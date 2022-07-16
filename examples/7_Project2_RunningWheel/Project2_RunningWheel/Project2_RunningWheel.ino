/**************************************************************************
  Running wheel demo on Adafruit PyGamer
  June 2022
  Lex Kravitz
 **************************************************************************/

//We need these libraries
#include <Adafruit_GFX.h>                                    // Core graphics library
#include <Adafruit_ST7735.h>                                 // Hardware-specific library for ST7735
#include <SPI.h>                                             // SPI communication library
#include <SdFat.h>                                           // SD card & FAT filesystem library

Adafruit_ST7735 tft = Adafruit_ST7735(&SPI1, 44, 45, 46);    // Start screen - the numbers in the function are pin numbers for the screen
SdFat SD;                                                    // Start SD card filesystem

int wheelcounts = 0;                                         // Initialize a wheelcounts variable
bool countready = true;                                      // Initialize a variable to tell when we're ready to count a wheel turn

void setup(void) {
  tft.initR(INITR_BLACKTAB);                                 // Initialize ST7735R screen
  tft.setRotation(1);                                        // Set rotation
  tft.setTextSize(4);                                        // Set text size
  tft.fillScreen(ST77XX_BLACK);                              // clear screen
  tft.setTextColor(ST77XX_WHITE);                            // set font color
  tft.setCursor(5, 20);                                      // set cursor position
  tft.println("Count:");                                     // print light sensor reading
  tft.setTextColor(ST77XX_YELLOW);                           // set font color
  tft.setCursor(5, 52);                                      // set cursor position
  tft.println(wheelcounts);                                  // print wheelcounts

  pinMode(A11, INPUT);                                       //set joystick X pin to be an input
  digitalWrite(47, HIGH);                                    // turn on backlight (this is like our red LED, but on pin 47)
  SD.begin(4);                                               //initialize SD card
}

void loop() {
  int x = analogRead(A11);                                   // Read x position of joystick this will be ~510 in the resting center position and ~1023 when fully pushed right

  if (x > 600 and countready == true) {                      // if wheel moves the joystick...
    wheelcounts++;                                           // add 1 to wheelcounts
    countready = false;                                      // this variable stops repeat triggers
    tft.fillRect(0, 52, 400, 32, ST77XX_BLACK);              // erase a little area of the screen
    tft.setCursor(5, 52);                                    // set cursor position
    tft.println(wheelcounts / 4.00);                         // display wheel counts (divided by 4 - why?)
  }

  if (x < 600) {                                             // if joystick returns to center
    countready = true;                                       // get ready to count another joystick movement
  }

  ////////////////////////////////////////////////////
  // Task 1: Can you play a short tone on each rotation (every 4 clicks)?
  ////////////////////////////////////////////////////

  ////////////////////////////////////////////////////
  // Task 2: Can you log wheel counts to the SD card?
  ////////////////////////////////////////////////////
}
