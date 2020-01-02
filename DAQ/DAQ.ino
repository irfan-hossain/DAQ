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

static const uint8_t statusLEDPin = 6; // LED for transmission status
static const uint8_t startByte    = 0x42; // Start sampling if read from Pi
static const uint8_t endByte      = 0x45; // End sampling if read from Pi

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
  beginFRAM();

  /////////////////////////////////////////
  /// Setup LED.
  pinMode(statusLEDPin, OUTPUT);
}

void loop()
{
  static bool startSampling = false;

  // Continously check if we recieved data over SPI from Pi
  if (SPIF != 0) // We have data!
  {
    if (SPDR == startByte) // Start sampling
    {
      enableInterrupts();
      startSampling = true;
    }
    else if (SPDR == endByte) // Stop Sampling
    {
      disableInterrupts();
      startSampling = false;
    }
    else
    {
      // do nothing
    }
  }

  // Now that we're sampling, blink led and transmit buffer.
  if (startSampling == true)
  {
    digitalWrite(statusLEDPin, HIGH);
    txBuffer();
    digitalWrite(statusLEDPin, LOW);
  }
}
