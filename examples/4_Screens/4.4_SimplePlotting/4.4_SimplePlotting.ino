/*
  Example 4.4: Light Sensor Screen Plot
  
  This example code plots data from the PyGamer's built-in light sensor
  and creates a dynamic graph on the TFT screen.
  
  This example utilizes libraries and code from Adafruit. 
  We encourage users to support open-source hardware and software!

  created Jun 2022
  by Lex Kravitz
*/

//We need these libraries to use the screen
#include <Adafruit_GFX.h>                                      // Core graphics library
#include <Adafruit_ST7735.h>                                   // Hardware-specific library for ST7735
#include <SPI.h>                                               // SPI communication library

Adafruit_ST7735 tft = Adafruit_ST7735(&SPI1, 44, 45, 46);      // Start screen - the numbers in the function are pin numbers for the screen

void setup(void) {
  tft.initR(INITR_BLACKTAB);                                   // Initialize ST7735R screen
  tft.setRotation(1);                                          // Rotate screen 90 degrees
  tft.fillScreen(ST77XX_BLACK);                                // Fill screen in black (ie: clear screen)
  digitalWrite(47, HIGH);                                      // turn on backlight (this is like our red LED, but on pin 47)
  pinMode (A7, INPUT);                                         // We'll read the light sensor on pin A7       
}

void loop() {
  //This is some very simple plotting code!
  for (int i = 0; i < 160; i++) {                              //this is a for loop that runs from 0 to 160 (the width of the screen), so we're running the code in this for loop for every pixel in the X direction
    int light = analogRead(A7);                                //read the light sensor
    tft.setCursor(0, 0);                                       //set cursor to the top left
    tft.fillRect(0, 0, 20, 10, ST77XX_BLACK);                  //clear area to print the light level in top left
    tft.print(light);                                          //write the light level in the top left
    int light_mapped = map(light, 0, 500, 0, 128);             //remap the light sensor readings from 0-500 to 0-128 (the height of the screen)
    tft.fillRect(i, 0, 5, 160, ST77XX_BLACK);                  //clear a 5 pixel wide bar ahead of where we'll be plotting (instead of clearing the whole screen we can just swipe a black rectangle across the screen ahead of us)
    tft.drawLine (i, 128, i, 128-light_mapped, ST77XX_WHITE);  //draw white line showing light level
    delay(20);                                                 //this sets the screen scrolling speed (ie: 20ms between pixels, or 3.2s to cross the screen)
  }
}

/*

Activities:
1) Change the color of the plot line to yellow
2) Plot the Joystick X position instead of the light sensor in yellow
3) (Advanced) Now plot the Joystick Y position on the same plot in white

*/
