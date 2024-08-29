// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        3

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 45 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 10 // Time (in milliseconds) to pause between pixels

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void ua_flag() {
  pixels.clear(); // Set all pixel colors to 'off'
  auto blue = pixels.Color(0, 0, 255);
  auto yellow = pixels.Color(128, 128, 0);
  pixels.fill(blue, 7 + 7, 7 + 10 + 7);
  pixels.fill(yellow, 0, 7 + 7);
  pixels.fill(yellow, 7 + 14 + 10 + 7, 7);

  pixels.show();
}

void set_left(uint32_t color) {
  pixels.fill(color, 0, 3);
  pixels.fill(color, 7 + 14 + 5, 5 + 14);
  pixels.show();
}

void set_right(uint32_t color) {
  pixels.fill(color, 4, 3 + 14 + 5);
  pixels.show();
}

void hazard_flash() {
  auto orange = pixels.Color(255, 100, 0);
  auto off = pixels.Color(0, 0, 0);
  const auto pause = 50;
  pixels.clear();
  for (int i=0; i<4; i++) {
    set_left(orange);
    delay(pause);
    set_left(off);
    delay(pause);
  }
  for (int i=0; i<4; i++) {
    set_right(orange);
    delay(pause);
    set_right(off);
    delay(pause);
  }
}

void loop() {
  hazard_flash();
  /*ua_flag();*/
  /*delay(2000);*/

  /*pixels.clear(); // Set all pixel colors to 'off'*/

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  /*for(int i=0; i<NUMPIXELS; i++) { // For each pixel...*/
  /**/
  /*  // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255*/
  /*  // Here we're using a moderately bright green color:*/
  /*  pixels.setPixelColor(i, pixels.Color(0, 0, 255));*/
  /**/
  /*  pixels.show();   // Send the updated pixel colors to the hardware.*/
  /**/
  /*  delay(DELAYVAL); // Pause before next pass through loop*/
  /*  pixels.setPixelColor(i, pixels.Color(0, 0, 0));*/
  /*}*/
}
