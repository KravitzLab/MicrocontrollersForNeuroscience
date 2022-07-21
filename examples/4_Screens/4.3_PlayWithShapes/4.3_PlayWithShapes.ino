/*
  Example 4.3: Play with shapes

  We're going to learn to draw shapes here - try copy/pasting these commands into the void loop()
  tft.drawPixel(50, 50, ST77XX_WHITE);                       // Pixel
  tft.drawLine(20, 0, 160, 128, ST77XX_BLUE);                // Line
  tft.drawRect(20, 10, 80, 50, ST77XX_YELLOW);               // Rect outline
  tft.fillRect(30, 70, 70, 30, ST77XX_BLUE);                 // Rect fill
  tft.drawCircle(80, 64, 40, ST77XX_MAGENTA);                // Circle outline
  tft.fillCircle(80, 64, 39, ST77XX_WHITE);                  // Circle fill
  tft.drawRoundRect(40, 32, 80, 64, 10, ST77XX_ORANGE);      // Round rectangle outline
  tft.fillRoundRect(41, 33, 78, 62, 10, ST77XX_GREEN);       // Round rectangle fill
  
  This example utilizes libraries and code from Adafruit. 
  We encourage users to support open-source hardware and software!
  
  created Jun 2022
  by Cammi Rood and Lex Kravitz
*/

//We need these libraries to use the screen
#include <Adafruit_GFX.h>                                    // Core graphics library
#include <Adafruit_ST7735.h>                                 // Hardware-specific library for ST7735
#include <SPI.h>                                             // SPI communication library

Adafruit_ST7735 tft = Adafruit_ST7735(&SPI1, 44, 45, 46);    // Start screen - the numbers in the function are pin numbers for the screen

void setup(void) {
  tft.initR(INITR_BLACKTAB);                                 // Initialize ST7735R screen
  tft.setRotation(1);                                        // Rotate screen 90 degrees
  tft.fillScreen(ST77XX_BLACK);                              // Fill screen in black (ie: clear screen)
  digitalWrite(47, HIGH);                                    // turn on backlight (this is like our red LED, but on pin 47)
}

void loop() {
  tft.drawCircle(40, 40, 6, ST77XX_WHITE);                   // Draw circle
  tft.drawLine(41, 50, 50, 45, ST77XX_BLACK);                // Line - why are we doing this line in black??
  tft.drawLine(40, 46, 40, 65, ST77XX_WHITE);                // Line
  tft.drawLine(30, 50, 50, 50, ST77XX_WHITE);                // Line
  tft.drawLine(40, 65, 35, 80, ST77XX_WHITE);                // Line
  tft.drawLine(40, 65, 45, 80, ST77XX_WHITE);                // Line
  delay (1000);
  
  tft.drawLine(41, 50, 50, 50, ST77XX_BLACK);                // Line - again, why are we doing this line in black??
  tft.drawLine(41, 50, 50, 45, ST77XX_WHITE);                // Line
  delay (1000);
}
