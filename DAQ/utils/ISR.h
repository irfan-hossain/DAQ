///////////////////////////////////////////////////////////////////////////////
//`File: ISR.h
// Desc: File that contains all the ISR functions used in the code.
//
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////

extern volatile uint8_t data_byte;
extern volatile bool flag;
/////////////////////////////////////////
///
void enableInterrupts()
{

  // Enable Timer1 CMB.
  TIMSK1 |= (1 << OCIE1B);
  TCNT1   = 0;

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
  uint8_t byte0 = ADCL;
  uint8_t byte1 = ADCH;

  flag = true;
}
