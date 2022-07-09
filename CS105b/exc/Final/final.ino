#include <LiquidCrystal.h>

/// ------------------------------------------------------------------------ ///
///                                   Setup                                  ///
/// ------------------------------------------------------------------------ ///

/// --------------------------------- Pins --------------------------------- ///
/* #region   */
LiquidCrystal LCD(7, 6, 5, 4, 3, 2);

const int MOIST = A0;
const int PIR = 8;
const int RELAY = 9;
const int LCD_LED = 13;			// Turn on/off LCD
/* #endregion */

/// ------------------------------ Global Vars ----------------------------- ///
/* #region   */
bool g_pirState = false;		// false = not detected, true = detected
bool g_relayState = false;		// false = off, true = on

int g_moisture = 0;				// Moisture level read from sensor
int g_threshold = 0;			// Moisture threshold set by user
/* #endregion */


void setup() {
	Serial.begin(9600);

	LCD.begin(16, 2);

	pinMode(MOIST, INPUT);
	pinMode(PIR, INPUT);

	pinMode(RELAY, OUTPUT);
	pinMode(LCD_LED, OUTPUT);
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
	g_pirState = digitalRead(PIR);
}

// Activate RELAY
void activateRelay() {
	if (!g_relayState) {
		digitalWrite(RELAY, HIGH);
		g_relayState = true;
	}
}

// Deactivate RELAY
void deactivateRelay() {
	if (g_relayState) {
		digitalWrite(RELAY, LOW);
		g_relayState = false;
	}
}
/* #endregion */


/// ------------------------------ Controllers ----------------------------- ///
/* #region   */
// Control RELAY based on MOIST
void wateringOnMoisture(const int threshold) {
	if (g_moisture < threshold) {
	activateRelay();
	} else {
	deactivateRelay();
	}
}

// Control RELAY based on weather forcast
void wateringOnWeather(const int threshold) {
	//TODO
}

void wateringController() {
	//TODO
}
// Turn LCD on/off based on PIR
void LCDOnPIR() {
	if (g_pirState) {
		digitalWrite(LCD_LED, HIGH);
	} else {
		digitalWrite(LCD_LED, LOW);
	}
}
/* #endregion */

void logging(){
	Serial.print("Moisture: ");
	Serial.print(g_moisture);
	Serial.print("\n");
	
	Serial.print("PIR: ");
	Serial.print(g_pirState);
	Serial.print("\n");
}

/// ------------------------------------------------------------------------ ///
///                                   Main                                   ///
/// ------------------------------------------------------------------------ ///
void loop() {
	readMoist();
	readPir();
	LCDOnPIR();
	
	logging();
}