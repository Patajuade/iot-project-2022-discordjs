#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoMatrix.h>
#include <gamma.h>
#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <SoftwareSerial.h> //for esp
#include <ArduinoJson.h> //for esp

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
//nodeMCU
SoftwareSerial nodemcu(5, 3);

int delayVal = 5000;         // Delay in milliseconds between changing displayed number
int randNum;                 // Variable to store the random number

// Define pixel arrays used to display numbers
int numDefault[] = {0,1,2,5,6,7,8,10,13,15,16,18,21,23,24,25,26,29,31,32,34,37,39,40,42,45,47,48,50,53,55,56,57,58,61,62,63};
int num1[] = {0,1,2,7,8,13,15,16,18,23,24,29,31,32,34,39,40,45,47,48,50,55,56,61,62,63};
int num2[] = {0,1,2,5,6,7,10,13,15,16,18,21,24,25,26,29,31,32,34,39,40,45,47,48,50,55,56,57,58,61,62,63};
int num3[] = {0,1,2,5,6,7,8,13,15,16,18,23,24,25,26,29,31,32,34,39,40,45,47,48,50,55,56,57,58,61,62,63};
int num4[] = {0,1,2,7,8,13,15,16,18,23,24,25,26,29,31,32,34,37,39,40,42,45,47,48,50,53,55,56,58,61,62,63};
int num5[] = {0,1,2,5,6,7,8,13,15,16,18,23,24,25,26,29,31,32,34,37,42,45,47,48,50,53,56,57,58,61,62,63};
int num6[] = {0,1,2,5,6,7,8,10,13,15,16,18,21,23,24,25,26,29,31,32,34,37,42,45,47,48,50,53,56,57,58,61,62,63};
int num7[] = {0,1,2,7,8,13,15,16,18,23,24,29,31,32,34,39,40,45,47,48,50,55,56,58,57,61,62,63};
int num8[] = {0,1,2,5,6,7,8,10,13,15,16,18,21,23,24,25,26,29,31,32,34,37,39,40,42,45,47,48,50,53,55,56,57,58,61,62,63};
int num9[] = {0,1,2,5,6,7,8,13,15,16,18,23,24,25,26,29,31,32,34,37,39,40,42,45,47,48,50,53,55,56,57,58,61,62,63};
int num10[] = {2,5,6,7,8,10,13,18,21,23,24,26,29,34,37,39,40,42,45,50,53,55,56,57,58,61};
int num11[] = {2,7,8,13,18,23,24,29,34,39,40,45,50,55,56,61};
int num12[] = {2,5,6,7,10,13,18,21,24,25,26,29,34,39,40,45,50,55,56,57,58,61};
int num13[] = {2,5,6,7,8,13,18,23,24,25,26,29,34,39,40,45,50,55,56,57,58,61};
int num14[] = {2,7,8,13,18,23,24,25,26,29,34,37,39,40,42,45,50,53,55,56,58,61};
int num15[] = {2,5,6,7,8,13,18,23,24,26,29,34,37,42,45,50,53,56,57,58,61};
int num16[] = {2,5,6,7,8,10,13,18,21,23,24,26,29,34,37,42,45,50,53,56,57,58,61};
int num17[] = {2,7,8,13,18,23,24,29,34,39,40,45,50,55,56,58,57,61};
int num18[] = {2,5,6,7,8,10,13,18,21,23,24,25,26,29,34,37,39,40,42,45,50,53,55,56,57,58,61};
int num19[] = {2,5,6,7,8,13,18,23,24,26,29,34,37,39,40,42,45,50,53,55,56,57,58,61};
int num20[] = {0,1,2,5,6,7,8,10,15,16,21,23,24,26,29,30,31,34,37,39,40,42,45,50,53,55,56,57,58,61,62,63};


// Define sizes of arrays used above
int pixelCountDefault = 38;
int pixelCount = 64;
int sizeNum1 = sizeof num1 / sizeof num1[0];
int sizeNum2 = sizeof num2 / sizeof num2[0];
int sizeNum3 = sizeof num3 / sizeof num3[0];
int sizeNum4 = sizeof num4 / sizeof num4[0];
int sizeNum5 = sizeof num5 / sizeof num5[0];
int sizeNum6 = sizeof num6 / sizeof num6[0];
int sizeNum7 = sizeof num7 / sizeof num7[0];
int sizeNum8 = sizeof num8 / sizeof num8[0];
int sizeNum9 = sizeof num9 / sizeof num9[0];
int sizeNum10 = sizeof num10 / sizeof num10[0];
int sizeNum11 = sizeof num11 / sizeof num11[0];
int sizeNum12 = sizeof num12 / sizeof num12[0];
int sizeNum13 = sizeof num13 / sizeof num13[0];
int sizeNum14 = sizeof num14 / sizeof num14[0];
int sizeNum15 = sizeof num15 / sizeof num15[0];
int sizeNum16 = sizeof num16 / sizeof num16[0];
int sizeNum17 = sizeof num17 / sizeof num17[0];
int sizeNum18 = sizeof num18 / sizeof num18[0];
int sizeNum19 = sizeof num19 / sizeof num19[0];
int sizeNum20 = sizeof num20 / sizeof num20[0];


void setup() {
  //NodeMCU setup
  Serial.begin(115200);
  nodemcu.begin(115200);
  delay(1000);
  Serial.println("Program started");

  //Matrix setup
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pinMode(tiltPin, INPUT); // INITIALIZE tilts pin
  pixels.show();
}

void sendNumberToNodeMCU(int num){
   StaticJsonBuffer<1000> jsonBuffer;
      JsonObject& data = jsonBuffer.createObject();

      Serial.print("Result : ");
      Serial.println(num);

      //Assign collected data to JSON Object
      data["result"] = num;

      //Send data to NodeMCU
      data.printTo(nodemcu);
      jsonBuffer.clear();

      //delay(2000);
}

void loop() {
 
  //loop listening to the tilt's state
  int tiltSensorValue = digitalRead(tiltPin);
  delay(100);
  randNum = random(1,21);
  
    if(tiltSensorValue==LOW){
     sendNumberToNodeMCU(randNum);
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
      else if (randNum==7){
        for (int i = 0; i < sizeNum7; i++){
          pixels.setPixelColor(num7[i],255,0,0);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }
      else if (randNum==8){
        for (int i = 0; i < sizeNum8; i++){
          pixels.setPixelColor(num8[i],255,0,0);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }
      else if (randNum==9){
        for (int i = 0; i < sizeNum9; i++){
          pixels.setPixelColor(num9[i],255,0,0);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }
      else if (randNum==10){
        for (int i = 0; i < sizeNum10; i++){
          pixels.setPixelColor(num10[i],255,0,0);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }
      else if (randNum==11){
        for (int i = 0; i < sizeNum11; i++){
          pixels.setPixelColor(num11[i],255,0,0);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }
      
      else if (randNum==12){
        for (int i = 0; i < sizeNum12; i++){
          pixels.setPixelColor(num12[i],255,0,0);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }
      
      else if (randNum==13){
        for (int i = 0; i < sizeNum13; i++){
          pixels.setPixelColor(num13[i],255,0,0);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }
      
      else if (randNum==14){
        for (int i = 0; i < sizeNum14; i++){
          pixels.setPixelColor(num14[i],255,0,0);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }
      
      else if (randNum==15){
        for (int i = 0; i < sizeNum15; i++){
          pixels.setPixelColor(num15[i],255,0,0);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }
      
      else if (randNum==16){
        for (int i = 0; i < sizeNum16; i++){
          pixels.setPixelColor(num16[i],255,0,0);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }
      
      else if (randNum==17){
        for (int i = 0; i < sizeNum17; i++){
          pixels.setPixelColor(num17[i],255,0,0);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }
      
      else if (randNum==18){
        for (int i = 0; i < sizeNum18; i++){
          pixels.setPixelColor(num18[i],255,0,0);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }
      else if (randNum==19){
        for (int i = 0; i < sizeNum19; i++){
          pixels.setPixelColor(num19[i],255,0,0);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }
      else if (randNum==20){
        for (int i = 0; i < sizeNum20; i++){
          pixels.setPixelColor(num20[i],255,0,0);
          pixels.show(); 
          }
          delay(delayVal);
         for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(off)); 
          pixels.show(); 
         }
      }  
    }
    
    else{
     for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(off)); 
    pixels.show();
    } 
  //end of loop
}
}


void wipe(){
    for(int i=0;i<NUMPIXELS;i++){
       pixels.setPixelColor(i, pixels.Color(0,0,0)); 
       }
}
