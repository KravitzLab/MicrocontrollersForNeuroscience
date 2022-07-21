/*
Example 5.1: The simplest SD card example ever!

This code demonstrates the use of SD cards with microcontrollers.
A text file is written to the SD card. 

created Jun 2022
by Lex Kravitz
*/

#include <SPI.h>                                       //Include SPI library
#include <SD.h>                                        //Include SD library
const int chipSelect = 4;                              //Set "Chip Select" pin for SD card on SPI bus

void setup() {
  SD.begin(chipSelect);                                //Initialize SD card
}

void loop() {
  File dataFile = SD.open("testing.txt", FILE_WRITE);  //open file (if the filename doesn't exist this will create a new one)
  dataFile.println("testing");                         //write the word "testing" to the file and move to the next line
  dataFile.close();                                    //close file (data won't be written until it is closed)
  delay(1000);                                         //delay for 1s 
}
