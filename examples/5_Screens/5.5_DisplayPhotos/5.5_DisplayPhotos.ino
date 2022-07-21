/*
  Example 5.5: Loading images demo
  
  Copy parrot.bmp and daffodil.bmp from the /extras directory to the SD card in PyGamer 
  
  This example utilizes libraries and code from Adafruit. 
  We encourage users to support open-source hardware and software!
  
  adapted from an Arduino example Jul 2022
  by Lex Kravitz
 **************************************************************************/

//We need these libraries 
#include <Adafruit_GFX.h>                                    // Core graphics library
#include <Adafruit_ST7735.h>                                 // Hardware-specific library for ST7735
#include <SPI.h>                                             // SPI communication library
#include <SdFat.h>                                           // SD card & FAT filesystem library
#include <Adafruit_ImageReader.h>                            // Image-reading functions

Adafruit_ST7735 tft = Adafruit_ST7735(&SPI1, 44, 45, 46);    // Start screen - the numbers in the function are pin numbers for the screen

//Code to use the SD card and the ImageRead library
SdFat SD;                                                    // SD card filesystem
Adafruit_ImageReader reader(SD);                             // Image-reader object, pass in SD filesys
Adafruit_Image img;                                          // An image loaded into RAM

void setup(void) {
  tft.initR(INITR_BLACKTAB);                                 // Initialize ST7735R screen
  tft.setRotation(1);                                        // Rotate screen 90 degrees
  tft.fillScreen(ST77XX_BLACK);                              // Fill screen in black (ie: clear screen)
  digitalWrite(47, HIGH);                                    // turn on backlight (this is like our red LED, but on pin 47)
  SD.begin(4);                                               //initialize SD card
}

void loop() {
  ////////////// draw image 1 ////////////// 
  tft.fillScreen(ST77XX_BLACK);                              //clear screen
  reader.drawBMP("/parrot.bmp", tft, 16, 0);                 //load parrot bmp
  delay (1000);                                              //wait a second

  ////////////// draw image 2 ////////////// 
  tft.fillScreen(ST77XX_BLACK);                              //clear screen
  reader.drawBMP("/daffodil.bmp", tft, 32, 32);              //draw daffodil
  delay (1000);                                              //wait a second
}
