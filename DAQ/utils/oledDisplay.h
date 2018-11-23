///////////////////////////////////////////////////////////////////////////////
//`File: oledDisplay.h
// Desc: File that contains functions relating to the OLED display.
//
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

/////////////////////////////////////////
///
void setupOLED(int textSize)
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextSize(textSize);
  display.setTextColor(WHITE);
}

/////////////////////////////////////////
///
void resetOLED(int x, int y)
{
  display.setCursor(0,0);
  display.clearDisplay();
}

/////////////////////////////////////////
///
void displayData(uint8_t data, int x, int y, int delay_time)
{
  resetOLED(x, y);
  display.print(data);
  delay(delay_time);
  display.display();
}
