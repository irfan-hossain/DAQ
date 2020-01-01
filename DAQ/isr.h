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

/////////////////////////////////////////
// module: TIMER1TIMER1_COMPB_vect
//
// desc: Interrupt triggered when Timer1
// reaches a set value. This interrupt then
// the ADC_vect interrupt for sampling.
///////////////////////////////////////////
ISR(TIMER1_COMPB_vect)
{
  // Do nothing.
}

/////////////////////////////////////////
// module:ADC_vect
//
// desc: Triggered when TIMER1_COMPB_vect
// is triggered. This starts the ADC the
// the ADC result is grabbed from here.
/////////////////////////////////////////
ISR(ADC_vect)
{
  // Read 8-bit conversion result from ADCH.

  // Write data to FRAM
}

#endif
