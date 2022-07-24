/*
  Example 3.3: Joystick and NeoPixels
  
  This code uses the PyGamer's built-in joystick to read X and Y-values
  to turn on specific NeoPixels. Based on the joystick's position, one
  or two individual NeoPixels will turn on.
  
  created Jun 2022
  by Cammi Rood & Kevin Chavez Lopez
*/

int JoystickX = A11;
int pix = 8;
int numPix = 5;

int delayVal = 100;

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels(numPix, pix, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  pixels.begin();
  pinMode(JoystickX, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int valX = analogRead(JoystickX);
  
  //The meaning of the digits in the parenthesis below:
  //First digit represents the pixel# from 0 to 4.
  //The following digits change the color values in a R-G-B scale. Min=0 Max=255
  pixels.clear();
  pixels.setPixelColor(2, 10, 10, 10);  
  if (valX < 200) {
    pixels.setPixelColor(0, 10, 10, 10);
  }
  if (valX < 400) {
    pixels.setPixelColor(1, 10, 10, 10);
  }
  if (valX > 600) {
    pixels.setPixelColor(3, 10, 10, 10);
  }
  if (valX > 800) {
    pixels.setPixelColor(4, 10, 10, 10);
  }
  pixels.show();
}

/*

Activities:
1) Make the left two Neopixels light up in red, and the right two light up in blue when activated
2) Change *one character* in the above code to change the Neopixels with the Y instead of X position
3) (Advanced) Modify this code to control the NeoPixels with the accelerometer instead of the light meter

*/
