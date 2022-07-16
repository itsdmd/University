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

const int ESP_IN = A1;			// Start reading ESP sequence
const int ESP_SEPI = A2;		// Separate between characters
const int ESP_READ = A3;		// Binary signal
const int ESP_OUT = 11; 		// Start writing ESP sequence
const int ESP_SEPO = 12; 		// Separate between characters
const int ESP_WRITE = 13; 		// Binary signal
/* #endregion */

/// ------------------------------ Global Vars ----------------------------- ///
/* #region   */
bool g_statePIR = false;		// PIR state
bool g_status = false;			// Watering relay state

int g_moisture = 0;				// Moisture level read from sensor
int g_threshold = 0;			// Moisture threshold set by user
String g_weather = "";			// Weather condition read from ESP

String g_imsg = "";				// Incoming message from ESP (completed)
String g_omsg = "";				// Outgoing message to ESP
const int g_msglen = 3;			// Message length
bool g_write = false;				// Reading mode

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

	pinMode(ESP_IN, INPUT);
	pinMode(ESP_SEPI, INPUT);
	pinMode(ESP_READ, INPUT);
	
	
	pinMode(REL_PWR, OUTPUT);
	pinMode(REL_LCD, OUTPUT);
	
	pinMode(ESP_OUT, OUTPUT);
	pinMode(ESP_SEPO, OUTPUT);
	pinMode(ESP_WRITE, OUTPUT);
	
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
// Read binary data from ESP
void readESP() {
	g_imsg = "";
	
	bool finished = false;
	
	while (!finished) {
		digitalWrite(ESP_OUT, LOW);
		digitalWrite(ESP_SEPO, LOW);
		digitalWrite(ESP_WRITE, LOW);
		
		// When detect start signal
		if ((analogRead(ESP_IN) > 50) && (analogRead(ESP_SEPI) > 50) && (analogRead(ESP_READ) > 50)) {
			while (((analogRead(ESP_IN) > 50) && (analogRead(ESP_SEPI) < 50)) == false) {
				Serial.println("[A] Waiting first");
				
				digitalWrite(ESP_OUT, HIGH);
				digitalWrite(ESP_SEPO, HIGH);
				digitalWrite(ESP_WRITE, LOW);
			}
			digitalWrite(ESP_OUT, LOW);
			digitalWrite(ESP_SEPO, LOW);
			
			bool state = true;		// true: OUT=1, SEPO=0 ; false: OUT=0, SEPO=1
			while (g_imsg.length() < (g_msglen * 4)) {
				digitalWrite(ESP_SEPO, LOW);
				
				bool canRead = false;
				
				switch (state) {
					case true:
						if ((analogRead(ESP_IN) > 50) && (analogRead(ESP_SEPI) < 50)) {
							canRead = true;
							state = !state;
						}
						break;
					
					case false:
						if ((analogRead(ESP_IN) < 50) && (analogRead(ESP_SEPI) > 50)) {
							canRead = true;
							state = !state;
						}
						break;
					
					default:
						break;
				}
				
				if (canRead) {
					if (analogRead(ESP_READ) > 50) {
						g_imsg += '1';
					} else {
						g_imsg += '0';
					}

					Serial.print("[A] Reading, ");
					Serial.print(analogRead(ESP_READ));
					Serial.print(", ");
					Serial.println(g_imsg);
					
					while (((analogRead(ESP_IN) > 50) && (analogRead(ESP_SEPI) > 50)) == false) {
						Serial.print("[A] Waiting respond, ");
						Serial.print(analogRead(ESP_IN));
						Serial.print(", ");
						Serial.print(analogRead(ESP_SEPI));
						Serial.print(", ");
						Serial.println(analogRead(ESP_READ));
						
						digitalWrite(ESP_SEPO, HIGH);
					}
				} else {
					digitalWrite(ESP_SEPO, HIGH);
				}
			}
			
			Serial.println("[A] Finished reading");
			finished = true;
		}
	}
}

// Write binary data to ESP
void writeESP() {
	Serial.println("[A] Start writing");
	
	while (((analogRead(ESP_IN) > 50) && (analogRead(ESP_SEPI) > 50)) == false) {
		Serial.println("[A] Waiting first");
			
		digitalWrite(ESP_OUT, HIGH);
		digitalWrite(ESP_SEPO, HIGH);
		digitalWrite(ESP_WRITE, HIGH);
	}
	
	bool state = true;		// true: OUT=1, SEPO=0 ; false: OUT=0, SEPO=1
	int counter = 0;
	while (counter < g_omsg.length()) {
		digitalWrite(ESP_OUT, LOW);
		digitalWrite(ESP_SEPO, LOW);
		
		if (g_omsg[counter] == '1') {
			digitalWrite(ESP_WRITE, HIGH);
		} else {
			digitalWrite(ESP_WRITE, LOW);
		}
		
		switch (state) {
			case true:
				digitalWrite(ESP_OUT, HIGH);
				digitalWrite(ESP_SEPO, LOW);
				state = !state;
				break;
			
			case false:
				digitalWrite(ESP_OUT, LOW);
				digitalWrite(ESP_SEPO, HIGH);
				state = !state;
				break;
			
			default:
				break;
		}
		
		Serial.print("[A] Writing, ");
		Serial.println(g_omsg[counter]);
		
		while (analogRead(ESP_SEPI) != HIGH) {
			Serial.println("[A] Waiting for reading");
		}
		
		digitalWrite(ESP_OUT, HIGH);
		digitalWrite(ESP_SEPO, HIGH);
		digitalWrite(ESP_WRITE, LOW);
		while (((analogRead(ESP_IN) < 50) && (analogRead(ESP_SEPI) < 50) && (analogRead(ESP_READ) < 50)) == false) {
			if (counter == g_omsg.length() - 1) {
				break;
			}
			
			Serial.println("[A] Waiting next");
		}
		
		counter++;
	}
	
	g_write = false;
	Serial.println("[A] Finished writing");
}

// Convert a string of decimal number characters to a binary string
String toBinary(String msg) {
	String binary = "";
	
	for (int i = 0; i < msg.length(); i++) {
		switch (msg[i]) {
			case '0':
				binary += "0000";
				break;
			case '1':
				binary += "0001";
				break;
			case '2':
				binary += "0010";
				break;
			case '3':
				binary += "0011";
				break;
			case '4':
				binary += "0100";
				break;
			case '5':
				binary += "0101";
				break;
			case '6':
				binary += "0110";
				break;
			case '7':
				binary += "0111";
				break;
			case '8':
				binary += "1000";
				break;
			case '9':
				binary += "1001";
				break;
		}
	}
	
	return binary;
}

// Convert binary string to a string of decimal number characters
String toDecimal(String msg) {
	String decimal = "";
	
	for (int i = 0; i < msg.length(); i += 4) {
		if (msg.substring(i, i + 4) == "0000") {
			decimal += "0";
		} else if (msg.substring(i, i + 4) == "0001") {
			decimal += "1";
		} else if (msg.substring(i, i + 4) == "0010") {
			decimal += "2";
		} else if (msg.substring(i, i + 4) == "0011") {
			decimal += "3";
		} else if (msg.substring(i, i + 4) == "0100") {
			decimal += "4";
		} else if (msg.substring(i, i + 4) == "0101") {
			decimal += "5";
		} else if (msg.substring(i, i + 4) == "0110") {
			decimal += "6";
		} else if (msg.substring(i, i + 4) == "0111") {
			decimal += "7";
		} else if (msg.substring(i, i + 4) == "1000") {
			decimal += "8";
		} else if (msg.substring(i, i + 4) == "1001") {
			decimal += "9";
		}
	}
	
	return decimal;
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
  	
	if (!g_write) {
		readESP();
		
		g_imsg = toDecimal(g_omsg);
		Serial.println(g_imsg);
		
		digitalWrite(ESP_OUT, LOW);
		digitalWrite(ESP_SEPO, LOW);
		digitalWrite(ESP_WRITE, LOW);
		
		g_write = true;
	} else {
		delay(1000);
		Serial.print("\n\n\n\n\n");
		
		composeMessage();
		g_omsg = toBinary(g_omsg);

		logging();
		
		writeESP();
		
		delay(1500);
		Serial.print("\n\n\n\n\n");
	}
}