/*
Example 5.3: Log light levels with a timestamp!

This code writes values from the analog light sensor to a csv file 
on an SD card with time stamps.

It also uses the Arduino millis() function (Google it!) to record a timestamp.

created Jul 2022
by Lex Kravitz
*/

#include <SPI.h>                                         //Include SPI library
#include <SD.h>                                          //Include SD library
const int chipSelect = 4;                                //Set "Chip Select" pin for SD card on SPI bus
#define lightSensor A7                                   //Assign the variable label lightSensor to pin A7

void setup() {
  SD.begin(chipSelect);                                  //Initialize SD card
  pinMode(lightSensor, INPUT);                           //Set lightSensor as an input
}

void loop() {
  File dataFile = SD.open("LightT.csv", FILE_WRITE);     //open file (if the filename doesn't exist this will create a new one)
  int light = analogRead(lightSensor);                   //read the light level 
  dataFile.print(millis());                              //write the time (in milliseconds) since the device started up. 
  dataFile.print(",");                                   //write a comma
  dataFile.println(light);                               //write the X position of the joystick to the file and move to the next line
  dataFile.close();                                      //close file (data won't be written on card until file is closed)
}

/*

Activities:
1) Open LightT.csv in Excel and look at the time-stamps. What is the time between samples? What is the sampling rate in Hz?
2) Why is the time between samples not constant?
3) Modify the code to log timestamps in seconds instead of ms
4) (Advanced) Also print the time-stamp and light-level on the screen as you log

*/
