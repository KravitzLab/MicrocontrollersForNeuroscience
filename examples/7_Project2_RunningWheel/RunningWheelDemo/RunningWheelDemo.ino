/**************************************************************************
  Running wheel demo on Adafruit PyGamer
  June 2022
  Lex Kravitz
 **************************************************************************/

//We need libraries
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>

//We need these pin definitions for SPI communication with the screen
#define TFT_CS        44 // PyBadge/PyGamer display control pins: chip select
#define TFT_RST       46 // Display reset
#define TFT_DC        45 // Display data/command select
#define TFT_BACKLIGHT 47 // Display backlight pin

//Start screen object
Adafruit_ST7735 tft = Adafruit_ST7735(&SPI1, TFT_CS, TFT_DC, TFT_RST);

//Initialize variables that we'll need to use later
int wheelcounts = 0;
bool countready = true;

void setup(void) {
  //setup screen one time in the setup loop
  tft.initR(INITR_BLACKTAB);        // Initialize ST7735R screen
  tft.setRotation(1);
  tft.setTextSize(4);
  tft.fillScreen(ST77XX_BLACK);      // clear screen
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(5, 20);             // set cursor position
  tft.println("Count:");            // print light sensor reading
  tft.setTextColor(ST77XX_YELLOW);
  tft.setCursor(5, 52);             // set cursor position
  tft.println(wheelcounts);

  //set joystick X pin to be an input and read it to get a baseline reading
  pinMode(3, INPUT);

  //turn on backlight
  pinMode(TFT_BACKLIGHT, OUTPUT);
  analogWrite(TFT_BACKLIGHT, 10); // Backlight on dim (less annoying than on full brightness)
}

void loop() {
  //read the x position of the joystick
  int x = digitalRead(3);  //this will be ~510 in the resting center position and ~1023 when fully pushed right

  //if wheel moves the joystick, add 1 to wheelcounts and update the screen
  if (x == true and countready == true) {
    wheelcounts++;
    countready = false;
    tft.fillRect(0, 52, 400, 32, ST77XX_BLACK);
    tft.setCursor(5, 52);             // set cursor position
    tft.println(wheelcounts);
  }

  //set countready to true when joystick returnsto the center (this stops the counter from triggering multiple times per movement)
  if (x == false) {
    countready = true;
  }
}
