///////////////////////////////////////////////////////////////////////////////
//`File: configReg.h
// Desc: A file that contains all the functions to configure register for the
//       ADC and Timer1. See README.md for more information.
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////

void configADMUX()
{
 // Set Register to all zeros since Vref
 // will be set to internal voltge and
 // analog pin A0 is used.
 ADMUX = 0x00;

 // Set bit 5 (ADLAR) to left shift conversion
 // result. This creats an 8-bit result in
 // ADCH.
 ADMUX |= (1 << ADLAR);

}

void configADCSRA()
{
  // Turn ADC on.
  ADCSRA |= (1 << ADEN);

  // Enable auto trigger so Timer1 can trigger
  // the ADC.
  ADCSRA |= (1 << ADATE);

  // Set the ADC prescaler. PRESCALER = 2.
  ADCSRA &= ~(1 << ADPS2);
  ADCSRA &= ~(1 << ADPS1);
  ADCSRA |=  (1 << ADPS0);
}

void configADCSRB()
{
  // ACME is not used and should be set to zero.
  ADCSRB &= ~(1 << ACME);

  // Set Timer1 to CMB.
  ADCSRB |=  (1 << ADTS2);
  ADCSRB &= ~(1 << ADTS1);
  ADCSRB |=  (1 << ADTS0);
}