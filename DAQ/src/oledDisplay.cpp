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
#include "../include/oledDisplay.h"

Adafruit_SSD1306 display(OLED_RESET);

extern uint8_t data_byte;

/////////////////////////////////////////
/// Reset OLED to clear buffer and set the
/// cursor for the print function.
void resetOLED(int x, int y)
{
  display.setCursor(x, y);
  display.clearDisplay();
}

/////////////////////////////////////////
/// Show splash screen on OLED.
void displaySplashScreen(int x, int y, int duration)
{
  resetOLED(x,y);
  display.print("DAQ SYSTEM");
  display.display();
  delay(duration);
}

/////////////////////////////////////////
/// Initialize all of OLED settings in
/// one function.
void setupOLED(int x, int y, int textSize, int duration)
{
  // NOTE: #define SSD1306_128_64 is enabled in
  // Adafruit_SSD1306.h
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  display.setTextSize(textSize);
  display.setTextColor(WHITE);
  display.setRotation(0); // Rotates screen by 270
  displaySplashScreen(x, y, duration);
}

/////////////////////////////////////////
/// Show the sensor data, set the cursor.
void displayData(uint8_t data, int x, int y)
{
  resetOLED(x, y);
  display.print(data);
  display.display();
}

/////////////////////////////////////////
/// Plot data on OLED display.
void plotData()
{
  display.clearDisplay();

  uint8_t y = 0;
  for (int x = 0; x < (SSD1306_LCDWIDTH - 1); x++)
  {
    y = (SSD1306_LCDHEIGHT - 1) - (data_byte/DATA_SCALE_FACTOR);
    display.drawPixel(x, y, WHITE);

    display.display();
  }
}
