///////////////////////////////////////////////////////////////////////////////
//`File: DAQ.ino
// Desc: Main loop for arduino code to run.
//
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////

#include "utils/configReg.h"
#include "utils/ISR.h"

volatile uint8_t data_byte;
volatile bool flag;

void setup()
{
  /////////////////////////////////////////
  /// Disable Interrupts.
  cli();

  /////////////////////////////////////////
  /// Configure Registers for ADC
  configADMUX();
  configADCSRA();
  configADCSRB();

  /////////////////////////////////////////
  /// Configure Registers for Timer1
  configTCCR1A();
  configTCCR1B();
  configICR1();

  /////////////////////////////////////////
  /// Enable Interrupts for Timer1 and ADC.
  enableInterrupts();

  /////////////////////////////////////////
  /// Enable Interrupts
  sei();

  /////////////////////////////////////////
  /// Setup Serial Communication
  Serial.begin(250000);
}


void loop()
{
  if (flag == true)
  {
    //Serial.println("ISR HIT");
    Serial.println(data_byte);
    flag = false;
  }
}
