/**************************************************************************
  Example 2.2_ Read from the accelerometer on the Adafruit PyGamer
  June 2022
  Lex Kravitz & Cammi Rood
 **************************************************************************/

//Include libraries
#include <Wire.h>
#include <Adafruit_LIS3DH.h>

Adafruit_LIS3DH lis = Adafruit_LIS3DH();                //Start accelerometer object

void setup(void) {
  Serial.begin(9600);                                   //Start Serial connection to computer
  lis.begin(0x19);                                      //Initialize accelerometer on port 0x19
}

void loop() {
  lis.read();                                           //Read accelerometer data
  int x = lis.x;                                        //Store x acceleration in a variable called "x"
  int y = lis.y;                                        //Store y acceleration in a variable called "y"
  int z = lis.z;                                        //Store z acceleration in a variable called "z"

  Serial.print("X-value:");                             //Print x value to the serial monitor/plotter
  Serial.print(x);
  Serial.print(",");
  Serial.print("Y-value:");                             //Print y value to the serial monitor/plotter
  Serial.print(y);      
  Serial.print(",");
  Serial.print("Z-value:");                             //Print z value to the serial monitor/plotter
  Serial.println(z);
  delay(50);
}
