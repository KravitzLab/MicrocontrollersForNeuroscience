/**************************************************************************
  Learn for and while loops with Adafruit PyGamer
  June 2022
  Cammi Rood and Lex Kravitz
 **************************************************************************/

#include <Adafruit_NeoPixel.h>                                    //Initialize libraries

Adafruit_NeoPixel pixels(pix, pin, NEO_GRB + NEO_KHZ800);         //Set up neopixels
int pin = 8;                                                      // NeoPixel output pin on PyGamer is 8
int pix = 5;                                                      // Number of NeoPixels on PyGamer is 5

void setup() {
  pixels.begin();                                                 // Initializes the NeoPixel object
  pinMode (2, INPUT);                                             // Set pin 2 as an input for the button
}

void loop() { // put your main code here, to run repeatedly:
  /* ************************** While loops ******************************
     while loops run WHILE the condition within the parantheses is being met.
     In this case, while the button is pushed, the first pixel light up blue.
     When the button is NOT pushed, the pixel will light up red */

  while (digitalRead (2) == HIGH) {
    pixels.setPixelColor(0, 0, 0, 50);
    pixels.show(); // Sends the color to the code
  }
  pixels.setPixelColor(0, 50, 0, 0);
  pixels.show(); // Sends the color to the code

  /* ************************** For loops ******************************
     for loops run UNTIL the condition within the parantheses is met.
     In this case, we will blink the second pixel green 20x
     int i = 0 initializes a variable "i" at 0
     i <= 20 says the loop will repeat 20x (until i = 19) -
     i++ tells the board to increment i by 1 each iteration
     Experiment with changing these values! */
  
  for (int i = 0; i <= 20; i++) {
    pixels.setPixelColor(1, 0, 20, 0);                            //Set 2nd pixel to be green
    pixels.show();                                                //Display settings on neopixel
    delay (200);                                                  //Delay for 200ms
    pixels.clear();                                               //Turn off all pixels
    pixels.show();                                                //Display settings on neopixel
    delay (200);                                                  //Delay for 200ms
  }
}
