/*
  Example 4.1: Screen test
  
  This code introduces users to the built-in TFT screen on the PyGamer.
  
  This example utilizes libraries and code from Adafruit. 
  We encourage users to support open-source hardware and software!
  
  created Jun 2022
  by Lex Kravitz (based heavily on Adafruit example code!)
*/

//We need these libraries to use the screen
#include <Adafruit_GFX.h>                                    // Core graphics library
#include <Adafruit_ST7735.h>                                 // Hardware-specific library for ST7735
#include <SPI.h>                                             // SPI communication library

Adafruit_ST7735 tft = Adafruit_ST7735(&SPI1, 44, 45, 46);    //Start screen

void setup(void) {
  tft.initR(INITR_BLACKTAB);                                 // Initialize ST7735R screen
  tft.fillScreen(ST77XX_BLACK);                              // Fill screen in black (ie: clear screen)
  digitalWrite(47, HIGH);                                    // turn on backlight on pin 47
  tft.print("Hello world!");                                 // print "Hello world!" - you can change this to print comical expressions!
}

void loop() {
}                                                             // Why don't we have anything in the void loop here??

/*

Activities:
1) Why didn't we put anything in the void loop() in this script?
2) Change the text to say hi to your neighbor
3) Change the color of the text to Red
4) Change the position of the text to the center of the screen.  (Hint: Google the Adafruit GFX library!)

*/
