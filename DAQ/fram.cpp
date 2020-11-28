///////////////////////////////////////////////////////////////////////////////
//`File: fram.h
// Desc: Function that relate to FRAM sending and recieving.
//
//
//
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////
#include "Wire.h"
#include "fram.h"
#include "oledDisplay.h"
#include "Adafruit_FRAM_I2C.h"

// Takes second half of FRAM chip
static const uint16_t BUFFER1_END    = 0x8000;
static const uint16_t BUFFER1_START  = 0x4000;

// Takes first half of FRAM chip
static const uint16_t BUFFER0_END    = 0x4000;
static const uint16_t BUFFER0_START  = 0x0000;

static uint16_t rxAddress;
static uint16_t txAddress;

Adafruit_FRAM_I2C fram = Adafruit_FRAM_I2C();

/////////////////////////////////////////////////////////
// module: rxBuffer
//
// desc: Write data to specified buffer in FRAM.
//
// inputs: data - data to write
//
// outputs: none
//
// return: none
/////////////////////////////////////////////////////////
void rxBuffer(uint8_t data)
{
  bufferSwitching();
  fram.write8(rxAddress, data);
  rxAddress = rxAddress + sizeof(uint8_t);
}

/////////////////////////////////////////////////////////
// module: txBuffer
//
// desc: Send data from FRAM to Pi.
//
// inputs: none
//
// outputs: none
//
// return: none
/////////////////////////////////////////////////////////
void txBuffer()
{
  uint8_t data = fram.read8(txAddress);
  displayData(0, 0, data);
  txAddress = txAddress + sizeof(uint8_t);
}

/////////////////////////////////////////////////////////
// module: refreshBuffers
//
// desc: initialize FRAM begin and variables
//
// inputs: none
//
// outputs: none
//
// return: none
/////////////////////////////////////////////////////////
void refreshBuffers()
{
  rxAddress = BUFFER0_START;
  txAddress = BUFFER1_START;
}

/////////////////////////////////////////////////////////
// module: beginFRAM
//
// desc: Wrapper function for begin()
//
// inputs: none
//
// outputs: none
//
// return: none
/////////////////////////////////////////////////////////
void beginFRAM()
{
  refreshBuffers();
  fram.begin();
}

/////////////////////////////////////////////////////////
// module: bufferSwitching
//
// desc: Switch between send and recieve
//       buffers.
//
// inputs: none
//
// outputs: none
//
// return: none
/////////////////////////////////////////////////////////
void bufferSwitching()
{
  if (rxAddress == BUFFER0_END)
  {
    rxAddress = BUFFER1_START;
    txAddress = BUFFER0_START;
  }
  else if (rxAddress == BUFFER1_END)
  {
    rxAddress = BUFFER0_START;
    txAddress = BUFFER1_START;
  }
  else
  {
    // Do nothing
  }
}
