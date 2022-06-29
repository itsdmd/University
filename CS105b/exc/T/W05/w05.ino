/// ------------------------------------------------------------------------ ///
///                                   Pins                                   ///
/// ------------------------------------------------------------------------ ///
int PHT = A0;
int LED = 2;


void setup() {
  Serial.begin(9600);
  
  pinMode(PHT, INPUT);
  
  pinMode(LED, OUTPUT);
}



/// ------------------------------------------------------------------------ ///
///                                   Main                                   ///
/// ------------------------------------------------------------------------ ///
void loop() {
  bool day;
  (analogRead(PHT) >= 500) ? day = true : day = false;
  
  if (day) {
    digitalWrite(LED, LOW);
    return;
  }
  
  digitalWrite(LED, HIGH);
}