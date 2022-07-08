/**************************************************************************
  Loading images demo
  Put parrot.bmp and daffodil.bmp on the SD card!
  July 2022
  Lex Kravitz
 **************************************************************************/

//We need these libraries
#include <Adafruit_GFX.h>                        // Core graphics library
#include <Adafruit_ST7735.h>                     // Hardware-specific library for ST7735
#include <SPI.h>                                 // SPI library for controlling screen
#include <SdFat.h>                               // SD card & FAT filesystem library
#include <Adafruit_ImageReader.h>                // Image-reading functions

//We need these pin definitions for SPI communication with the screen and SD card
#define TFT_CS        44                         // PyBadge/PyGamer display control pins: chip select
#define TFT_RST       46                         // Display reset
#define TFT_DC        45                         // Display data/command select
#define TFT_BACKLIGHT 47                         // Display backlight pin
#define chipSelect    4                          // Chip Select pin for the SD card 

//Start screen object
Adafruit_ST7735 tft = Adafruit_ST7735(&SPI1, TFT_CS, TFT_DC, TFT_RST);

//SD card steup
SdFat SD;                                        // SD card filesystem
Adafruit_ImageReader reader(SD);                 // Image-reader object, pass in SD filesys
Adafruit_Image img;                              // An image loaded into RAM

void setup(void) {
  tft.initR(INITR_BLACKTAB);                     //initialize ST7735R screen
  tft.setRotation(1);                            //set screen rotation direction
  tft.fillScreen(ST77XX_BLACK);                  //clear screen
  analogWrite(TFT_BACKLIGHT, 100);               // Backlight on full

  SD.begin(chipSelect);                          //initialize SD card
}

void loop() {
  ////////////// draw image 1 ////////////// 
  tft.fillScreen(ST77XX_BLACK);                  //clear screen
  reader.drawBMP("/parrot.bmp", tft, 16, 0);     //draw parrot
  delay (1000);                                  //wait a second

  ////////////// draw image 2 ////////////// 
  tft.fillScreen(ST77XX_BLACK);                  //clear screen
  reader.drawBMP("/daffodil.bmp", tft, 32, 32);  //draw daffodil
  delay (1000);                                  //wait a second
}
