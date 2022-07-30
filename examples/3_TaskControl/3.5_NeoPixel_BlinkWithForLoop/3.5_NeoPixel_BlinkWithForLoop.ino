/*
  Example 3.5 - Neopixels with a for loop
  
  In the pixels.setPixelColor(n, R, G, B) function (line 32):
  n = the pixel number, R is the Red value, G is Green, B is Blue

  created Jul 2022
  by Cammi Rood, Kevin Chavez Lopez, and Lex Kravitz
*/

// Reference the NeoPixel Library
#include <Adafruit_NeoPixel.h>

#define button = 3;                                              // Choose a button to control the lights
#define pix = 8;                                                 // The PyGamer pin connected to the NeoPixels = 8
#define numPix = 5;                                              // Number of NeoPixels on the strip
int delayVal = 125;                                              // Set the blinking speed delay

Adafruit_NeoPixel pixels(numPix, pix, NEO_GRB + NEO_KHZ800);     //Start the "pixels" object

void setup() {
  pixels.begin();                                                // Initiates the NeoPixel object
  pixels.clear();                                                // Turn off all pixels
  pixels.show();                                                 // pixels.show() sends the command to the Neopixels
}

void loop() {
  for (int i = 0; i <= 4; i++) {
    //int i = 0 refers to the first pixel(i would be equal to 0-4)
    //i <= 4 has the for loop repeating until the fifth(i = 4) LED
    //i++ tells the board to have the i variable increase
    pixels.setPixelColor(i, 50, 0, 50); //i is equal to n
    delay(delayVal); // Adds a delay so the light movement is visible
    pixels.show(); // Sends the color to the code
    pixels.clear(); // Turns off all pixels after each loop
  }
}

/*

  Activities:
  1) Change the code to blink the NeoPixels 10 times 
  2) Print the cycle of the for loop to the Serial monitor, ie: "Loop 1", "Loop 2", "Loop 3", etc
  3) Modify the for loop to randomly change the NeoPixel color each time it blinks (Hint: Google an Arduino function called "random")
  4) (Advanced) Make the colors smoothly fade from blue red and back. 

*/
