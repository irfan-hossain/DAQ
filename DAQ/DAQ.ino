///////////////////////////////////////////////////////////////////////////////
//`File: DAQ.ino
// Desc: Main loop for arduino code to run.
//
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "utils/configReg.h"
#include "utils/ISR.h"
#include "utils/oledDisplay.h"

volatile uint8_t data_byte = 0;
volatile bool flag = false;

void setup()
{
  /////////////////////////////////////////
  /// Disable Interrupts.
  cli();

  /////////////////////////////////////////
  /// Configure Registers for ADC
  configADMUX();
  configADCSRA();
  configADCSRB();

  /////////////////////////////////////////
  /// Configure Registers for Timer1
  configTCCR1A();
  configTCCR1B();
  configICR1();

  /////////////////////////////////////////
  /// Enable Interrupts for Timer1 and ADC.
  enableInterrupts();

  /////////////////////////////////////////
  /// Enable Interrupts
  sei();

  /////////////////////////////////////////
  /// Setup OLED display.
  setupOLED(1);
  resetOLED(0, 0);

  /////////////////////////////////////////
  /// Setup Serial Communication
  Serial.begin(250000);
}


void loop()
{

  /////////////////////////////////////////
  ///
  if (flag == true)
  {
    displayData(data_byte, 0, 0);
    flag = false;
  }

  display.drawPixel(64, 16,WHITE);
  display.display();

  /////////////////////////////////////////
  ///
  


}
