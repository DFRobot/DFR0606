/*!
   /*!
   file LightCuverainbow.ino

   DFRobot-DFR0606 Full Color 4x4x4 Light Cube
   This sample codee is to test whether the light cube can work properly?
   If the light cube were working properly, it would be a rainbow block.
   Copyright    [DFRobot](http://www.dfrobot.com), 2018
   Copyright    GNU Lesser General Public License
   Macro.
   version  V1.0
   date  2019-03-21
*/
#include <DFRobot_LightCube.h>

DFRobot_LightCube cube = DFRobot_LightCube(NEO_GRB + NEO_KHZ800);
// Create a new object cube.
void setup() {

  cube.begin();
  
}

void loop() {
  
       theaterChase(cube.Color(0, 139, 139), 100); 
       theaterChase(cube.Color(139, 0, 139), 100); 
       theaterChase(cube.Color(255, 255, 0), 100); 
       theaterChase(cube.Color(0, 255, 255), 100); 
       colorWipe(cube.Color(255, 0, 0), 10);
       colorWipe(cube.Color(0, 255, 0), 10);
       colorWipe(cube.Color(0, 0, 255), 10);
       rainbow(20);
       rainbowCycle(10);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<64; i++) {
    cube.setPixelColor(i, c);
    cube.show();
    delay(wait);
  }
}
//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < 64; i=i+3) {
        cube.setPixelColor(i+q, c);    //turn every third pixel on
      }
      cube.show();
      delay(wait);
      for (int i=0; i < 64; i=i+3) {
        cube.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}
void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<64; i++) {
      cube.setPixelColor(i, Wheel((i+j) & 255));
    }
    cube.show();
    delay(wait);
  }
}
/*
 * Function: The Light Cube becomes a rainbow.
*/
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) {                 
    for(i=0; i< cube.numPixels(); i++) {
      cube.setPixelColor(i, Wheel(((i * 256 / cube.numPixels()) + j) & 255));
    }
    cube.show();
    delay(wait);
  }
}
/*
 * Function: Three shades of red, green and blue create a rainbow.
*/
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return cube.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return cube.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return cube.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
