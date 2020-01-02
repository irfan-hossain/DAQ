///////////////////////////////////////////////////////////////////////////////
//`File: fram.h
// Desc: Function that relate to FRAM sending and recieving.
//
//
//
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////
#ifndef FRAM_H
#define FRAM_H

void rxBuffer(uint8_t data);
void txBuffer();
void refreshBuffers();
void beginFRAM();
void bufferSwitching();
void beginSPI();
void writeSPI(uint8_t data);

#endif
