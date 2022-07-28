#include <Adafruit_NeoPixel.h> // This tells Arduino to get information from the NeoPixel library
int pin = 8; // NeoPixel output pin on PyGamer is 8
int pix = 5; // Number of NeoPixels on PyGamer is 5

Adafruit_NeoPixel pixels(pix, pin, NEO_GRB + NEO_KHZ800);
// Library pixelVariable(number of pixels, pin number, NeoPixel type)

int delayVal = 125; // Variable in ms

void setup() { // put your setup code here, to run once:
  pixels.begin(); // Initializes the NeoPixel object (REQUIRED)
  pixels.setBrightness(50); //Brightness ranges from 0 (off) to 255 (brightest)
}

void loop() { // put your main code here, to run repeatedly:
  // below: pixelVariable.setPixelColor(n, R, G, B)
    // n = the pixel number, starting from 0, so if we light individual pixels, we use n = 0-4

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
