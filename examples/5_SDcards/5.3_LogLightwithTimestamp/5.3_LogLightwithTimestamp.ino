/*
Example 5.3: Log light levels with a timestamp!

This code writes values from the analog light sensor to a csv file 
on an SD card with time stamps.

created Jul 2022
by Lex Kravitz
*/

#include <SPI.h>                                         //Include SPI library
#include <SD.h>                                          //Include SD library
const int chipSelect = 4;                                //Set "Chip Select" pin for SD card on SPI bus

void setup() {
  SD.begin(chipSelect);                                  //Initialize SD card
  pinMode(A7, INPUT);
}

void loop() {
  File dataFile = SD.open("LightT.csv", FILE_WRITE);     //open file (if the filename doesn't exist this will create a new one)
  int light = analogRead(A7);                            //read the light level from A7
  dataFile.print(millis());                              //write the time (in milliseconds) since the device started up - can you change this to seconds?
  dataFile.print(",");                                   //write a comma
  dataFile.println(light);                               //write the X position of the joystick to the file and move to the next line
  dataFile.close();                                      //close file (data won't be written on card until file is closed)
  delay(100);                                            //delay 100ms (this results in a 10Hz sampling rate of the light level)

  //Can you also display the light levels on the screen as you log them? 
}
