/**************************************************************************

 **************************************************************************/

//We need libraries
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>

//We need these pin definitions for SPI
#define TFT_CS        44 // PyBadge/PyGamer display control pins: chip select
#define TFT_RST       46 // Display reset
#define TFT_DC        45 // Display data/command select
#define TFT_BACKLIGHT 47 // Display backlight pin

//Start screen object
Adafruit_ST7735 tft = Adafruit_ST7735(&SPI1, TFT_CS, TFT_DC, TFT_RST);

void setup(void) {
  //Startup and clear the screen
  tft.initR(INITR_BLACKTAB);        // Initialize ST7735R screen
  tft.setRotation(1);

  //set light sensor to be an input
  pinMode(A7, INPUT);

  //turn on backlight
  pinMode(TFT_BACKLIGHT, OUTPUT);
  digitalWrite(TFT_BACKLIGHT, HIGH); // Backlight on

  //set text size
  tft.setTextSize(4);
}

void loop() {
  tft.fillScreen(ST77XX_BLACK);      // clear screen
  int lightsensor = analogRead(A7);  // read light sensor
  tft.setCursor(10, 10);             // set cursor position 
  tft.print(lightsensor);            // print light sensor reading
  delay (200);                       // delay for 200ms
}
