///////////////////////////////////////////////////////////////////////////////
//`File: oledDisplay.h
// Desc: File that uses the SSD1306 library to draw objects specfic to this
// project.
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////
#include <SPI.h>
#include <Wire.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "oledDisplay.h"

Adafruit_SSD1306 display(OLED_RESET);

/////////////////////////////////////////
///
void resetOLED(int x, int y)
{
  display.setCursor(x, y);
  display.clearDisplay();
}

/////////////////////////////////////////
///
void setupOLED(int x, int y, int duration)
{
  // NOTE: #define SSD1306_128_64 is enabled in
  // Adafruit_SSD1306.h
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  display.setTextSize(TEXT_SIZE);
  display.setTextColor(WHITE);
  display.setRotation(0); // Rotates screen by 270

  String text = "DAQ SYSTEM";
  displayText(x, y, text, duration);
}

/////////////////////////////////////////
///
void displayText(int x, int y, String text, int duration)
{
  resetOLED(x,y);
  display.print(text);
  display.display();
  delay(duration);
}

/////////////////////////////////////////
///
void displayData( int x, int y, uint8_t data)
{
  resetOLED(x, y);
  display.print(data);
  display.display();
}

/////////////////////////////////////////
///
void plotData(uint8_t data)
{
  display.clearDisplay();

  uint8_t y = 0;
  for (int x = 0; x < (SSD1306_LCDWIDTH - 1); x++)
  {
    y = (SSD1306_LCDHEIGHT - 1) - (data/DATA_SCALE_FACTOR);
    display.drawPixel(x, y, WHITE);

    display.display();
  }
}