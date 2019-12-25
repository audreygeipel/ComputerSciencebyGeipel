#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) {
  for(int i = 0; i<SIZE; i++){
   for(int y = left; y< (left+width); y++){
      image[top][y] = 0;
      image[top+height][y] =0;
  }
  for(int x = top; x<(height+top); x++){
      image[x][left] = 0;
      image[x][left+width] = 0;
  }
}
}


// Fill in this function:
void draw_ellipse(int cy, int cx, int height, int width) {
   for(double theta = 0.0; theta<(2*3.14159); theta+=.01){
      int rx = width/2;
      int ry = height/2;
      double x = rx*cos(theta);
      double y = ry*sin(theta);
      x += cx;
      y += cy;
         image[(int)y][(int)x] = 0;
}
}


int main() {
   // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
   
   // Main program loop here

cout << "To draw a rectangle, enter: 0 top left height width" << endl;
cout << "To draw an ellipse, enter: 1 cy cx height width" << endl;
cout << "To save your drawing as 'output.bmp' and quit, enter: 2" << endl;




int ins;
int v1;
int v2;
int v3;
int v4;

cin >> ins;
cin >> v1 >> v2 >> v3 >> v4;

while(ins == 0 || ins == 1 ){
      if(ins == 0){
      draw_rectangle(v1, v2, v3, v4);
         writeGSBMP("output.bmp", image);
      }
      if(ins == 1){
      draw_ellipse(v1, v2, v3, v4);
         writeGSBMP("output.bmp", image);
      }
 cin >> ins;
 if(ins == 2){
 break;
 }
 cin >> v1 >> v2 >> v3 >> v4;

}

   // Write the resulting image to the .bmp file

   writeGSBMP("output.bmp", image);
   
   
   return 0;
}
