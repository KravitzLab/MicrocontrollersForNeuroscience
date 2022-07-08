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
//  tft.drawPixel(50, 50, ST77XX_WHITE); // Pixel

//  tft.drawLine(20, 0, 160, 128, ST77XX_BLUE); // Line
//  tft.drawLine(40, 0, 160, 128, ST77XX_BLUE); // Line
//  tft.drawLine(60, 0, 160, 128, ST77XX_BLUE); // Line
//  tft.drawLine(100, 0, 160, 128, ST77XX_BLUE); // Line
//  tft.drawLine(140, 0, 160, 128, ST77XX_BLUE); // Line
//  tft.drawLine(0, 10, 160, 128, ST77XX_BLUE); // Line
//  tft.drawLine(0, 30, 160, 128, ST77XX_BLUE); // Line
//  tft.drawLine(0, 50, 160, 128, ST77XX_BLUE); // Line
//  tft.drawLine(0, 80, 160, 128, ST77XX_BLUE); // Line
//  tft.drawLine(0, 100, 160, 128, ST77XX_BLUE); // Line
  
//  tft.drawRect(20, 10, 80, 50, ST77XX_YELLOW); // Rect outline
//  tft.drawRect(80, 40, 20, 60, ST77XX_WHITE); // Rect outline
//  tft.drawRect(40, 100, 50, 15, ST77XX_ORANGE); // Rect outline
//  tft.drawRect(100, 60, 40, 30, ST77XX_RED); // Rect outline
//  tft.fillRect(30, 70, 70, 30, ST77XX_BLUE); // Rect fill
//  tft.fillRect(60, 100, 30, 25, ST77XX_GREEN); // Rect fill
//  tft.fillRect(90, 40, 45, 40, ST77XX_MAGENTA); // Rect fill
//  tft.fillRect(30, 12, 20, 35, ST77XX_WHITE); // Rect fill

//  tft.drawCircle(80, 64, 40, ST77XX_MAGENTA); // Circle outline
//  tft.fillCircle(80, 64, 39, ST77XX_WHITE); // Circle fill

//  tft.drawRoundRect(40, 32, 80, 64, 10, ST77XX_ORANGE); // Round rectangle outline
//  tft.fillRoundRect(41, 33, 78, 62, 10, ST77XX_GREEN); // Round rectangle fill

//  tft.drawTriangle(30, 20, 40, 90, 80, 70, ST77XX_WHITE); // Triangle outline
//  tft.fillTriangle(31, 22, 42, 89, 78, 70, ST77XX_MAGENTA); // Triangle fill

  delay(delayVal);
}
