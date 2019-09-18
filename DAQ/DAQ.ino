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

static const uint16_t BAUD_RATE  = 9600;
static const uint16_t FRAM_SIZE  = 32768;
static const uint16_t SPLASH_DEL = 2000;
static const uint8_t  SPLASH_X   = 33;
static const uint8_t  SPLASH_Y   = 13;
static const uint8_t  TEXT_SIZE  = 1;


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

  /////////////////////////////////////////
  /// Setup FRAM chips.
  setupBuffers();
}

void loop()
{

  if (data_flag == true)
  {
     Serial.println(data_byte);
     data_flag = false;
  }
;
//  if (data_flag == true)
//  {
//    static uint8_t buffNum = 0;
//    static uint16_t i = 0;
//
//    transmitBuffer(buffNum, i);
//    writeBuffer(buffNum, i, data_byte);
//
//    if (i == FRAM_SIZE)
//    {
//      i = 0;
//      buffNum = 1;
//    }
//
//    data_flag = false;
//    i++;
//  }

}
