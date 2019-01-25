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
#define SPLASH_X 33
#define SPLASH_Y 13
#define SPLASH_DELAY 2000
#define TEXT_SIZE 1

volatile uint8_t data_byte = 0;
volatile bool data_flag = false;

void setup()
{
  /////////////////////////////////////////
  /// Setup registers for sampling.
  cli(); // Disable interrupts
  setupRegisters();
  sei(); // Enable interrupts

  /////////////////////////////////////////
  /// Setup OLED display.
  setupOLED(SPLASH_X, SPLASH_Y, SPLASH_DELAY);

  /////////////////////////////////////////
  /// Setup Serial Communication
  Serial.begin(BAUD_RATE);
}

void loop()
{
  if (data_flag == true)
  {
    Serial.println(data_byte);
    data_flag = false;
  }
}
