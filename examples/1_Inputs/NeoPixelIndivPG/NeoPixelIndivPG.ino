#include <Adafruit_NeoPixel.h> // This tells Arduino to get information from the NeoPixel library
int pin = 8; // NeoPixel output pin on PyGamer is 8
int pix = 5; // Number of NeoPixels on PyGamer is 5

Adafruit_NeoPixel pixels(pix, pin, NEO_GRB + NEO_KHZ800);
// Library pixelVariable(number of pixels, pin number, NeoPixel type)

int delayVal = 500; // Variable in ms

void setup() { // put your setup code here, to run once:
  pixels.begin(); // Initializes the NeoPixel object (REQUIRED)
  pixels.setBrightness(50); //Brightness ranges from 0 (off) to 255 (brightest)
}

void loop() { // put your main code here, to run repeatedly:
  pixels.clear(); // Set all pixel colors to 'off' 
  // below: pixelVariable.setPixelColor(n, R, G, B)
    // n = the pixel number, starting from 0, so if we light individual pixels, we use n = 0-4
  pixels.setPixelColor(0, 200, 0, 0); // Sets farthest left 
  pixels.setPixelColor(1, 100, 100, 0);
  pixels.setPixelColor(2, 0, 200, 0);
  pixels.setPixelColor(3, 0, 100, 100);
  pixels.setPixelColor(4, 0, 0, 200);
  pixels.show();
  delay(delayVal);
}
