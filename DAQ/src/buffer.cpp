////////////////////////////////////////////////////////////////////////////
//`File: buffer.cpp
// Desc: A file that contains all the implementations for buffer.h.
// These functions configure and implement the buffer sceheme using the
// I2C FRAM chips.
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////
#include <Wire.h>
#include "Adafruit_FRAM_I2C.h"
#include "../include/buffer.h"

static Adafruit_FRAM_I2C buff0     = Adafruit_FRAM_I2C();
static Adafruit_FRAM_I2C buff1     = Adafruit_FRAM_I2C();

static const uint8_t  BUFF0_ADDR = 0x50;
static const uint8_t  BUFF1_ADDR = 0x51;

/////////////////////////////////////////
///
void testFRAM(uint16_t baud_rate, uint16_t fram_size)
{
  //Example code for the Adafruit I2C FRAM breakout */
  // Connect SCL    to analog 5
  // Connect SDA    to analog 4
  // Connect VDD    to 5.0V DC
  // Connect GROUND to common ground

  Adafruit_FRAM_I2C fram     = Adafruit_FRAM_I2C();

  Serial.begin(baud_rate);

  if (fram.begin(BUFF1_ADDR))
  {  // you can stick the new i2c addr in here, e.g. begin(0x51);
    Serial.println("Found I2C FRAM");
  } else
  {
    Serial.println("I2C FRAM not identified ... check your connections?\r\n");
    Serial.println("Will continue in case this processor doesn't support repeated start\r\n");
  }

  // Read the first byte
  uint8_t test = fram.read8(0x0);
  Serial.print("Restarted "); Serial.print(test); Serial.println(" times");
  // Test write ++
  fram.write8(0x0, 0x00);

  // dump the entire 32K of memory!
  uint8_t value;
  for (uint16_t i = 0; i < fram_size; i++)
  {

    value = fram.read8(i);
    if ((i % 32) == 0)
    {
      Serial.print("\n 0x"); Serial.print(i, HEX); Serial.print(": ");
    }

    Serial.print("0x");

    if (value < 0x1)
    {
      Serial.print('0');
    }

    Serial.print(value, HEX); Serial.print(" ");
  }
}

/////////////////////////////////////////
///
void setupBuffers()
{
  bool result = 0;

  result = buff0.begin(BUFF0_ADDR);
  if (result == true)
  {
    Serial.println("BUFF 0 FRAM SUCCESS");
  }
  else
  {
    Serial.println("BUFF 0 FRAM ERROR: CHECK CONNECTIONS");
  }

  // result = buff1.begin(BUFF1_ADDR);
  // if (result != true)
  // {
  //   Serial.println("BUFF 1 FRAM ERROR: CHECK CONNECTIONS");
  // }
}

/////////////////////////////////////////
///
void transmitBuffer(uint8_t buffNum, uint16_t addr)
{
  uint8_t data = 0;

  if (buffNum == 0)
  {
    data = buff0.read8(addr);
    Serial.print(buffNum);
    Serial.print("\t");
    Serial.println(data);
    // SPI send data
  }
  // else if (buffNum == 1)
  // {
  //   data = buff1.read8(addr);
  //   Serial.print(buffNum);
  //   Serial.print("\t");
  //   Serial.println(data);
  //   // SPI send data
  // }
  // else
  // {
  //   // How many owls does it take to code an app?
  //   // i dont know either
  // }
}

/////////////////////////////////////////
///
void writeBuffer(uint8_t buffNum, uint16_t addr, uint8_t data)
{
  if (buffNum == 0)
  {
    buff0.write8(addr, data);
  }
  // else if (buffNum == 1)
  // {
  //   buff1.write8(addr, data);
  // }
  // else
  // {
  //   // My coding skills are the same as that
  //   // of a sack of potatoes
  // }
}
