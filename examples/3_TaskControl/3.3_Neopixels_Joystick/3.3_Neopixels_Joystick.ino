/*
  Example 3.3: Controlling the NeoPixels with the Joystick

  This code read the X position from the PyGamer's built-in joystick
  to control which NeoPixels are lit. 

  created Jun 2022
  by Cammi Rood & Kevin Chavez Lopez
*/

#include <Adafruit_NeoPixel.h>                                    // We need to include the Adafruit_NeoPixel library
#define PIN 8                                                     // The Neopixels are on pin 8 (on different boards this might be different)
#define NUMPIXELS 5                                               // We have 5 Neopixels
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);   // Define the "pixels" object

#define JoystickX A11                                             // Assign the variable label JoystickX to pin A11  

void setup() {
  pixels.begin();                                                 // Initialize "pixels" object
  pinMode(JoystickX, INPUT);                                      // Set JoystickX as an input
}

void loop() {
  int valX = analogRead(JoystickX);                               // Read JoystickX position 
  pixels.clear();                                                 // Clear all pixels
  pixels.setPixelColor(2, 5, 5, 5);                               // Set the 3rd pixel (index = 2) to the RGB color (5, 5, 5) - a dim white
  if (valX < 25) {                                                // If Joystick is all the way to the left...
    pixels.setPixelColor(0, 5, 5, 5);                             // Light up left-most pixel in dim white (5, 5, 5)
  }
  if (valX < 200) {                                               // If Joystick is a little to the left...
    pixels.setPixelColor(1, 5, 5, 5);                             // Light up 2nd pixel in dim white (5, 5, 5)
  }
  if (valX > 775) {                                               // If Joystick is a little to the right...
    pixels.setPixelColor(3, 5, 5, 5);                             // Light up 4th pixel in dim white (5, 5, 5)
  }
  if (valX > 1000) {                                              // If Joystick is all the way to the right...
    pixels.setPixelColor(4, 5, 5, 5);                             // Light up 5th pixel in dim white (5, 5, 5)
  }
  pixels.show();                                                  // show pixels (don't forget this line when using NeoPixels!)
}

/*

  Activities:
  1) Make the left two Neopixels light up in red, and the right two light up in blue when activated
  2) Change *one character* in the above code to change the Neopixels with the Y instead of X position
  3) Change a different *single character* in the above code to light the Neopixels with the light sensor 
  3) (Advanced) Modify this code to control the NeoPixels with the accelerometer instead of the joystick

*/
