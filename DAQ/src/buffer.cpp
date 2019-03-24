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

/////////////////////////////////////////
///
void testFRAM()
{
  //Example code for the Adafruit I2C FRAM breakout */
  // Connect SCL    to analog 5
  // Connect SDA    to analog 4
  // Connect VDD    to 5.0V DC
  // Connect GROUND to common ground

  Adafruit_FRAM_I2C fram     = Adafruit_FRAM_I2C();
  uint16_t          framAddr = 0;

  Serial.begin(9600);

  if (fram.begin(0x50))
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
  for (uint16_t a = 0; a < 32768; a++)
  {

    value = fram.read8(a);
    if ((a % 32) == 0)
    {
      Serial.print("\n 0x"); Serial.print(a, HEX); Serial.print(": ");
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
  bool buff0_result = buff0.begin(0x50);
  bool buff1_result = buff0.begin(0x51);

  if ((buff0_result && buff1_result) != true)
  {
    Serial.println("FRAM ERROR: CHECK CONNECTIONS");
  }
}

/////////////////////////////////////////
///
void writeBufferI2C(uint8_t  data)
{
  // Which buffer to write to.
  static uint8_t buffNum = 0;
  // Index for FRAM address.
  static uint16_t i = 1;

  // Write data buffer.
  if (buffNum == 0)
  {
    buff0.write8(i, data);
    i++;
  }
  else if (buffNum = 1)
  {
    buff1.write8(i, data);
    i++;
  }
  else
  {
    Serial.println("BUFFER ERROR: BUFF NUM TOO HIGH");
  }

  // If the buffer is full, toggle buffer to
  // write to
  if (i == 32768)
  {
    i = 0;
    buffNum = !buffNum;
  }
}

/////////////////////////////////////////
///
void sendBufferSPI(uint8_t buffNum, uint16_t addr)
{
  if (buffNum == 0)
  {
    Serial.println(buff0.read8(addr));
  }
  else if (buffNum == 1)
  {
    Serial.println(buff1.read8(addr));
  }
  else 
  {
    Serial.println("BUFFER ERROR: BUFF NUM TOO HIGH");
  }

}
