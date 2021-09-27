#include <Arduino.h>
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/pgmspace.h>


void setup() {
  // put your setup code here, to run once:
  CCP = 0xD8;                 // unlock before writing to the registers within 4 instructions
  CCP = CCP_IOREG_gc;
  CLKCTRL_MCLKCTRLA = 0x00;   // 16/20 MHz internal oscillator
  CCP = 0xD8;                 // unlock before writing to the registers within 4 instructions
  CLKCTRL_MCLKCTRLB = 0x00;   // no prescaler main clock will pass through undivided
  
  PORTA_DIR |= PIN3_bm;       // Setup PIN_PA3 as OUTPUT bm BitMask 00000100
  Serial.swap(1);
  Serial.begin(115200);
  
  Serial.println("Terminal activ");
}


void LED_blinks(uint32_t time_ms){
  for(uint8_t n=0;n<10;n++){
    PORTA_OUT |= PIN3_bm;     // Set PIN3 high
    _delay_ms(time_ms);
    PORTA_OUT &= ~PIN3_bm;    // Set PIN low
    _delay_ms(time_ms);
  }
}

void loop() {
  
  LED_blinks(250);
  _delay_ms(2000);
  Serial.print(F("FUSE_OSCCFG: \t\t"));
  Serial.print(FUSE_OSCCFG,HEX);
  Serial.print(F("\t"));
  Serial.println(FUSE_OSCCFG,BIN);
  Serial.print(F("CLKCTRL_MCLKCTRLB: \t"));
  Serial.print(CLKCTRL_MCLKCTRLB,HEX);
  Serial.print(F("\t"));
  Serial.println(CLKCTRL_MCLKCTRLB,BIN);
  
  }
