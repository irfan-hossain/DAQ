///////////////////////////////////////////////////////////////////////////////
//`File: oledDisplay.h
// Desc: File that uses the SSD1306 library to draw objects specfic to this
// project.
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define OLED_WIDTH 127
#define OLED_HEIGHT 31
#define DATA_SCALE_FACTOR 8

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
  display.clearDisplay();
}

/////////////////////////////////////////
/// Initialize all of OLED settings in
/// one function.
void setupOLED(int x, int y, int textSize, int duration)
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
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
  for (int x = 0; x < OLED_WIDTH; x++)
  {
    y = OLED_HEIGHT - (data_byte/DATA_SCALE_FACTOR);
    display.drawPixel(x, y, WHITE);

    display.display();
  }
}
