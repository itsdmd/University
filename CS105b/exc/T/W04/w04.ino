/// ------------------------------------------------------------------------ ///
///                                   Pins                                   ///
/// ------------------------------------------------------------------------ ///
int trig = 4;
int echo = 5;

int RED = 12;
int YLW = 8;
int GRN = 7;


void setup() {
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
  delay(interval);
  
  digitalWrite(pin, LOW);
  delay(interval);
}

void stateSwitcher() {
  if (getDistCM() > 100) {
    digitalWrite(GRN, HIGH);
    digitalWrite(YLW, LOW);
    digitalWrite(RED, LOW);
  }
  
  else if ((getDistCM() > 50) && (getDistCM() <= 100)) {
    digitalWrite(GRN, LOW);
    digitalWrite(YLW, HIGH);
    digitalWrite(RED, LOW);
  }
  
  else {
    digitalWrite(GRN, LOW);
    digitalWrite(YLW, LOW);
    digitalWrite(RED, HIGH);
    
    blink(1000, RED);
  }
}



/// ------------------------------------------------------------------------ ///
///                                   Main                                   ///
/// ------------------------------------------------------------------------ ///
void loop() {
  stateSwitcher();
}