/*
  Project 1.2: While loops

  This code demonstrates the use of "while" loops
  to control NeoPixels built-in to the PyGamer based on the button state.

  created Jun 2022
  by Cammi Rood and Lex Kravitz
*/

#include <Adafruit_NeoPixel.h>                                    // Initialize libraries

#define button 3                                                  // Assign the name "button" to pin 3

int pin = 8;                                                      // NeoPixel output pin on PyGamer is 8
int pix = 5;                                                      // Number of NeoPixels on PyGamer is 5
Adafruit_NeoPixel pixels(pix, pin, NEO_GRB + NEO_KHZ800);         // Set up neopixels

void setup() {
  pixels.begin();                                                 // Initializes the NeoPixel object
  pinMode (button, INPUT);                                        // Set button to be an input
}

void loop() { 
  /* ************************** While loops ******************************
     While loops will continue to repeat as long as the condition
     in the loop argument remains true
  */

  while (digitalRead(button) == LOW) {                            // WHILE button is pressed
    pixels.setPixelColor(2, 0, 20, 20);                           // Turn 3rd pixel on blue/green
    pixels.show();                                                // Display neopixel
    delay (50);                                                   // Delay for 50ms
    pixels.clear();                                               // Turn off all pixels
    pixels.show();                                                // Display neopixel
    delay (50);                                                   // Delay for 50ms
  }
}

/*

  Activity:
  
  1) Change the loop to pulse the pixel when the button is NOT pushed

*/
