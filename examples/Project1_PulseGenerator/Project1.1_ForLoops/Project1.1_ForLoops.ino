/*
  Project 1.1: Review for loops

  This code demonstrates the use of "for" loops 
  to control NeoPixels built-in to the PyGamer.

  created Jun 2022
  by Cammi Rood and Lex Kravitz
*/

#include <Adafruit_NeoPixel.h>                                    //Initialize libraries

int pin = 8;                                                      // NeoPixel output pin on PyGamer is 8
int pix = 5;                                                      // Number of NeoPixels on PyGamer is 5
Adafruit_NeoPixel pixels(pix, pin, NEO_GRB + NEO_KHZ800);         // Set up neopixels

void setup() {
  pixels.begin();                                                 // Initializes the NeoPixel object
}

void loop() { 
  /* ************************** For loops ******************************
     for loops run UNTIL the condition within the parantheses is met.
     In this case, we will blink the second pixel green 20x
     int i = 0 initializes a variable "i" at 0
     i <= 4 says the loop will repeat 5x (until i = 5) 
     i++ tells the board to increment i by 1 each iteration
     Experiment with changing these values! */

  for (int i = 0; i <= 4; i++) {
    pixels.setPixelColor(2, 0, 20, 20);                           // Turn 3rd pixel on blue/green
    pixels.show();                                                // Display neopixel
    delay (200);                                                  // Delay for 200ms
    pixels.clear();                                               // Turn off all pixels
    pixels.show();                                                // Display neopixel 
    delay (200);                                                  // Delay for 200ms
  }
  delay (2000);                                                   // Delay for 2s between pulse trains
}
