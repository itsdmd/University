const int OUT = 8;
const int SEPO = 9;
const int WRITE = 10;
const int IN = 11;
const int SEPI = 12;
const int READ = 13;

String g_imsg = "006270500";
String g_omsg = "";
const int g_msglen = 3;

bool g_write = true;

void setup() {
	Serial.begin(9600);
  	
	pinMode(IN, INPUT);
	pinMode(SEPI, INPUT);
	pinMode(READ, INPUT);
	
	pinMode(OUT, OUTPUT);
	pinMode(SEPO, OUTPUT);
	pinMode(WRITE, OUTPUT);
	
	g_write = true;
}

// Write binary data to Arduino
void write() {
	Serial.println("[E] Start writing");
	
	while (((digitalRead(IN) == HIGH) && (digitalRead(SEPI) == HIGH)) == false) {
		Serial.println("[E] Waiting first");
			
		digitalWrite(OUT, HIGH);
		digitalWrite(SEPO, HIGH);
		digitalWrite(WRITE, HIGH);
	}
	
	bool state = true;		// true: OUT=1, SEPO=0 ; false: OUT=0, SEPO=1
	int counter = 0;
	while (counter < (g_msglen * 4)) {
		digitalWrite(OUT, LOW);
		digitalWrite(SEPO, LOW);
		
		if (g_omsg[counter] == '1') {
			digitalWrite(WRITE, HIGH);
		} else {
			digitalWrite(WRITE, LOW);
		}
		
		switch (state) {
			case true:
				digitalWrite(OUT, HIGH);
				digitalWrite(SEPO, LOW);
				state = !state;
				break;
			
			case false:
				digitalWrite(OUT, LOW);
				digitalWrite(SEPO, HIGH);
				state = !state;
				break;
			
			default:
				break;
		}
		
		Serial.print("[E] Writing, ");
		Serial.println(g_omsg[counter]);
		
		while (digitalRead(SEPI) != HIGH) {
			Serial.println("[E] Waiting for reading");
		}
		
		digitalWrite(OUT, HIGH);
		digitalWrite(SEPO, HIGH);
		digitalWrite(WRITE, LOW);
		while (((digitalRead(IN) == LOW) && (digitalRead(SEPI) == LOW) && (digitalRead(READ) == LOW)) == false) {
			if (counter == (g_msglen * 4 - 1)) {
				break;
			}
			
			Serial.println("[E] Waiting next");
		}
		
		counter++;
	}
	
	g_write = false;
	Serial.println("[E] Finished writing");
}

void read() {
	g_imsg = "";
	
	bool finished = false;
	
	while (!finished) {
		digitalWrite(OUT, LOW);
		digitalWrite(SEPO, LOW);
		digitalWrite(WRITE, LOW);
		
		// When detect start signal
		if ((digitalRead(IN) > 50) && (digitalRead(SEPI) > 50) && (digitalRead(READ) > 50)) {
			while (((digitalRead(IN) > 50) && (digitalRead(SEPI) < 50)) == false) {
				Serial.println("[E] Waiting first");
				
				digitalWrite(OUT, HIGH);
				digitalWrite(SEPO, HIGH);
				digitalWrite(WRITE, LOW);
			}
			digitalWrite(OUT, LOW);
			digitalWrite(SEPO, LOW);
			
			bool state = true;		// true: OUT=1, SEPO=0 ; false: OUT=0, SEPO=1
			while (g_imsg.length() < (g_msglen * 4)) {
				digitalWrite(SEPO, LOW);
				
				bool canRead = false;
				
				switch (state) {
					case true:
						if ((digitalRead(IN) > 50) && (digitalRead(SEPI) < 50)) {
							canRead = true;
							state = !state;
						}
						break;
					
					case false:
						if ((digitalRead(IN) < 50) && (digitalRead(SEPI) > 50)) {
							canRead = true;
							state = !state;
						}
						break;
					
					default:
						break;
				}
				
				if (canRead) {
					if (digitalRead(READ) > 50) {
						g_imsg += '1';
					} else {
						g_imsg += '0';
					}

					Serial.print("[E] Reading, ");
					Serial.print(digitalRead(READ));
					Serial.print(", ");
					Serial.println(g_imsg);
					
					while (((digitalRead(IN) > 50) && (digitalRead(SEPI) > 50)) == false) {
						Serial.print("[E] Waiting respond, ");
						Serial.print(digitalRead(IN));
						Serial.print(", ");
						Serial.print(digitalRead(SEPI));
						Serial.print(", ");
						Serial.println(digitalRead(READ));
						
						digitalWrite(SEPO, HIGH);
					}
				} else {
					digitalWrite(SEPO, HIGH);
				}
			}
			
			Serial.println("[E] Finished reading");
			finished = true;
		}
	}
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

void loop() {
	if (g_write) {
		g_omsg = toBinary(g_imsg);
		Serial.println(g_omsg);
		
		write();
		
		digitalWrite(OUT, LOW);
		digitalWrite(SEPO, LOW);
		digitalWrite(WRITE, LOW);
	} else {
		delay(1500);
		
		Serial.print("\n\n\n\n\n");
		read();
		
		g_imsg = toDecimal(g_imsg);
		Serial.println(g_imsg);
		
		delay(1000);
		Serial.print("\n\n\n\n\n");
	}
}