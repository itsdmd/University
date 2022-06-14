/// ------------------------------------------------------------------------ ///
///                                   Pins                                   ///
/// ------------------------------------------------------------------------ ///
int buzz = 2;
int trig = 4;
int echo = 5;

int GRN = 7;
int YLW = 8;
int RED = 12;


void setup() {
  pinMode(buzz, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(RED, OUTPUT);
  pinMode(GRN, OUTPUT);
  pinMode(YLW, OUTPUT);
}

/// ------------------------------------------------------------------------ ///
///                                 Functions                                ///
/// ------------------------------------------------------------------------ ///
long getDistCM() {
  digitalWrite(trig, LOW);
  
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  
  return ((pulseIn(echo, HIGH) * 0.034) / 2);
}

void blink(int interval, int pin) {
  digitalWrite(pin, HIGH);
  tone(buzz, 1000);
  delay(interval);
  
  digitalWrite(pin, LOW);
  noTone(buzz);
  delay(interval);
}

void stateSwitcher(const int thres1, const int thres2) {
  if (getDistCM() >= thres2) {
    digitalWrite(GRN, HIGH);
    digitalWrite(YLW, LOW);
    digitalWrite(RED, LOW);
  }
  
  else if ((getDistCM() > thres1) && (getDistCM() < thres2)) {
    digitalWrite(GRN, LOW);
    digitalWrite(YLW, LOW);
    digitalWrite(RED, LOW);
    
    blink(1000, YLW);
  }
  
  else {
    digitalWrite(GRN, LOW);
    digitalWrite(YLW, LOW);
    digitalWrite(RED, LOW);
    
    blink((getDistCM() * 20), RED);
    
  }
}



/// ------------------------------------------------------------------------ ///
///                                   Main                                   ///
/// ------------------------------------------------------------------------ ///
void loop() {
  stateSwitcher(50, 150);
}