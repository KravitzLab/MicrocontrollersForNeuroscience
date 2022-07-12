/**************************************************************************
  Joystick and NeoPixels on Adafruit PyGamer
  June 2022
  Cammi Rood & Kevin Chavez Lopez
 **************************************************************************/

int JoystickY = A10;                                      
int JoystickX = A11;
int pix = 8;
int numPix = 5;

int delayVal = 100;

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels(numPix, pix, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  pixels.begin();
  pixels.setBrightness(50);
  pinMode(JoystickY, INPUT);
  pinMode(JoystickX, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int valY = analogRead(JoystickY);
  int valX = analogRead(JoystickX);
  
  //The meaning of the digits in the parenthesis below:
  //First digit represents the pixel# from 0 to 4.
  //The following digits change the color values in a R-G-B scale. Min=0 Max=255
  pixels.setPixelColor(2, 0, 100, 0);
  pixels.show();
  if (valY < 400) {
    pixels.setPixelColor(1, 50, 50, 0);
    pixels.show();
    pixels.clear();
  } else if (valY > 600) {
    pixels.setPixelColor(3, 0, 50, 50);
    pixels.show();
    pixels.clear();
  } 
  
  if (valX < 400) {
    pixels.setPixelColor(0, 100, 0, 0);
    pixels.show();
    pixels.clear();
  } else if (valX > 600) {
    pixels.setPixelColor(4, 0, 0, 100);
    pixels.show();
    pixels.clear();
  }
}
