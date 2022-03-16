#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoMatrix.h>
#include <gamma.h>
#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 6 
// how many pixels in the matrix
#define NUMPIXELS 64
#define off            0,0,0
// Tilt's pin
const int tiltPin = 7;

// how many pixels, which pin to use to send signals.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayVal = 5000;         // Delay in milliseconds between changing displayed number
int randNum;                 // Variable to store the random number

// Define pixel arrays used to display numbers
int numDefault[] = {0,1,2,5,6,7,8,10,13,15,16,18,21,23,24,25,26,29,30,31,32,34,37,39,40,42,45,47,48,50,53,55,56,57,58,61,62,63};
int num1[] = {0,1,2,7,8,13,15,16,18,23,24,29,30,31,32,34,39,40,45,47,48,50,55,56,61,62,63};
int num2[] = {0,1,2,5,6,7,10,13,15,16,18,21,24,25,26,29,30,31,32,34,39,40,45,47,48,50,55,56,57,58,61,62,63};
int num3[] = {0,1,2,5,6,7,8,13,15,16,18,23,24,25,26,29,30,31,32,34,39,40,45,47,48,50,55,56,57,58,61,62,63};

int num4[] = {0,1,2,7,8,13,15,16,18,23,24,25,26,29,30,31,32,34,37,39,40,42,45,47,48,50,53,55,56,58,61,62,63};
int num5[] = {2,3,4,10,18,19,20,28,34,35,36};
int num6[] = {2,3,4,10,18,19,20,26,28,34,35,36};


// Define sizes of arrays used above
int pixelCountDefault = 38;
int pixelCount = 64;
int sizeNum1 = sizeof num1 / sizeof num1[0];
int sizeNum2 = sizeof num2 / sizeof num2[0];
int sizeNum3 = sizeof num3 / sizeof num3[0];
int sizeNum4 = sizeof num4 / sizeof num4[0];
int sizeNum5 = sizeof num5 / sizeof num5[0];
int sizeNum6 = sizeof num6 / sizeof num6[0];


void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pinMode(tiltPin, INPUT); // INITIALIZE tilts pin
  Serial.begin(9600); //for tilt tests
  wipe();
  pixels.show();
  wipe();
}

void loop() {
 
  //loop listening to the tilt's state
  int tiltSensorValue = digitalRead(tiltPin);
  delay(100);
  //randNum = random(1,6);
  randNum = 4;
  Serial.print(randNum);
  
    if(tiltSensorValue==LOW){ 
      if (randNum==1){
        for (int i = 0; i < sizeNum1; i++){
          pixels.setPixelColor(num1[i],0,0,255);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }
      else if (randNum==2){
        for (int i = 0; i < sizeNum2; i++){
          pixels.setPixelColor(num2[i],0,255,0);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }
      else if (randNum==3){
        for (int i = 0; i < sizeNum3; i++){
          pixels.setPixelColor(num3[i],255,0,0);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }
      else if (randNum==4){
        for (int i = 0; i < sizeNum4; i++){
          pixels.setPixelColor(num4[i],255,0,0);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }
      else if (randNum==5){
        for (int i = 0; i < sizeNum5; i++){
          pixels.setPixelColor(num5[i],255,0,0);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }
      else if (randNum==6){
        for (int i = 0; i < sizeNum6; i++){
          pixels.setPixelColor(num6[i],255,0,0);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }
      
//suite des nums ici..

      
    }
    
    else{
     for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(off)); 
    pixels.show();
    } 
  //end of loop
}
}

void testnumber(){
  pixels.setPixelColor(11,255,0,0);
  pixels.setPixelColor(12,255,0,0);
  pixels.setPixelColor(13,255,0,0);
  pixels.setPixelColor(19,255,0,0);
  pixels.setPixelColor(28,255,0,0);
  pixels.setPixelColor(35,255,0,0);
  pixels.setPixelColor(44,255,0,0);
  pixels.setPixelColor(34,255,0,0);
  pixels.show();
}



void wipe(){
    for(int i=0;i<NUMPIXELS;i++){
       pixels.setPixelColor(i, pixels.Color(0,0,0)); 
       }
}
