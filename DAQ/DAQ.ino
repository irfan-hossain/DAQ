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
#include "include/buffer.h"

#define BAUD_RATE 115200
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
  setupRegisters();

  /////////////////////////////////////////
  /// Setup Serial Communication
  Serial.begin(BAUD_RATE);

  // Setup FRAM Chips
  setupBuffers();
}

void loop()
{
  if (data_flag == true)
  {
    static uint8_t buffNum = 0;
    static uint16_t i = 0;

    transmitBuffer(buffNum, i);
    writeBuffer(buffNum, i, data_byte);

    if (i == FRAM_SIZE)
    {
      i = 0;
      bufNum = 1;
    }
    
    data_flag = false;
    i++;
  }


}
