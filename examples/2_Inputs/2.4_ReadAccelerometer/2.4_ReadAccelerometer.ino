/*
  Example 2.4: Read from the accelerometer
  
  This code reads  data from the LIS3DH 3-axis accelerometer on the PyGamer.
  Read more about this chip and the Adafruit examples here:
  https://learn.adafruit.com/adafruit-lis3dh-triple-axis-accelerometer-breakout/arduino
  
  This example utilizes libraries and code from Adafruit. 
  We encourage users to support open-source hardware and software!
  
  created Jun 2022
  by Lex Kravitz & Cammi Rood
 */

//Include libraries
#include <Wire.h>
#include <Adafruit_LIS3DH.h>

Adafruit_LIS3DH lis = Adafruit_LIS3DH();                //Start accelerometer object
int samplingPeriod = 100;                               //Set the sampling period

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
  delay(samplingPeriod);
}

/*

Activities:
1. Open the Serial Plotter to visualize the accelerometer values.  Can you move the PyGamer to independently alter the X, Y, and Z values?
2. Turn the sampling period down to 10ms and look at the data on the Serial Plotter.  What do you notice?
3. What units are the accelerometer values in? (Hint: Read from the link at the top)
4. What are some potential uses for an accelerometer in neuroscience experiments?

*/
