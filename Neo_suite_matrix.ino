#include <Adafruit_NeoPixel.h>
#include <math.h>
#include <MicroView.h>

#define PIN 6
#define PIXEL 64
int pixNum = 9;
int R = 0;
int G = 0;
int B = 0; 

Adafruit_NeoPixel strip = Adafruit_NeoPixel(64, PIN, NEO_GRB + NEO_KHZ800);

  
void setup() {
  Serial.begin(9600);    
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(100); // Initialize all pixels to 'off'
  uView.begin();
  uView.clear(PAGE);			// clear page
  uView.display();
}


void loop() {
   fadeLineLed();  
  if (Serial.available())
  {
    switch (Serial.read()){  
       case 'A': 
        pixNum=1;
       break;   
       case 'B': 
        pixNum=2;
       break;   
       case 'C': 
         fadeLineLed();   
       break;   
       case 'D': 
         fadeInLed(pixNum);
         fadeOutLed(pixNum);  
       break;   
       case 'E': 
        pixNum=9;
       break;   
    }
  }  
 int sensorValue = readCapacitivePin(A0);
 if(sensorValue>2){
   fadeInLed(pixNum);
   fadeOutLed(pixNum);   
 }

}
int decalCarre = 5;
void fadeLineLed(){
  //int randLed = floor(random()*64);
  int randLed = floor(random(0,64));
  int randNX = floor(random(2,8));
  randNX = decalCarre;
  int randDirX = floor(random(0,3))-1;
  int randDirY = floor(random(0,3))-1;;
  int randColor1 = (random(0,2));
  int randColor2 = (random(0,2));
  //randNX = min(randNX, 8-(randLed % 8)); 
  Serial.println(randNX);
  for(int i=0; i<100; i++) {
    int eccartLed = randNX-((i/100)*randNX);
    uView.clear(PAGE);
    uView.setCursor(0,0);
    uView.print(randNX);
    uView.display();  
     for(int j=0; j<randNX; j++) {
          int eccartLed2 = i-(j*(100/randNX));
          int sensVal = constrain(eccartLed2, 0, 255);
          int randLedStart = randLed+(j*randDirX)+(j*8*randDirY);
          int randLedStart0 = 9+(j*1)+(j*8*0);
          int randLedStart1 = 14+(j*0)+(j*8*1);
          int randLedStart2 = 54+(j*-1)+(j*8*0);
          int randLedStart3 = 49+(j*0)+(j*8*-1);
          strip.setPixelColor(randLedStart, strip.Color(randColor1*sensVal, randColor2*sensVal, sensVal));
          //strip.setPixelColor(randLedStart1, strip.Color(randColor1*sensVal, randColor2*sensVal, sensVal));
          //strip.setPixelColor(randLedStart2, strip.Color(randColor1*sensVal, randColor2*sensVal, sensVal));
          //strip.setPixelColor(randLedStart3, strip.Color(randColor1*sensVal, randColor2*sensVal, sensVal));
          /*int randLedStart4 = 18+(j*1)+(j*8*0);
          int randLedStart5 = 21+(j*0)+(j*8*1);
          int randLedStart6 = 45+(j*-1)+(j*8*0);
          int randLedStart7 = 42+(j*0)+(j*8*-1);
          strip.setPixelColor(randLedStart4, strip.Color(randColor1*sensVal, randColor2*sensVal, sensVal));
          strip.setPixelColor(randLedStart5, strip.Color(randColor1*sensVal, randColor2*sensVal, sensVal));
          strip.setPixelColor(randLedStart6, strip.Color(randColor1*sensVal, randColor2*sensVal, sensVal));
          strip.setPixelColor(randLedStart7, strip.Color(randColor1*sensVal, randColor2*sensVal, sensVal));*/          
          strip.show();
          delay(0);
     }
     delay(0);
   }
  for(int i=100; i>0; i--) {
    for(int j=0; j<randNX; j++) {
          int eccartLed2 = i-((randNX-j)*(100/randNX));
          int sensVal = constrain(eccartLed2, 0, 255);
          int randLedStart = randLed+(j*randDirX)+(j*8*randDirY);
          int randLedStart0 = 9+(j*1)+(j*8*0);
          int randLedStart1 = 14+(j*0)+(j*8*1);
          int randLedStart2 = 54+(j*-1)+(j*8*0);
          int randLedStart3 = 49+(j*0)+(j*8*-1);
          int carreStart = 27+(j+decalCarre);
          strip.setPixelColor(randLedStart, strip.Color(randColor1*i, randColor2*i, i));
          //strip.setPixelColor(randLedStart1, strip.Color(randColor1*sensVal, randColor2*sensVal, sensVal));
          //strip.setPixelColor(randLedStart2, strip.Color(randColor1*sensVal, randColor2*sensVal, sensVal));
          //strip.setPixelColor(randLedStart3, strip.Color(randColor1*sensVal, randColor2*sensVal, sensVal));
          /*int randLedStart4 = 18+(j*1)+(j*8*0);
          int randLedStart5 = 21+(j*0)+(j*8*1);
          int randLedStart6 = 45+(j*-1)+(j*8*0);
          int randLedStart7 = 42+(j*0)+(j*8*-1);
          strip.setPixelColor(randLedStart4, strip.Color(randColor1*sensVal, randColor2*sensVal, sensVal));
          strip.setPixelColor(randLedStart5, strip.Color(randColor1*sensVal, randColor2*sensVal, sensVal));
          strip.setPixelColor(randLedStart6, strip.Color(randColor1*sensVal, randColor2*sensVal, sensVal));
          strip.setPixelColor(randLedStart7, strip.Color(randColor1*sensVal, randColor2*sensVal, sensVal));*/                    
          strip.show();
          delay(0);
     }
     delay(0);
   }
}

void fadeInLed(int numL){
  int randLed = floor(random(0,64));
  int randNX = floor(random(2,8));
  randNX = min(randNX, 8-(randLed % 8));
  int randDirX = floor(random(0,2))-1;
  int randDirY = floor(random(0,2))-1;
  int randColor1 = floor(random(0,255));
  int randColor2 = floor(random(0,255));
  uView.setFontType(2); 		// set font type 0, please see declaration in MicroView.cpp
  uView.clear(PAGE);
  uView.setCursor(0,0);
  uView.print(randLed);
  uView.display();  
  
  for(int i=0; i<randNX; i++) {
    R = 0;
    G = 0;
    B = 0;
  int randLedStart = randLed+(randNX*randDirX)+(randNX*8*randDirY);  
      for(R && G && B; R<90 && G<90 && B<90; R++ && G++ && B++) {
        strip.setPixelColor(randLed+i, strip.Color(0,0, B));
        strip.show();
        delay(0);
      }
    delay(0);
  }
  for(R && G && B; R>-1 && G>-1 && B>-1; R-- && G-- && B--) {
    for(int j=0; j<randNX; j++) {
      strip.setPixelColor(randLed+j, strip.Color(0, 0, B));
      strip.show();
      delay(0);
    }
    delay(1);
  }  
  
}
void fadeOutLed(int numL){
  for(R && G && B; R>-1 && G>-1 && B>-1; R-- && G-- && B--) {
    for(int j=0; j<pixNum; j++) {
      strip.setPixelColor(j, strip.Color(R, 10+G, 50+B));
      strip.show();
      delay(0);
    }
    delay(1);
  }  
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(0, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(0, 0, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, 0, 0);
  }
}

uint8_t readCapacitivePin(int pinToMeasure) {
  // Variables used to translate from Arduino to AVR pin naming
  volatile uint8_t* port;
  volatile uint8_t* ddr;
  volatile uint8_t* pin;
  // Here we translate the input pin number from
  //  Arduino pin number to the AVR PORT, PIN, DDR,
  //  and which bit of those registers we care about.
  byte bitmask;
  port = portOutputRegister(digitalPinToPort(pinToMeasure));
  ddr = portModeRegister(digitalPinToPort(pinToMeasure));
  bitmask = digitalPinToBitMask(pinToMeasure);
  pin = portInputRegister(digitalPinToPort(pinToMeasure));
  // Discharge the pin first by setting it low and output
  *port &= ~(bitmask);
  *ddr  |= bitmask;
  //delay(1);
  // Prevent the timer IRQ from disturbing our measurement
  noInterrupts();
  // Make the pin an input with the internal pull-up on
  *ddr &= ~(bitmask);
  *port |= bitmask;

  // Now see how long the pin to get pulled up. This manual unrolling of the loop
  // decreases the number of hardware cycles between each read of the pin,
  // thus increasing sensitivity.
  uint8_t cycles = 17;
       if (*pin & bitmask) { cycles =  0;}
  else if (*pin & bitmask) { cycles =  1;}
  else if (*pin & bitmask) { cycles =  2;}
  else if (*pin & bitmask) { cycles =  3;}
  else if (*pin & bitmask) { cycles =  4;}
  else if (*pin & bitmask) { cycles =  5;}
  else if (*pin & bitmask) { cycles =  6;}
  else if (*pin & bitmask) { cycles =  7;}
  else if (*pin & bitmask) { cycles =  8;}
  else if (*pin & bitmask) { cycles =  9;}
  else if (*pin & bitmask) { cycles = 10;}
  else if (*pin & bitmask) { cycles = 11;}
  else if (*pin & bitmask) { cycles = 12;}
  else if (*pin & bitmask) { cycles = 13;}
  else if (*pin & bitmask) { cycles = 14;}
  else if (*pin & bitmask) { cycles = 15;}
  else if (*pin & bitmask) { cycles = 16;}

  // End of timing-critical section
  interrupts();

  // Discharge the pin again by setting it low and output
  //  It's important to leave the pins low if you want to 
  //  be able to touch more than 1 sensor at a time - if
  //  the sensor is left pulled high, when you touch
  //  two sensors, your body will transfer the charge between
  //  sensors.
  *port &= ~(bitmask);
  *ddr  |= bitmask;

  return cycles;
}
