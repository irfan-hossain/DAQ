///////////////////////////////////////////////////////////////////////////////
//`File: oledDisplay.h
// Desc: File that uses the SSD1306 library to draw objects specfic to this
// project.
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////
#ifndef OLEDDISPLAY_H
#define OLEDDISPLAY_H

#define OLED_RESET 4
#define DATA_SCALE_FACTOR 4
#define TEXT_SIZE 1

/////////////////////////////////////////
// module: resetOLED
//
// desc: Set's cursor for OLED and
// clears display.
//
// inputs: x - x coordinate for cursor
//         y - y cordinate for cursor
//
// outputs: none
//
// return: none
/////////////////////////////////////////
void resetOLED(int x, int y);

/////////////////////////////////////////
// module: setupOLED
//
// desc: Sets up OLED object for text
// size, color, and rotation. Also
// displays splash screen.
//
// inputs: x - x coordinate for cursor
//         y - y cordinate for cursor
//         duration - delay for splash
//         screen.
//
// outputs: none
//
// return: none
/////////////////////////////////////////
void setupOLED(int x, int y, int duration);

/////////////////////////////////////////
// module: displayText
//
// desc: Displays a text string on OLED.
//
// inputs: x - x coordinate for cursor
//         y - y cordinate for cursor
//         duration - delay for splash
//         screen.
//
// outputs:
//
// return:
/////////////////////////////////////////
void displayText(int x, int y, String text, int duration);

/////////////////////////////////////////
// module: displayData
//
// desc: Displays sensor data on OLED.
//
// inputs: x - x coordinate for cursor
//         y - y cordinate for cursor
//
// outputs:
//
// return:
/////////////////////////////////////////
void displayData(int x, int y, uint8_t data);

/////////////////////////////////////////
// module: plotData
//
// desc: Plots data in realtime from
// OLED.
//
// inputs: none
//
// outputs: none
//
// return: none
/////////////////////////////////////////
void plotData(uint8_t data);

#endif 