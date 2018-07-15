///////////////////////////////////////////////////////////////////////////////
//`File: ISR.h
// Desc: File that contains all the ISE functions used in the code.
//
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////

static uint8_t TEST_POINT;

/////////////////////////////////////////
///
void enableInterrupts()
{

  // Enable Timer1 CMB.
  TIMSK1 |= (1 << OCIE1B);

  // ADC interrupt setup.
  ADCSRA |= (1 << ADEN); // Enable ADC
  ADCSRA |= (1 << ADIE); // Enable ADC
  ADCSRA |= (1 << ADSC); // Start first conversion

}

/////////////////////////////////////////
///
ISR(TIMER1_COMPB_vect)
{
  // Do nothing.
}

/////////////////////////////////////////
///
ISR(ADC_vect)
{
  // Read 8-bit conversion result from ADCH.
  TEST_POINT = ADCH;
}
