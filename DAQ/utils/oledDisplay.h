///////////////////////////////////////////////////////////////////////////////
//`File: oledDisplay.h
// Desc: File that uses the SSD1306 library to draw objects specfic to this
// project.
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

/////////////////////////////////////////
/// Initialize all of OLED settings in
/// one function.
void setupOLED(int textSize)
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextSize(textSize);
  display.setTextColor(WHITE);
  display.setRotation(0); // Rotates screen by 270
}

/////////////////////////////////////////
/// Reset OLED to clear buffer and set the
/// cursor for the print function.
void resetOLED(int x, int y)
{
  display.setCursor(x, y);
  display.clearDisplay();
}

/////////////////////////////////////////
/// Show the sensor data, set the cursor.
void displayData(uint8_t data, int x, int y)
{
  resetOLED(x, y);
  display.print(data);
  display.display();
}
