/*
  Example 3.5 - Blink the Neopixels with a for loop

  created Jul 2022
  by Cammi Rood, Kevin Chavez Lopez, and Lex Kravitz
*/

// Reference the NeoPixel Library
#include <Adafruit_NeoPixel.h>

int button = 3;                                                  // Choose a button to control the lights
int pix = 8;                                                     // The PyGamer pin connected to the NeoPixels = 8
int numPix = 5;                                                  // Number of NeoPixels on the strip

Adafruit_NeoPixel pixels(numPix, pix, NEO_GRB + NEO_KHZ800);     //Start the "pixels" object

void setup() {
  pixels.begin();                                                // Initiates the NeoPixel object
  pinMode(button, INPUT);                                        // Set button to be an input
}

void loop() {
  pixels.clear();                                                // Turn off all pixels
  pixels.show();                                                 // pixels.show() sends the command to the Neopixels
  if (digitalRead(button) == LOW) {                              // If button is pressed...

    ////////////////////////////////////////
    // Modify this for loop 
    ////////////////////////////////////////

    for (int i = 1; i < 6; i++) {
      pixels.fill(pixels.Color(0, 5, 5));                        // Light up all pixels blue/green
      pixels.show();                                             // pixels.show() sends the command to the Neopixels
      delay (200);                                               // delay 100ms
      pixels.clear();                                              // Light up all pixels
      pixels.show();                                             // pixels.show() sends the command to the Neopixels
      delay (200);                                               // delay 100ms
    }

  }
}

/*

  Activities:
  1) Change the code to blink the NeoPixels 10 times instead of 5
  2) Print the cycle of the for loop to the Serial monitor, ie: "Loop 1", "Loop 2", "Loop 3", etc
  3) Modify the for loop to randomly change the NeoPixel color each time it blinks (Hint: Google an Arduino function called "random")
  4) Run the loop 25x, set pixels.Color to (i, 0, 25 - i), and remove the pixels.clear() call so it stops blinking.  Pretty, huh?
  5) Remove the if statement so the pixels keep changing from blue-red continuously without pushing the button. Can you make the color smoothly go from blue-red-blue repeatedly?

*/
