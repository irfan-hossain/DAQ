///////////////////////////////////////////////////////////////////////////////
//`File: buffer.h
// Desc: A file that contains all the function prototypes for buffer.cpp.
// These functions configure and implement the buffer sceheme using the
// I2C FRAM chips.
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////
#ifndef BUFFER_H
#define BUFFER_H

#define FRAM_SIZE 32768
/////////////////////////////////////////
// module: testFRAM
//
// desc: Taking the example from the
// FRAM library and putting in the
// function for easy testing.
//
// inputs: none
//
// outputs: none
//
// return: none
/////////////////////////////////////////
void testFRAM();

/////////////////////////////////////////
// module: setupBuffers
//
// desc: Begins FRAM communications and
// checls that connection is successful
//
// inputs: none
//
// outputs: result - 1 if both FRAM
//                   chips connected.
//                   0 if one or both
//                   FRAM chips fail.
//
// return: none
/////////////////////////////////////////
void setupBuffers();

/////////////////////////////////////////
// module: setupBuffers
//
// desc: Begins FRAM communications and
// checls that connection is successful
//
// inputs: none
//
// outputs: result - 1 if both FRAM
//                   chips connected.
//                   0 if one or both
//                   FRAM chips fail.
//
// return: none
/////////////////////////////////////////
void transmitBuffer(uint8_t buffNum, uint16_t addr);

/////////////////////////////////////////
// module: setupBuffers
//
// desc: Begins FRAM communications and
// checls that connection is successful
//
// inputs: none
//
// outputs: result - 1 if both FRAM
//                   chips connected.
//                   0 if one or both
//                   FRAM chips fail.
//
// return: none
/////////////////////////////////////////
void writeBuffer(uint8_t buffNum, uint16_t addr, uint8_t data);

#endif BUFFER_H
