#include <WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqttServer = "broker.hivemq.com";
int port = 1883;
String stMac;
char mac[50];
char clientId[50];

WiFiClient espClient;
PubSubClient client(espClient);


LiquidCrystal_I2C LCD(0x27, 16, 2);

const int MOIST = 14;
const int PIR = 12;
const int REL_PWR = 2;			    	// Relay controlling watering system

bool g_statePIR = false;		    	// PIR state
bool g_status = false;			     	// Watering relay state
int g_m_status = 0;				       	// Watering status set by user. 0: auto-off, 1: auto-on, 2: manual-off, 3: manual-on

int g_moisture = 0;				     	// Moisture level read from sensor
int g_threshold = 0;			    	// Moisture threshold set by user
String g_weather = "";			      	// Weather condition read from Node-RED

String g_imsg = "";				        // Received from Node-RED
String g_omsg = "";						// To be sent to Node-RED
const int g_msglen = 27;	            // Receive message length

unsigned long long prevMillis = 0;		// Checkpoint for timer

bool timer(unsigned long start, unsigned long threshold) {
  return ((millis() - start) >= threshold);
}


void setup() {
	Serial.begin(115200);
	
	// Components
	LCD.init();
	LCD.noBacklight();

	pinMode(MOIST, INPUT);
	pinMode(PIR, INPUT);

	pinMode(REL_PWR, OUTPUT);
	digitalWrite(REL_PWR, LOW);

	prevMillis = millis();

	// Network
	randomSeed(analogRead(0));
	delay(10);
	Serial.println();
	Serial.print("Connecting to ");
	Serial.println(ssid);

	wifiConnect();

	Serial.println("");
	Serial.println("WiFi connected");
	Serial.println("IP address: ");
	Serial.println(WiFi.localIP());
	Serial.println(WiFi.macAddress());
	stMac = WiFi.macAddress();
	stMac.replace(":", "_");
	Serial.println(stMac);

	client.setServer(mqttServer, port);
	client.setCallback(callback);
}


/// --------------------------------- Base --------------------------------- ///
/* #region   */
// Read data from MOIST
void readMoist() {
	// g_moisture = analogRead(MOIST);
	g_moisture = random(1000);
	Serial.print("Moisture: ");
	Serial.println(g_moisture);
}

// Read data from PIR
void readPIR() {
	g_statePIR = digitalRead(PIR);
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

// Prepare message to send to ESP
void composeMessage() {
	g_omsg = "";
	
	g_omsg += g_m_status;
	
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

void decomposeMessage() {
	g_m_status = g_imsg.substring(12, (12 + 1)).toInt();
	g_threshold = g_imsg.substring(17, (17 + 4)).toInt();
	g_weather = g_imsg.substring(21);
}
/* #endregion */


/// ------------------------------ Controllers ----------------------------- ///
/* #region   */
// Control REL_PWR based on MOIST
void wateringController() {
	if (g_m_status == 2) {
		waterOff();
		return;
	} else if (g_m_status == 3) {
		waterOn();
		return;
	}
	
	else if (g_moisture < g_threshold) {
		if (((g_weather[0] == '1')							// If it's gonna rain in the next hour
				&& (g_moisture > g_threshold - 100))		// and the soil is not too dry
			|| ((g_weather.substring(0, 2) == "01")			// Or if it's not gonna rain the next hour but will be 2 hours from now
				&& (g_moisture > (g_threshold - 50)))) {	// ... and the soil is not too dry
			
			waterOff();
			g_m_status = 0;
		}
		
		else {
			waterOn();
			g_m_status = 1;
		}
	} else {
		waterOff();
		g_m_status = 0;
	}
}

// Turn LCD on/off based on PIR
void LCDOnPIR() {
	if (g_statePIR) {
		LCD.backlight();
		LCD.clear();
		
		LCD.setCursor(0, 0);
		LCD.print("Moist.:");
		LCD.print(g_moisture);
		LCD.setCursor(11, 0);
		LCD.print("/");
      	LCD.print(g_threshold);
		
		LCD.setCursor(0, 1);
		LCD.print("Status: ");
		LCD.setCursor(8, 1);
		(g_status) ? LCD.print("Water") : LCD.print("Idle");
		LCD.setCursor(13, 1);
		((g_m_status == 0) || (g_m_status == 1)) ? LCD.print("(A)") : LCD.print("(M)");
	}
	
	else {
		LCD.clear();
		LCD.noBacklight();
	}
}
/* #endregion */


/// ------------------------------ Networking ----------------------------- ///
/* #region   */
void wifiConnect() {
	WiFi.mode(WIFI_STA);
	WiFi.begin(ssid, password);
	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}
}

void mqttReconnect() {
	while (!client.connected()) {
		Serial.println("Attempting MQTT connection...");
		long r = random(1000);
		sprintf(clientId, "clientId-%ld", r);
		if (client.connect(clientId)) {
			Serial.print(clientId);
			Serial.println(" connected");
			client.subscribe("030927-cb");
		} else {
			Serial.print("failed, rc=");
			Serial.print(client.state());
			Serial.println(" try again in 5 seconds");
			delay(5000);
		}
	}
}

void callback(char* topic, byte* message, unsigned int length) {
	Serial.print("Message arrived on topic: ");
	Serial.print(topic);
	Serial.print(". Message: ");
	String stMessage;
	
	for (int i = 0; i < length; i++) {
		stMessage += (char)message[i];
	}

	g_imsg = stMessage;
	Serial.println(g_imsg);
}

void publish(String toSend) {
	char postMsg[9];
	toSend.toCharArray(postMsg, 9);

	client.publish("030927", postMsg);
	Serial.print("Sent: ");
	Serial.println(toSend);
}
/* #endregion */


/// ------------------------------ Main ----------------------------- ///
void loop() {
	if (!client.connected()) {
		mqttReconnect();
	}

	client.loop();
	decomposeMessage();
	
	readPIR();
	LCDOnPIR();
	wateringController();
	
	// Publish message every 3 seconds
	if(timer(prevMillis, 3000)) {
		readMoist();
		composeMessage();
		publish(g_omsg);

		prevMillis = millis();
	}

	delay(500);
}