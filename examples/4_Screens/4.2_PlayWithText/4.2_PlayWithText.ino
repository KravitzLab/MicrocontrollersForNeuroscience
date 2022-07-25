/*
  Example 4.2: Play with text

  We're going to learn a few more functions here:
  tft.setRotation(1) rotates the screen 90 degrees
  tft.setCursor(X, Y) moves the cursor location
  tft.setTextSize(N) changes the text size
  tft.setTextColor(COLOR) change the color - you can try ST77XX_RED, ST77XX_WHITE, ST77XX_BLUE, etc for colors
  
  This example utilizes libraries and code from Adafruit. 
  We encourage users to support open-source hardware and software!
  
  created Jun 2022
  by Lex Kravitz (based heavily on Adafruit example code!)
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
  tft.setTextSize(1);                                        // Default text size is 1 - try to change it!
  tft.setTextColor(ST77XX_RED);                              // Set font color
  tft.fillScreen(ST77XX_BLACK);                              // Fill screen in black (ie: clear screen)
  tft.setCursor(5, 20);                                      // This moves the cursor position around
  tft.print("I'm over here!");                               // print message - you can change this to print comical expressions!
  delay (1000);                                              // wait a second

  tft.setTextColor(ST77XX_WHITE);                            // Set font color
  tft.fillScreen(ST77XX_BLACK);                              // Fill screen in black (ie: clear screen)
  tft.setCursor(30, 90);                                     // This moves the cursor position around
  tft.print("Now I'm over here!");                           // print message - you can change this to print comical expressions!
  delay (1000);                                              // wait a second
}

/*

Activities:
1) Rotate the screen to make the text appear upside-down
2) Set the textsize to 2, what happens?  What about 3?
3) Change the backlight brightness with an analogWrite() call

*/
