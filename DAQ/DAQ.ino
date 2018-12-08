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

#include "include/configReg.h"
#include "include/ISR.h"
#include "include/oledDisplay.h"

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
  /// Setup registers for sampling.
  cli(); // Disable interrupts
  setupRegisters();
  sei(); // Enable interrups

  /////////////////////////////////////////
  /// Setup OLED display.
  setupOLED(SPLASH_X_CENTER, SPLASH_Y_CENTER, TEXT_SIZE, SPLASH_DELAY);

  /////////////////////////////////////////
  /// Setup Serial Communication
  Serial.begin(BAUD_RATE);
}


void loop()
{
  plotData();
}
