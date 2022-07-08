/**************************************************************************
  Loading images demo
  Put .bmp files on the SD card!
  July 2022
  Lex Kravitz
 **************************************************************************/

//We need these libraries - note that we added the SD library
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>
#include <SdFat.h>                // SD card & FAT filesystem library
#include <Adafruit_ImageReader.h> // Image-reading functions

//We need these pin definitions for SPI communication with the screen and SD card
#define TFT_CS        44     // PyBadge/PyGamer display control pins: chip select
#define TFT_RST       46     // Display reset
#define TFT_DC        45     // Display data/command select
#define TFT_BACKLIGHT 47     // Display backlight pin
#define chipSelect    4      // Chip Select pin for the SD card 

//Start screen object
Adafruit_ST7735 tft = Adafruit_ST7735(&SPI1, TFT_CS, TFT_DC, TFT_RST);

//SD card steup
SdFat                SD;         // SD card filesystem
Adafruit_ImageReader reader(SD); // Image-reader object, pass in SD filesys
Adafruit_Image         img;             // An image loaded into RAM
int32_t                width  = 0,      // BMP image dimensions
                       height = 0;

void setup(void) {
  ImageReturnCode stat; // Status from image-reading functions

  //setup the screen
  tft.initR(INITR_BLACKTAB);        //initialize ST7735R screen
  tft.setRotation(1);               //set screen rotation direction
  tft.setTextSize(4);               //set text size
  tft.fillScreen(ST77XX_BLACK);     //clear screen
  tft.setTextColor(ST77XX_WHITE);   //set text color
  tft.setCursor(5, 20);             //set cursor position
  pinMode(TFT_BACKLIGHT, OUTPUT);   //turn on backlight
  analogWrite(TFT_BACKLIGHT, 100);   // Backlight on dim (less annoying than on full brightness)

  //initialize SD card
  SD.begin(chipSelect);
}

void loop() {
  //draw image 1
  reader.drawBMP("/parrot.bmp", tft, 0, 0);
  delay (1000);
  
  //draw image 2
  reader.drawBMP("/daffodil.bmp", tft, 0, 0);
  delay (1000);
}
