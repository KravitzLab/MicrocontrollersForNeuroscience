/**************************************************************************
  Screen Text on Adafruit PyGamer
  June 2022
  Cammi Rood
 **************************************************************************/

//We need libraries
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>

//We need these pin definitions for SPI
#define TFT_CS        44 // PyBadge/PyGamer display control pins: chip select
#define TFT_RST       46 // Display reset
#define TFT_DC        45 // Display data/command select
#define TFT_BACKLIGHT 47 // Display backlight pin

//Start screen object
Adafruit_ST7735 tft = Adafruit_ST7735(&SPI1, TFT_CS, TFT_DC, TFT_RST);

int delayVal = 1000000;

void setup() {
  //Startup and clear the screen
  tft.initR(INITR_BLACKTAB);        // Initialize ST7735R 

  //turn on backlight
  pinMode(TFT_BACKLIGHT, OUTPUT);
  digitalWrite(TFT_BACKLIGHT, HIGH); // Backlight on
  tft.setRotation(1);
}

void loop() {
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(10, 10);                      //Coordinates for the position of the first letter written
  tft.setTextColor(ST77XX_RED);                
//tft.setTextColor(ST77XX_RED, ST77XX_BLACK); //Enables text highlighter  
  tft.setTextSize(2);
  tft.print("Welcome!");
  delay(delayVal);
}
