///////////////////////////////////////////////////////////////////////////////
//`File: DAQ.ino
// Desc: Main loop for arduino code to run.
//
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////
#include "Wire.h"
#include "isr.h"
#include "register.h"
#include "fram.h"
#include "oledDisplay.h"

#define BAUD_RATE 250000
#define SPLASH_X 33
#define SPLASH_Y 13
#define SPLASH_DELAY 5000

static const uint8_t  STATUS_LED_PIN = LED_BUILTIN; // LED for transmission status
static const uint8_t  START_BYTE     = 0x42; // Start sampling if read from Pi
static const uint8_t  END_BYTE       = 0x45; // End sampling if read from Pi

void setup()
{
  /////////////////////////////////////////
  /// Setup registers for sampling.
  setupRegisters();

  /////////////////////////////////////////
  /// Setup OLED display.
  setupOLED(SPLASH_X, SPLASH_Y, SPLASH_DELAY);
  
  /////////////////////////////////////////
  /// Setup Serial Communication
  Serial.begin(115200);

  /////////////////////////////////////////
  /// Setup FRAM chips.
  beginFRAM();

  /////////////////////////////////////////
  /// Setup LED.
  pinMode(STATUS_LED_PIN, OUTPUT);
}

void loop()
{
    txBuffer();
}
