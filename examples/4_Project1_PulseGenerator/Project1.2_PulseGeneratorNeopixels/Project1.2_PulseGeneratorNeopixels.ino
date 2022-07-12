/*
   Day 1 Project - build a simple function generator for controlling optogenetic stimulation!
   Lex Kravitz
   alexxai@wustl.edu
   June 2022
*/

#include <Adafruit_NeoPixel.h>                                  //Include Neopixel library

//Set up Neopixels
int pin = 8;                                                    // NeoPixel output pin on PyGamer is 8
int pix = 5;                                                    // Number of NeoPixels on PyGamer is 5
Adafruit_NeoPixel pixels(pix, pin, NEO_GRB + NEO_KHZ800);       // Start Neopixel object
 
int freq = 5;                                                   // This is our pulsing frequency, start at 5Hz

void setup() {
  pixels.begin();                                               // Initializes the NeoPixel object (REQUIRED)
}

void loop() {
  Serial.println(freq);

  //Pulse Neopixel 3 at the set frequency
  pixels.setPixelColor(2, 0, 50, 50);                           // This function includes the arguments (pixelnumber, R, G, B)
  pixels.show();                                                // Sends the color to the code
  delay(1000 / freq / 2);                                       // Delay for light on period
  pixels.setPixelColor(2, 0, 0, 0);                             // This function includes the arguments (pixelnumber, R, G, B)
  pixels.show();                                                // Sends the color to the code
  delay(1000 / freq / 2);                                       // Delay for light off period
  
    
  if (analogRead(A10) < 600) {                                  // If joystick is held up
    freq++;                                                     // Increase pulsing frequency
  }

  if (analogRead(A10) > 400) {                                  // If joystick is held down
    freq--;                                                     // Decrease pulsing frequency
  }
}
