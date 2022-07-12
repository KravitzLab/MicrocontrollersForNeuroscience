/**************************************************************************

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

void setup(void) {
  //Startup and clear the screen
  tft.initR(INITR_BLACKTAB);        // Initialize ST7735R screen
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  
  //turn on backlight
  pinMode(TFT_BACKLIGHT, OUTPUT);
  digitalWrite(TFT_BACKLIGHT, HIGH); // Backlight on
}

void loop() {
  tft.setCursor(0, 0);
  tft.print("Hello world!");
}
