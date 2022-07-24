/*
Example 5.2: The 2nd simplest SD card example ever!

This code uses the PyGamer's built-in light sensor to write a 
csv file to the SD card.

created Jun 2022
by Lex Kravitz
*/

#include <SPI.h>                                       //Include SPI library
#include <SD.h>                                        //Include SD library
const int chipSelect = 4;                              //Set "Chip Select" pin for SD card on SPI bus
#define lightSensor A7                                 //Assign the variable lightSensor to pin A7

void setup() {
  SD.begin(chipSelect);                                //Initialize SD card
  pinMode(lightSensor, INPUT);                                  //Set lightSensor as an input
}

void loop() {
  File dataFile = SD.open("light.csv", FILE_WRITE);    //open file (if the filename doesn't exist this will create a new one)
  int light = analogRead(lightSensor);                 //read the light level from A7
  dataFile.println(light);                             //write the X position of the joystick to the file and move to the next line
  dataFile.close();                                    //close file (data won't be written on card until file is closed)
  delay(100);                                          //delay 100ms (this results in a 10Hz sampling rate of the light level)
}

/*

Activities:
1) If the light-level is >600, print "Bright light" instead of printing the number in the log file
2) If the light-level is <100, print "Low light" instead of printing the actual reading in the log file
3) (Advanced) Have the program write just 10 light sensor samples and stop logging.

*/
