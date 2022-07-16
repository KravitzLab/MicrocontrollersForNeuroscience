/*
The 2nd simplest SD card example ever!
Lex Kravitz
June 2022
*/

#include <SPI.h>                                       //Include SPI library
#include <SD.h>                                        //Include SD library
const int chipSelect = 4;                              //Set "Chip Select" pin for SD card on SPI bus

void setup() {
  SD.begin(chipSelect);                                //Initialize SD card
  pinMode(A7, INPUT);
}

void loop() {
  File dataFile = SD.open("light.csv", FILE_WRITE);    //open file (if the filename doesn't exist this will create a new one)
  int light = analogRead(A7);                          //read the light level from A7
  dataFile.println(light);                             //write the X position of the joystick to the file and move to the next line
  dataFile.close();                                    //close file (data won't be written on card until file is closed)
  delay(100);                                          //delay 100ms (this results in a 10Hz sampling rate of the light level)
}
