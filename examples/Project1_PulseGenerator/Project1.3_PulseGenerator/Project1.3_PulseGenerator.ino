/*
   Day 1 Project - build a simple pulse generator for controlling optogenetic stimulation!

   created Jun 2022
   by Lex Kravitz and Kevin Chavez
*/

#include <Adafruit_NeoPixel.h>                                  // Include Neopixel library

#define button 3                                                // Assign the name "button" to pin 3
int pin = 8;                                                    // NeoPixel output pin on PyGamer is 8
int pix = 5;                                                    // Number of NeoPixels on PyGamer is 5
Adafruit_NeoPixel pixels(pix, pin, NEO_GRB + NEO_KHZ800);       // Set up neopixels

int period = 200;                                               // This is our pulsing period, start at 200ms, or 5Hz

void setup() {
  Serial.begin();                                               // Open the serial connection
  pixels.begin();                                               // Initializes the NeoPixel object
  pinMode (button, INPUT);                                      // Set button to be an input
}

void loop() {
  //Pulse pixel 3 at the set period
  pixels.setPixelColor(2, 0, 20, 20);                           // Turn 3rd pixel on blue/green
  pixels.show();                                                // Display neopixel
  delay (period/2);                                             // Delay for 50ms
  pixels.clear();                                               // Turn off all pixels
  pixels.show();                                                // Display neopixel
  delay (period/2);                                             // Delay for 50ms

  ///////////////////////////////////////////////////////
  // Task 1: Use two "if statements" to update the blinking 
  // frequency using the joystick.
  ///////////////////////////////////////////////////////
  Serial.println(period);                                       //Send pulsing frequency to the Serial Monitor (good for debugging)
  
  ///////////////////////////////////////////////////////
  // Task 2: When the delay is set < 0 the program will crash. 
  // How can you stop this from happening?
  ///////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////
  // Task 3: Use a "while loop" to only pulse when the button 
  // on pin 3 is pressed (hint: See the Project 1.2 example)
  ///////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////
  // Task 4: Use a "for loop" to send 20 pulses when the 
  // button on pin 3 is pressed 
  ///////////////////////////////////////////////////////
}
