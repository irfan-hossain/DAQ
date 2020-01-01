///////////////////////////////////////////////////////////////////////////////
//`File: configReg.h
// Desc: A file that contains all the function prototypes for configReg.cpp.
// These functions configure the ADC and TIMER registers for the proper
// sampling speeds and interrupts.
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////
#ifndef REGISTER_H
#define REGISTER_H

void configADMUX();
void configADCSRA();
void configADCSRB();
void configTCCR1A();
void configTCCR1B();
void configICR1();
void enableInterrupts();
void disableInterrupts();
void setupRegisters();

#endif
