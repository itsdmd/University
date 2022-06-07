// Pin
const int B_OUT = 2;
const int B_IN = 4;

const int GRN = 7;
const int YLW = 8;
const int RED = 12;

const int SET_2 = 13;


int blinkState = 1;					// 1 = GRN, 2 = YLW, 3 = RED
unsigned long seqBlinkTimer = 0;	// Start time for sequential blink
void seqBlink() {
	if (blinkState == 1) {
		digitalWrite(GRN, HIGH);
		digitalWrite(YLW, LOW);
		digitalWrite(RED, LOW);
	}
	
	else if (blinkState == 2) {
		digitalWrite(GRN, LOW);
		digitalWrite(YLW, HIGH);
		digitalWrite(RED, LOW);
	}
	
	else if (blinkState == 3) {
		digitalWrite(GRN, LOW);
		digitalWrite(YLW, LOW);
		digitalWrite(RED, HIGH);
	}
	
	
	if (timer(seqBlinkTimer, 1000)) {
		blinkState++;
		if (blinkState > 3) {
			blinkState = 1;
		}
		
		seqBlinkTimer = millis();
	}
}

bool timer(unsigned long start, unsigned long threshold) {
	return ((millis() - start) >= threshold);
}



void setup() {
	pinMode(B_OUT, OUTPUT);
	pinMode(B_IN, INPUT);
	
	pinMode(GRN, OUTPUT);
	pinMode(YLW, OUTPUT);
	pinMode(RED, OUTPUT);
	pinMode(SET_2, OUTPUT);
}

bool timerStarted = false;			// Timer's state
unsigned long longPressTimer = 0;	// Start time for long press
void loop() {
	digitalWrite(B_OUT, HIGH);
	
	// Button pressed
	if (digitalRead(B_IN) == HIGH) {
		// If timer not started yet
		if (timerStarted == false) {
			timerStarted = true;
			
			longPressTimer = millis();
			seqBlinkTimer = millis();
		}
		
		// If timer is already started
		else {
			// If the button had been pressed for more than 10 seconds
			if (timer(longPressTimer, 10000)) {
				// State 2: All up
				digitalWrite(GRN, HIGH);
				digitalWrite(YLW, HIGH);
				digitalWrite(RED, HIGH);
				digitalWrite(SET_2, HIGH);
			} else {
				// State 1: SET_2 up, sequential blink
				digitalWrite(SET_2, HIGH);
				seqBlink();
			}
		}
	}
	
	// Button released/not pressed
	else {
		// Reset timer's state
		timerStarted = false;
		
		// State 3: SET_2 down, SET_1 up
		digitalWrite(GRN, HIGH);
		digitalWrite(YLW, HIGH);
		digitalWrite(RED, HIGH);
		digitalWrite(SET_2, LOW);
	}
}