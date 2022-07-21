/*
  Example 1.4: Blink one Neopixel
  
  We blinked the red LED, and "blinked" the speaker,
  now let's blink the Neopixels!
  
  This code uses built-in NeoPixels, a type of LED in which each LED 
  has its own chip. This allows these LEDs to be controlled individually, 
  despite only using one digital pin for multiple LEDs. 
  
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
  pixels.setPixelColor(0, 20, 0, 0);                              // Turn left-most pixel on red (Experiment with changing this line!)
  pixels.show();                                                  // Call pixels.show to light up the pixels
  delay(1000);                                                    // wait for a second
  pixels.fill(pixels.Color(0, 0, 0));                             // Turn them all off
  pixels.show();                                                  // Call pixels.show to light up the pixels (this will "light" them up with (0,0,0) or turn them off
  delay(1000);                                                    // wait for a second
}
