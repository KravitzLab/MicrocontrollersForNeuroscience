/**************************************************************************
  NeoPixel? on Adafruit PyGamer
  June 2022
  Lex Kravitz
 **************************************************************************/

#include <Adafruit_NeoPixel.h>                                  //Include Neopixel library

//Set up Neopixels
int pin = 8;                                                    // NeoPixel output pin on PyGamer is 8
int pix = 5;                                                    // Number of NeoPixels on PyGamer is 5
Adafruit_NeoPixel pixels(pix, pin, NEO_GRB + NEO_KHZ800);       // Start Neopixel object
 
int frequency = 10;                                             // This is our pulsing frequency, start at 10Hz

void setup() { 
  pixels.begin();                                               // Initializes the NeoPixel object (REQUIRED)
}

void loop() {  
  //Pulse Neopixel 3 at the set frequency   
    pixels.setPixelColor(2, 0, 50, 50);                         // This function includes the arguments (pixelnumber, R, G, B)
    pixels.show();                                              // Sends the color to the code
    delay(1/frequency*2);                                       // Keep pixel lit for the duration of the pulse
    pixels.setPixelColor(2, 0, 50, 50);                         // This function includes the arguments (pixelnumber, R, G, B)
    pixels.show();                                              // Sends the color to the code
    delay(1/frequency*2);                                       // Adds a delay so the light movement is visible
}
