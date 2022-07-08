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

void setup() {
  tft.initR(INITR_BLACKTAB);                                  //initialize ST7735R
  tft.fillScreen(ST77XX_BLACK);                               //clear screen

  //turn on backlight
  pinMode (TFT_BACKLIGHT, OUTPUT);                            //set backlight pin as an output
  pinMode (A7, INPUT);                                        //set light sensor pin as an input 
  analogWrite(TFT_BACKLIGHT, 50);                             //turn on backlight ~20% brightness
  tft.setRotation(1);                                         //set screen rotation
}

void loop() {
  //simple plotting code!
  for (int i = 0; i < 160; i++) {                              //this is a for loop that runs from 0 to 160 (the width of the screen), so we're running the code in this for loop for every pixel in the X direction
    int light = analogRead(A7);                                //read the light sensor
    tft.setCursor(0, 0);                                       //set cursor to the top left
    tft.fillRect(0, 0, 20, 10, ST77XX_BLACK);                  //clear area to print the light level in top left
    tft.print(light);                                          //write the light level in the top left
    int light_mapped = map(light, 0, 500, 0, 128);             //remap the light sensor readings from 0-500 to 0-128 (the height of the screen)
    tft.fillRect(i, 0, 5, 160, ST77XX_BLACK);                  //clear a 5 pixel wide bar ahead of where we'll be plotting (instead of clearing the whole screen we can just swipe a black rectangle across the screen ahead of us)
    tft.drawLine (i, 128, i, 128-light_mapped, ST77XX_WHITE);  //draw white line showing light level
    tft.drawPixel(i, 127-light_mapped, ST77XX_YELLOW);         //also draw a yellow pixel on top to highlight our plot
    delay(20);                                                 //this sets the screen scrolling speed (ie: 20ms between pixels, or 3.2s to cross the screen)
  }
}
