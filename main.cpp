#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  PORTA_DIR |= (1<<PIN_PA3);      //Setup PIN_PA3 as OUTPUT
  pinMode(PIN_PA3, OUTPUT);
}

void loop() {
  PORTA_OUT |= (1<<PIN_PA3);
  digitalWrite(PIN_PA3,HIGH);
  delay(100);
  digitalWrite(PIN_PA3,LOW);
  PORTA_OUT &= ~(1<<PIN_PA3);
  delay(250);
  }
