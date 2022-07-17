#include <LiquidCrystal.h>

/// ------------------------------------------------------------------------ ///
///                                   Setup                                  ///
/// ------------------------------------------------------------------------ ///

/// --------------------------------- Pins --------------------------------- ///
/* #region   */
LiquidCrystal LCD(7, 6, 5, 4, 3, 2);

const int MOIST = A0;
const int PIR = 8;

const int REL_PWR = 9;			// Relay controlling watering system
const int REL_LCD = 10;			// Turn on/off LCD

const int ESP_IN = 12;			// Receive read/write signal from ESP
const int ESP_OUT = 13; 		// Send read/write signal to ESP
/* #endregion */

/// ------------------------------ Global Vars ----------------------------- ///
/* #region   */
bool g_statePIR = false;		// PIR state
bool g_status = false;			// Watering relay state

int g_moisture = 0;				// Moisture level read from sensor
int g_threshold = 0;			// Moisture threshold set by user
String g_weather = "";			// Weather condition read from ESP

String g_imsg = "";				// Received from ESP
String g_omsg = "";				// To be sent to ESP
const int g_msglen = 27;		// Receive message length

bool g_reading = true;			// Reading mode by default

unsigned long long prevMillis = 0;		// Checkpoint for timer
/* #endregion */

bool timer(unsigned long start, unsigned long threshold) {
  return ((millis() - start) >= threshold);
}

void setup() {
	Serial.begin(9600);

	LCD.begin(16, 2);

	pinMode(MOIST, INPUT);
	pinMode(PIR, INPUT);

	pinMode(REL_PWR, OUTPUT);
	pinMode(REL_LCD, OUTPUT);

	pinMode(ESP_IN, INPUT);
	pinMode(ESP_OUT, OUTPUT);
	
	digitalWrite(REL_PWR, LOW);
	digitalWrite(REL_LCD, LOW);
	digitalWrite(ESP_OUT, LOW);
	
	prevMillis = millis();
}


/// ------------------------------------------------------------------------ ///
///                                 Functions                                ///
/// ------------------------------------------------------------------------ ///

/// --------------------------------- Base --------------------------------- ///
/* #region   */
// Read data from MOIST
void readMoist() {
	g_moisture = analogRead(MOIST);
}

// Read data from PIR
void readPir() {
	g_statePIR = analogRead(PIR);
}

// Activate REL_PWR
void waterOn() {
	if (!g_status) {
		digitalWrite(REL_PWR, HIGH);
		g_status = true;
	}
}

// Deactivate REL_PWR
void waterOff() {
	if (g_status) {
		digitalWrite(REL_PWR, LOW);
		g_status = false;
	}
}
/* #endregion */


/// ------------------------------ Controllers ----------------------------- ///
/* #region   */
// Control REL_PWR based on MOIST
void wateringController() {
	if (g_moisture < (g_threshold)) {
		if (g_weather[0] == '1'							// If it's gonna rain in the next hour
			|| g_weather.substring(3) == "011") {		// Or if it's not gonna rain the next hour but will be 2 hours from now
			
			waterOff();
		}
		
		else {
			waterOn();
		}
	}
}

// Turn LCD on/off based on PIR
void LCDOnPIR() {
	if (g_statePIR) {
		digitalWrite(REL_LCD, HIGH);
		
		LCD.setCursor(0, 0);
		LCD.print("Moist.:");
		LCD.print(g_moisture);
		LCD.setCursor(11, 0);
		LCD.print("/");
      	LCD.print(g_threshold);
		
		LCD.setCursor(0, 1);
		LCD.print("Status: ");
		LCD.setCursor(8, 1);
		(g_status) ? LCD.print("Watering") : LCD.print("Idling");
	} else {
		digitalWrite(REL_LCD, LOW);
	}
}
/* #endregion */

/// ---------------------------------- ESP --------------------------------- ///
/* #region   */
void readESP() {
	char c_imsg[g_msglen * 2];
	Serial.readBytes(c_imsg, g_msglen * 2);
	
	String s_imsg = c_imsg;
	
	if (s_imsg.indexOf('>') == -1) {
		Serial.readBytes(c_imsg, g_msglen);
		s_imsg += c_imsg;
	} else if (s_imsg.indexOf('<') == -1) {
		Serial.readBytes(c_imsg, g_msglen);
		s_imsg = c_imsg + s_imsg;
	}
	
	g_imsg = s_imsg.substring((s_imsg.indexOf('<') + 1), s_imsg.indexOf('>', s_imsg.indexOf('<')));
	
	Serial.print("Received: ");
	Serial.println(g_imsg);
}

void writeESP() {
	composeMessage();
	
	Serial.flush();
	
	g_omsg = "<" + g_omsg + ">";
	Serial.write(g_omsg.c_str(), g_omsg.length());
	
	g_omsg = g_omsg.substring(1, g_omsg.length() - 1);
}

// Prepare message to send to ESP
void composeMessage() {
	g_omsg = g_status;
	
	if (g_moisture < 1000) {
		g_omsg += "0";
		
		if (g_moisture < 100) {
			g_omsg += "0";
			
			if (g_moisture < 10) {
				g_omsg += "0";
			}
		}
	}
	g_omsg += g_moisture;
	
	if (g_threshold < 1000) {
		g_omsg += "0";
		
		if (g_threshold < 100) {
			g_omsg += "0";
			
			if (g_threshold < 10) {
				g_omsg += "0";
			}
		}
	}
	g_omsg += g_threshold;
}
/* #endregion */

void logging(){
	Serial.print("Moisture: ");
	Serial.print(g_moisture);
	Serial.print("\n");
	
	Serial.print("PIR: ");
	Serial.print(g_statePIR);
	Serial.print("\n");
	
	Serial.print("IMSG: ");
	Serial.print(g_imsg);
	Serial.print("\n");
	
	Serial.print("OMSG: ");
	Serial.print(g_omsg);
	Serial.print("\n");
	
	Serial.print("\n");
}



/// ------------------------------------------------------------------------ ///
///                                   Main                                   ///
/// ------------------------------------------------------------------------ ///
void loop() {
	readMoist();
	readPir();
	LCDOnPIR();
	
	switch (g_reading) {
		case true: {
			digitalWrite(ESP_OUT, HIGH);
			
			while (g_imsg.length() != g_msglen) {
				readESP();
			}

			Serial.print("Received: ");
			Serial.println(g_imsg);

			digitalWrite(ESP_OUT, LOW);
			
			g_reading = false;
			break;
		}
		
		case false: {
			digitalWrite(ESP_OUT, LOW);
			
			while (digitalRead(ESP_IN) == LOW) {
				Serial.println("Waiting for ESP to read...\n");
				delay(100);
			}
			
			while (digitalRead(ESP_IN) == HIGH) {
				digitalWrite(ESP_OUT, LOW);
				writeESP();
				
				delay(50);
			}
			
			Serial.print("\nSent: ");
			Serial.println(g_omsg);

			g_reading = true;
			
			digitalWrite(ESP_OUT, HIGH);
			break;
		}
	}
	
	delay(3000);
}