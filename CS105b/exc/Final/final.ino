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
/* #endregion */

/// ------------------------------ Global Vars ----------------------------- ///
/* #region   */
bool g_statePIR = false;		// false = not detected, true = detected
bool g_statePWR = false;		// false = off, true = on

int g_moisture = 0;				// Moisture level read from sensor
int g_threshold = 0;			// Moisture threshold set by user
/* #endregion */


void setup() {
	Serial.begin(9600);

	LCD.begin(16, 2);

	pinMode(MOIST, INPUT);
	pinMode(PIR, INPUT);

	pinMode(REL_PWR, OUTPUT);
	pinMode(REL_LCD, OUTPUT);
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
	g_statePIR = digitalRead(PIR);
}

// Activate REL_PWR
void activateRelay() {
	if (!g_statePWR) {
		digitalWrite(REL_PWR, HIGH);
		g_statePWR = true;
	}
}

// Deactivate REL_PWR
void deactivateRelay() {
	if (g_statePWR) {
		digitalWrite(REL_PWR, LOW);
		g_statePWR = false;
	}
}
/* #endregion */


/// ------------------------------ Controllers ----------------------------- ///
/* #region   */
// Control REL_PWR based on MOIST
void wateringOnMoisture(const int threshold) {
	if (g_moisture < threshold) {
	activateRelay();
	} else {
	deactivateRelay();
	}
}

// Control REL_PWR based on weather forcast
void wateringOnWeather(const int threshold) {
	//TODO
}

void wateringController() {
	//TODO
}
// Turn LCD on/off based on PIR
void LCDOnPIR() {
	if (g_statePIR) {
		digitalWrite(REL_LCD, HIGH);
		
		LCD.setCursor(0, 0);
		LCD.print("Moisture: ");
		LCD.print(g_moisture);
		
		LCD.setCursor(0, 1);
		LCD.print("Status: ");
		LCD.setCursor(8, 1);
		(g_statePWR) ? LCD.print("Watering") : LCD.print("Idling");
	} else {
		digitalWrite(REL_LCD, LOW);
	}
}
/* #endregion */

void logging(){
	Serial.print("Moisture: ");
	Serial.print(g_moisture);
	Serial.print("\n");
	
	Serial.print("PIR: ");
	Serial.print(g_statePIR);
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