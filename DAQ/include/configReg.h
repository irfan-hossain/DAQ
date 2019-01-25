///////////////////////////////////////////////////////////////////////////////
//`File: configReg.h
// Desc: A file that contains all the function prototypes for configReg.cpp.
// These functions configure the ADC and TIMER registers for the proper
// sampling speeds and interrupts.
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////
#ifndef CONFIGREG_H
#define CONFIGREG_H

#define PRESCALER_INTERRUPT 19

/////////////////////////////////////////
// module: configADMUX
//
// desc: Set registers relating to ADC
// input pin and whether to left shift
// conversion.
//
// inputs: none
//
// outputs: none
//
// return: none
/////////////////////////////////////////
void configADMUX();

/////////////////////////////////////////
// module: configADCSRA
//
// desc: Configure register to turn
// ADC on, the autotrigger, and set
// the ADC clock prescaler.
//
// inputs: none
//
// outputs: none
//
// return: none
/////////////////////////////////////////
void configADCSRA();

/////////////////////////////////////////
// module: configADCSRB
//
// desc: Configure Timer1 mode.
//
// inputs: none
//
// outputs: none
//
// return: none
/////////////////////////////////////////
void configADCSRB();

/////////////////////////////////////////
// module: configTCCR1A
//
// desc: Has bits to set register of
// TOP register for Timer1.
//
// inputs: none
//
// outputs: none
//
// return: none
/////////////////////////////////////////
void configTCCR1A();

/////////////////////////////////////////
// module: configTCCR1B
//
// desc: Has bits to set register of
// TOP register for Timer1 and set the
// Timer1 prescaler.
//
// inputs: none
//
// outputs: none
//
// return: none
/////////////////////////////////////////
void configTCCR1B();

/////////////////////////////////////////
// module: configICR1
//
// desc: Set TOP value.
//
// inputs: none
//
// outputs: none
//
// return: none
/////////////////////////////////////////
void configICR1();

/////////////////////////////////////////
// module: configInterrupts
//
// desc: Enable Timer1, ADC, and Pin 2
// interrupts.
//
// inputs: none
//
// outputs: none
//
// return: none
/////////////////////////////////////////
void configInterrupts();

/////////////////////////////////////////
// module: setupRegisters
//
// desc: Function to wrap all the setup functions
// to be called in setup.
//
// inputs: none
//
// outputs: none
//
// return: none
/////////////////////////////////////////
void setupRegisters();

#endif CONFIGREG_H
