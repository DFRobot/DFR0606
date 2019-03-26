/*!
   /*!
   file LightCuverainbow.ino

   DFRobot-DFR0606 Full Color 4x4x4 Light Cube
   TThis sample code is used to coordinate the way to open the light cube 
   of any one of the LED.
   setVoxel(int x, int y, int z,int r,int g,int b)
   x、y、z is the coordinate,r,g,b is the Color.
   Copyright    [DFRobot](http://www.dfrobot.com), 2018
   Copyright    GNU Lesser General Public License
   Macro.
   version  V1.0
   date  2019-03-21
*/
#include <DFRobot_LightCube.h>
int frame=0;
DFRobot_LightCube cube = DFRobot_LightCube(NEO_GRB + NEO_KHZ800);
// Create a new object cube.
void setup() {
  
    cube.begin();
    background(0,0,0);
    
}
void loop() {
  
      background(0,0,0);
        if(frame%20>10)
         setVoxel(1,1,1,139,0,139); // 139,0,139,The corresponding color is purple
         cube.show();
         frame++;
      if(frame>255)
         frame =0;        
}
//  setVoxel(int x, int y, int z,int r,int g,int b)
//  x、y、z is the coordinate,r,g,b is the Color.
void setVoxel(int x, int y, int z,int r,int g,int b)
{
  if(x >= 0 && y >= 0 && z >= 0 &&
      x < 4 && y < 4 && z < 4) {
    int index = (z*16) + (x*4) + y;
    cube.setPixelColor(index, cube.Color(r,g,b));
  }
}
// Set the entire light cube to display one color as background
void background(int r,int g,int b)
{
  
  for(int x = 0; x < 4; x++)
    for(int y = 0; y < 4; y++)
      for(int z = 0; z < 4; z++)
        setVoxel(x, y, z, r, g, b );
        
}
