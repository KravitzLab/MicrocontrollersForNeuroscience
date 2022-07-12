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
}

void loop() {
  File dataFile = SD.open("joystick.csv", FILE_WRITE); //open file (if the filename doesn't exist this will create a new one)
  int joystick = analogRead(A11);                      //read the X position of the joystick
  dataFile.println(joystick);                          //write the X position of the joystick to the file and move to the next line
  dataFile.close();                                    //close file (data won't be written on card until file is closed)
  delay(20);                                           //delay 20ms (this results in a 50Hz sampling rate of the joystick position!)
}
