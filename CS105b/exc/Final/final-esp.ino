const int ARD_OUT = 12;				// Send read/write signal to Arduino
const int ARD_IN = 13;				// Receive read/write signal from Arduino

String g_nmsg = "220717112505006270050000000";		// Received from Node RED
String g_amsg = "";									// Received from Arduino
const int g_msglen = 9;								// Receive message length

bool g_reading = false;				// Writing mode by default

void setup() {
	Serial.begin(9600);
  	
	pinMode(ARD_IN, INPUT);
	
	pinMode(ARD_OUT, OUTPUT);
	digitalWrite(ARD_OUT, LOW);
}

void readARD() {
	char c_amsg[g_msglen * 2];
	Serial.readBytes(c_amsg, g_msglen * 2);
	
	String s_amsg = c_amsg;
	
	if (s_amsg.indexOf('>') == -1) {
		Serial.readBytes(c_amsg, g_msglen);
		s_amsg += c_amsg;
	} else if (s_amsg.indexOf('<') == -1) {
		Serial.readBytes(c_amsg, g_msglen);
		s_amsg = c_amsg + s_amsg;
	}
	
	g_amsg = s_amsg.substring((s_amsg.indexOf('<') + 1), s_amsg.indexOf('>', s_amsg.indexOf('<')));
	
	Serial.print("Received: ");
	Serial.println(g_amsg);
}

void writeARD() {
	Serial.flush();
	
	g_nmsg = "<" + g_nmsg + ">";
	Serial.write(g_nmsg.c_str(), g_nmsg.length());
	
	g_nmsg = g_nmsg.substring(1, g_nmsg.length() - 1);
}

void loop() {
	switch (g_reading) {
		case true: {
			digitalWrite(ARD_OUT, HIGH);
			
			while (g_amsg.length() != g_msglen) {
				readARD();
			}

			Serial.print("Received: ");
			Serial.println(g_amsg);
			
			digitalWrite(ARD_OUT, LOW);
			
			g_reading = false;
			break;
		}
		
		case false: {
			digitalWrite(ARD_OUT, LOW);
			
			while (digitalRead(ARD_IN) == LOW) {
				Serial.println("Waiting for Arduino to read...\n");
				delay(100);
			}
			
			while (digitalRead(ARD_IN) == HIGH) {
				digitalWrite(ARD_OUT, LOW);
				writeARD();
				
				delay(50);
			}
			
			Serial.print("\nSent: ");
			Serial.println(g_nmsg);

			g_reading = true;

			digitalWrite(ARD_OUT, HIGH);
			break;
		}
	}
	
	delay(3000);
}