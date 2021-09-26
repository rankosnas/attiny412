//https://ww1.microchip.com/downloads/en/Appnotes/Getting-Started-with-GPIO-DS90003229B.pdf

#define F_CPU 3333333     // Defaut CPU frequency

#include <Arduino.h>
#include <avr/io.h>
#include <avr/delay.h>


void setup() {
  // put your setup code here, to run once:
  PORTA_DIR |= PIN3_bm;      //Setup PIN_PA3 as OUTPUT bm BitMask 00000100
}

void loop() {
  PORTA_OUT |= PIN3_bm;     // Set PIN3 high
  _delay_ms(150);
  PORTA_OUT &= ~PIN3_bm;    // Set PIN low
  _delay_ms(250);
  }
