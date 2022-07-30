/*
  Example 3.2 - NeoPixel Button Press

  This code uses an externally wired button to control the built-in
  NeoPixel RGB LEDs using "if" statements.

  created Jun 2022
  by Cammi Rood
*/

// Reference the NeoPixel Library
#include <Adafruit_NeoPixel.h>

#define button 2                                                  // Choose a button to control the lights
#define pix 8                                                     // The PyGamer pin connected to the NeoPixels = 8
#define numPix 5                                                  // Number of NeoPixels on the strip

Adafruit_NeoPixel pixels(numPix, pix, NEO_GRB + NEO_KHZ800);     //Start the "pixels" object

void setup() {
  pixels.begin();                                                // Initiates the NeoPixel object
  pixels.setBrightness(50);                                      // Brightness range goes from 0-255
  pinMode(button, INPUT);                                        // Set button to be an input
}

void loop() {
  if (digitalRead(button) == LOW) {                              // If button is pressed...
    pixels.setPixelColor(2, 0, 50, 50);                          // Light up declared pixels 
    pixels.show();                                               // pixels.show() sends the command to the Neopixels
  } else {                                                       // Otherwise...
    pixels.clear();                                              // Turn off all pixels
    pixels.show();                                               // pixels.show() sends the command to the Neopixels
  }
}


/*

  Activity:
  1) Change the code (hint: void loop) so that pressing the button will light up all neopixels instead of just one.

*/
