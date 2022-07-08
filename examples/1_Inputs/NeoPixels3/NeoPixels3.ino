#include <Adafruit_NeoPixel.h>

int PIN = 8;
int NUMPIXELS = 5;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int DELAYVAL = 1000;

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(50);
}

void loop() {
  pixels.clear();
  pixels.setPixelColor(0, 50, 0, 0);
  pixels.setPixelColor(1, 25, 25, 0);
  pixels.setPixelColor(2, 0, 50, 0);
  pixels.setPixelColor(3, 0, 25, 25);
  pixels.setPixelColor(4, 0, 0, 50);
  pixels.show();
  delay(DELAYVAL);
  pixels.fill(pixels.Color(0, 0, 0));
  pixels.show();
  delay(DELAYVAL);
}
