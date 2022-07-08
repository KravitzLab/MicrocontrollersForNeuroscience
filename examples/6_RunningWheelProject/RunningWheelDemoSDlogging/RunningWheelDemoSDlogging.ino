/**************************************************************************
  Running wheel demo on Adafruit PyGamer with SD card logging
  June 2022
  Lex Kravitz
 **************************************************************************/

//We need these libraries - note that we added the SD library
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>
#include <SD.h>

//We need these pin definitions for SPI communication with the screen and SD card
#define TFT_CS        44     // PyBadge/PyGamer display control pins: chip select
#define TFT_RST       46     // Display reset
#define TFT_DC        45     // Display data/command select
#define TFT_BACKLIGHT 47     // Display backlight pin
#define chipSelect    4      // Chip Select pin for the SD card 

//Start screen object
Adafruit_ST7735 tft = Adafruit_ST7735(&SPI1, TFT_CS, TFT_DC, TFT_RST);

//Initialize variables
unsigned long currenttime = 0;  //this will store the time
float wheelcounts = 0;            //this will store our wheel counts
bool countready = true;

void setup(void) {
  //setup the screen 
  tft.initR(INITR_BLACKTAB);        //initialize ST7735R screen
  tft.setRotation(1);               //set screen rotation direction
  tft.setTextSize(4);               //set text size
  tft.fillScreen(ST77XX_BLACK);     //clear screen
  tft.setTextColor(ST77XX_WHITE);   //set text color
  tft.setCursor(5, 20);             //set cursor position
  tft.println("Count:");            //print light sensor reading
  tft.setTextColor(ST77XX_YELLOW);  //set text color
  tft.setCursor(5, 52);             //set cursor position
  tft.println(wheelcounts);         //print wheel counts
  pinMode(TFT_BACKLIGHT, OUTPUT);   //turn on backlight
  analogWrite(TFT_BACKLIGHT, 10);   // Backlight on dim (less annoying than on full brightness)

  //initialize SD card, create a datafile, and write header
  SD.begin(chipSelect);
  File dataFile = SD.open("wheels.csv", FILE_WRITE);        //create a file - NOTE: for SD library the filename must be 8 characters
  dataFile.println("Time, Counts");                         //write a header
  dataFile.close();                                         //close the file to write the data
}

void loop() {
  //read the x position of the joystick (our wheel sensor)
  int x = analogRead(A11);  //this will be ~510 in the resting center position and ~1023 when fully pushed right

  //if a joystick is moved
  if (x > 600 and countready == true) {
    currenttime = millis();
    wheelcounts++;
    countready = false;
    tft.fillRect(0, 52, 400, 32, ST77XX_BLACK);
    tft.setCursor(5, 52);                                     // set cursor position
    tft.println(wheelcounts/4);

    //write data to the SD card
    digitalWrite (13, HIGH);                                  //light up red LED on back so we can tell if the SD card is being accessed
    File dataFile = SD.open("wheels.csv", FILE_WRITE);        //open the datafile so we can write to it
    dataFile.print(currenttime/1000.000);                     //write the time (in seconds)
    dataFile.print(",");                                      //write a "," to create a new column in the .csv file
    dataFile.println(wheelcounts/4);                          //write the wheel counts
    dataFile.close();                                         //close the datafile
    digitalWrite (13, LOW);                                   //turn off red LED
  }

  //set countready to true when joystick returns to the center (this stops the counter from triggering multiple times per movement)
  if (x < 600) {
    countready = true;
  }
}
