/*
  Example 1.3: Light a single Neopixel

  We blinked the red LED, and "blinked" the speaker, now let's blink the Neopixels!

  This code uses the built-in NeoPixels, a multi-color LED that has its own controller chip.
  This allows you to select individual LEDs and change their colors using only one digital pin.

  This example utilizes libraries and code from Adafruit.
  We encourage users to support open-source hardware and software!

  created Jun 2022
  by Lex Kravitz, Cammi Rood, and Kevin Chávez López

*/

#include <Adafruit_NeoPixel.h>                                    // We need to include the Adafruit_NeoPixel library
#define PIN 8                                                     // The Neopixels are on pin 8 (on different boards this might be different)
#define NUMPIXELS 5                                               // We have 5 Neopixels
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);   // Define the "pixels" object

void setup() {
  pixels.begin();                                                 // Initialize "pixels" object
}

void loop() {
  /* pixels.setPixelColor(n, r, g, b) is a function that can be used to set the color of each NeoPixel on the PyGamer.  Useage:
    n  Pixel index, from 0 to 4 (5 pixels in total)
    r Red brightness, 0 = minimum (off), 255 = maximum.
    g Green brightness, 0 = minimum (off), 255 = maximum.
    b Blue brightness, 0 = minimum (off), 255 = maximum.
  */
  pixels.setPixelColor(0, 20, 0, 0);                              // Turn left-most pixel on red (Experiment with changing this line! Can you change the color? The pixel?)
  pixels.show();                                                  // Call pixels.show to light up the pixels
}

/*

  Activities:
  1. Can you change the above example to light up the 2nd pixel?
  2. Can you change the pixels to blink?
  3. Can you turn on all of the LEDs at once? Can you find a more efficient way of going this?
  (hint: View the NeoPixel class reference documentation)

*/
