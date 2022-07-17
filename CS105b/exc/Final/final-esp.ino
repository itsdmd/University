const int ARD_OUT = 12;				// Send read/write signal to Arduino
const int ARD_IN = 13;				// Receive read/write signal from Arduino

String g_nmsg = "220717144231006270500100111";		// Received from Node RED
String g_amsg = "";									// Received from Arduino
const int g_msglen = 9;								// Receive message length

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
}

void writeARD() {
	Serial.flush();
	
	g_nmsg = "<" + g_nmsg + ">";
	Serial.write(g_nmsg.c_str(), g_nmsg.length());
	
	g_nmsg = g_nmsg.substring(1, g_nmsg.length() - 1);
}

void loop() {
	// Default in writing mode.
	// When lost ARD_IN signal sent by Arduino, switch to reading mode.
	if (digitalRead(ARD_IN) == HIGH) {
		digitalWrite(ARD_OUT, LOW);
		
		do {
			writeARD();
			delay(100);
		} while (digitalRead(ARD_IN) == HIGH);
		
	} else {
		digitalWrite(ARD_OUT, HIGH);
		
		do {
			readARD();
			delay(100);
		} while (g_amsg.length() != g_msglen);
		
		digitalWrite(ARD_OUT, LOW);
	}
	
	delay(200);
}