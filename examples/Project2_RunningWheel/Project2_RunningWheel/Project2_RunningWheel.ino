/*
  Project 2: Running wheel demo on Adafruit PyGamer
  
  This code uses the Adafruit PyGamer board to count the number of revolutions made by a 3D-printed mouse wheel (3D files in /extras). 
  
  created Jun 2022
  by Lex Kravitz
*/

//We need these libraries
#include <Adafruit_GFX.h>                                    // Core graphics library
#include <Adafruit_ST7735.h>                                 // Hardware-specific library for ST7735
#include <SPI.h>                                             // SPI communication library
#include <SdFat.h>                                           // SD card & FAT filesystem library

Adafruit_ST7735 tft = Adafruit_ST7735(&SPI1, 44, 45, 46);    // Start screen - the numbers in the function are pin numbers for the screen
SdFat SD;                                                    // Start SD card filesystem

float wheelcounts = 0.00;                                    // Initialize a wheelcounts variable
bool countready = true;                                      // Initialize a variable to tell when we're ready to count a wheel turn

void setup(void) {
  ////////////////////////////////////////////////////
  // Task 0: We did the setup for you!  Check it out and make sure you understand each function call
  ////////////////////////////////////////////////////

  tft.initR(INITR_BLACKTAB);                                 // Initialize ST7735R screen
  tft.setRotation(1);                                        // Set rotation
  tft.setTextSize(4);                                        // Set text size
  tft.fillScreen(ST77XX_BLACK);                              // clear screen
  tft.setTextColor(ST77XX_WHITE);                            // set font color

  pinMode(A11, INPUT);                                       //set joystick X pin to be an input
  digitalWrite(47, HIGH);                                    //turn on backlight 
  SD.begin(4);                                               //start SD card
}

void loop() {
  ////////////////////////////////////////////////////
  // Task 1: analogRead the joystick X position on A11 and store it as a variable.  Print it to the Serial monitor and watch what happens as you spin the wheel
  ////////////////////////////////////////////////////

  ////////////////////////////////////////////////////
  // Task 2: If the X position exceeds 600, add 0.25 to the "wheelcounts" variable.  Print "wheelcounts" to the Serial monitor and watch it as you spin the wheel
  ////////////////////////////////////////////////////

  ////////////////////////////////////////////////////
  // Task 3: Now display the word "Counts" and wheelcounts on the screen. Again, watch them as you spin the wheel.  Do you notice any display issues?
  ////////////////////////////////////////////////////

  ////////////////////////////////////////////////////
  // Task 4: wheelcounts is incrementnig multiple times each time the joystick moves. Why is this?  Can you stop this from happening?
  ////////////////////////////////////////////////////

  ////////////////////////////////////////////////////
  // Final Task: Also log the timestamp and wheelcounts variable to the SD card!
  ////////////////////////////////////////////////////
}
