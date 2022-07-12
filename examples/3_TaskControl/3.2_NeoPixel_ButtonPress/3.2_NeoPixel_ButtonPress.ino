/**************************************************************************
  Example 3.2 - NeoPixel Button Press on Adafruit PyGamer
  June 2022
  Cammi Rood
 **************************************************************************/

// Reference the NeoPixel Library
#include <Adafruit_NeoPixel.h>

int button = 2;                                                  // Choose a button to control the lights
int pix = 8;                                                     // The PyGamer pin connected to the NeoPixels = 8
int numPix = 5;                                                  // Number of NeoPixels on the strip

Adafruit_NeoPixel pixels(numPix, pix, NEO_GRB + NEO_KHZ800);     //Start the "pixels" object 

void setup() {
  pixels.begin();                                                // Initiates the NeoPixel object
  pinMode(button, INPUT);                                        // Set button to be an input
}

void loop() {
  int buttonState = digitalRead(button);                         // Read the button state and store as "buttonState"
  if (buttonState == LOW) {                                      // If button is pressed...
    pixels.fill(pixels.Color(0, 50, 50));                        // Light up all pixels
    pixels.show();                                               // pixels.show() sends the command to the Neopixels
  } else {                                                       // Otherwise...
    pixels.clear();                                              // Turn off all pixels
    pixels.show();                                               // pixels.show() sends the command to the Neopixels
  }
}
