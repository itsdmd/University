#include <LiquidCrystal.h>

// Pins
const int TMP = A0;
const int B_IN = 7;
const int B_OUT = 8;

LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  
  LCD.begin(16, 2);
  
  pinMode(B_OUT, OUTPUT);
  
  pinMode(TMP, INPUT);
  pinMode(B_IN, INPUT);
}

int mode = 0;
void LcdMode() {
  switch (mode) {
    case 0: {
      LCD.setCursor(5, 0);
      LCD.print("CLASS");
      
      LCD.setCursor(6, 1);
      LCD.print("105b");

      break;
    }
    
    case 1: {
      LCD.setCursor(0, 0);
      LCD.print("                ");
      LCD.setCursor(0, 1);
      LCD.print("                ");
      LCD.setCursor(2, 0);
      LCD.print("DAO MINH DUC");
      
      LCD.setCursor(4, 1);
      LCD.print("2159003");
      
      delay(500);
      LCD.noDisplay();
      delay(500);
      LCD.display();
      
      break;
    }
    
    case 2: {
      LCD.setCursor(2, 0);
      LCD.print("TEMP: ");
      
      float raw_tmp = analogRead(TMP);
      float tmp = (((raw_tmp * 5) / 1023) / 0.01) - 50;
      LCD.setCursor(8, 0);
      LCD.print(tmp);
      
      break;
    }
  }
}

void loop() {
  digitalWrite(B_OUT, HIGH);
  
  LcdMode();
  
  if (digitalRead(B_IN) == HIGH) {
    while (digitalRead(B_IN) == HIGH) {
      Serial.println("Holding");
    }
    
    LCD.setCursor(0, 0);
    LCD.print("                ");
    LCD.setCursor(0, 1);
    LCD.print("                ");
    
    if (mode < 2) {
      mode++;
    } else {
      mode = 0;
    }
  }
}