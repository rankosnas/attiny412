#include <Arduino.h>
/*
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/pgmspace.h>
*/
#ifdef F_CPU
#undef F_CPU
#define F_CPU 20000000UL
#endif

void setup() {
  // CCP = 0xD8;              // unlock before writing to the registers within 4 instructions
  // CCP = CCP_IOREG_gc;
  _PROTECTED_WRITE(CLKCTRL_MCLKCTRLA, 0x00);
                              // unlock before writing to the registers within 4 instructions
  //CLKCTRL_MCLKCTRLA = 0x00; // 16/20 MHz internal oscillator, witchout EXTCLK
  //CCP = 0xD8;
  _PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, 0x00);
                              // unlock before writing to the registers within 4 instructions
  //CLKCTRL_MCLKCTRLB = 0x00; // no prescaler main clock will pass through undivided
  
  PORTA_DIR |= PIN3_bm;       // Setup PIN_PA3 as OUTPUT bm BitMask 00000100
  Serial.swap(1);
  Serial.begin(115200);
  _PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, 0x00);
  Serial.println("Terminal activ");
}


void LED_blinks(uint32_t time_ms){
  for(uint8_t n=0;n<10;n++){
    PORTA_OUT |= PIN3_bm;     // Set PIN3 high
    delay(time_ms);
    PORTA_OUT &= ~PIN3_bm;    // Set PIN low
    delay(time_ms);
  }
}

void loop() {
  
  LED_blinks(250);
  delay(2000);
  Serial.print(F("FUSE_OSCCFG: \t\t"));
  Serial.print(FUSE_OSCCFG,HEX);
  Serial.print(F("\t"));
  Serial.println(FUSE_OSCCFG,BIN);
  Serial.print(F("CLKCTRL_MCLKCTRLA: \t"));
  Serial.print(CLKCTRL_MCLKCTRLA,HEX);
  Serial.print(F("\t"));
  Serial.println(CLKCTRL_MCLKCTRLA,BIN);
  Serial.print(F("CLKCTRL_MCLKCTRLB: \t"));
  Serial.print(CLKCTRL_MCLKCTRLB,HEX);
  Serial.print(F("\t"));
  Serial.println(CLKCTRL_MCLKCTRLB,BIN);
  
  }
