///////////////////////////////////////////////////////////////////////////////
//`File: ISR.h
// Desc: File that contains all the ISR functions used in the code. This .h
// file does not have any includers other than the .ino file because the ISR
// functions are only used once.
//
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////
#ifndef ISR_H
#define ISR_H

extern volatile uint8_t data_byte;
extern volatile bool data_flag;
extern volatile bool pb_flag;

/////////////////////////////////////////
/// Interrupt just to trigger sampling
/// does nothing.
ISR(TIMER1_COMPB_vect)
{
  // Do nothing.
}

/////////////////////////////////////////
/// Grab sample from ADCH
ISR(ADC_vect)
{
  // Read 8-bit conversion result from ADCH.
  uint8_t byte0 = ADCL;
  uint8_t byte1 = ADCH;

  data_byte = byte1;
  data_flag = true;
}

/////////////////////////////////////////
/// Interrupt when pin 2 is on rising
/// edge.
ISR(INT0_vect)
{
  pb_flag = true;
}

#endif ISR_H
