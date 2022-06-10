// Neopixel pattern generator
// By Mike Cook August 2015

#include <Adafruit_NeoPixel.h>
#define PIN   6 // pin connected to the NeoPixels
#define NUMPIXELS      49 // number of LEDs in a 7 by 7 array

// pattern is LED numbers followed by a 255 to indicate the pattern end
// this is put into porgram memory and can be as long as you like
const PROGMEM uint8_t pattern[] = { 23,22,17,255, 1,5,7,12,42,13,255,
                                       18,14,10,11,255, 14,22,18,19,12,255,
                                       16,47,23,35,1,42,16,8,0,255};
                                       
int patternLength = sizeof(pattern);
int patternSpeed = 1000; // change every second
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
   pixels.begin(); // This initializes the NeoPixel library.
   wipe();
   pixels.show();
}

void loop() {
  int point = 0; // point in the pattern array
  int led = 0;
  while(point <= patternLength) { // read out the pattern
   led = pgm_read_byte_near(&pattern[point]);
   point ++; // increment next point in pattern
   if(led != 255) {
      pixels.setPixelColor(led, pixels.Color(0,128,0)); // note green fixed colour
   }
   else {
     pixels.show();
     delay(patternSpeed); // pause
     wipe(); // clear out pixels
     }
  }
}

void wipe(){
    for(int i=0;i<NUMPIXELS;i++){
       pixels.setPixelColor(i, pixels.Color(0,0,0)); 
       }
}
