/*
  Example 1.4: Blink one Neopixel
  
  We blinked the red LED, and "blinked" the speaker,
  now let's blink the Neopixels!
  
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
  pixels.setPixelColor(0, 0, 0, 0);                               // Turn pixel off
  pixels.show();                                                  // Call pixels.show to light up the pixels (this will "light" them up with (0,0,0) or turn them off
  delay(1000);                                                    // wait for a second
}

/*

Activities:
1. Can you blink the third pixel blue at 5Hz?
2. Can you alternate between blinking the first and fifth pixels red at 1Hz?
3. Can you turn each pixel on and off to light up pixels from 1 to 5 in order?

*/
