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

void setup()
{
  /////////////////////////////////////////
  /// Setup registers for sampling.
  setupRegisters();

  /////////////////////////////////////////
  /// Setup SPI Communication
  beginSPI();

  /////////////////////////////////////////
  /// Setup FRAM chips.
  refreshBuffers();
  beginFRAM();

  /////////////////////////////////////////
  /// Setup LEDs.
}

void loop()
{

}
