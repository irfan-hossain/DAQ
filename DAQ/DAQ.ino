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

#define BAUD_RATE 250000
#define SPLASH_X_CENTER 33
#define SPLASH_Y_CENTER 13
#define SPLASH_DELAY 5000
#define TEXT_SIZE 1

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
  setupOLED(SPLASH_X_CENTER, SPLASH_Y_CENTER, TEXT_SIZE, SPLASH_DELAY);
  resetOLED(0, 0);

  /////////////////////////////////////////
  /// Setup Serial Communication
  Serial.begin(BAUD_RATE);
}


void loop()
{
  plotData();
}
