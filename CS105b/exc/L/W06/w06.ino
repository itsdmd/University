/// ------------------------------------------------------------------------ ///
///                                   Pins                                   ///
/// ------------------------------------------------------------------------ ///
const int PHT = A0;
const int POT = A1;

const int PIR = 2;
const int LED = 7;
const int BUZ = 8;

void setup() {
	Serial.begin(9600);

	pinMode(PHT, INPUT);
	pinMode(POT, INPUT);

	pinMode(PIR, INPUT);
	pinMode(LED, OUTPUT);
	pinMode(BUZ, OUTPUT);
}

void blink(const bool condition, const int interval, const int pin) {
	if (condition) {
		digitalWrite(pin, HIGH);
	}
	tone(BUZ, 1000);
	delay(interval);

	if (condition) {
		digitalWrite(pin, LOW);
	}
	noTone(BUZ);
	delay(interval);
}

/// ------------------------------------------------------------------------ ///
///                                   Main                                   ///
/// ------------------------------------------------------------------------ ///
void loop() {
	const int THRESHOLD = analogRead(POT);
	
	Serial.print("THRESHOLD: ");
	Serial.println(THRESHOLD);

	if (digitalRead(PIR) == HIGH) {
		blink((analogRead(PHT) < THRESHOLD), 1000, LED);
	}
}