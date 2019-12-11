#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "bmplib.h"
#include <fstream>

using namespace std;

//============================Add function prototypes here======================
int readRGBBMP(char filename[], unsigned char inputImage[][256][3]);
int writeRGBBMP(char filename[], unsigned char outputImage[][256][3]);
void dummy(unsigned char output[256][256][3], unsigned char input[256][256][3]);
void convolve(unsigned char out[256][256][3], unsigned char in[256][256][3], int N, double kernel[11][11]);


//============================Do not change code in main()======================

#ifndef AUTOTEST

int main(int argc, char* argv[])
{
   //First check argc
  if(argc < 3)
    {
      //we need at least ./filter <input file> <filter name> to continue
      cout << "usage: ./filter <input file> <filter name> <filter parameters>";
      cout << " <output file name>" << endl;
      return -1;
    }
   //then check to see if we can open the input file
   unsigned char input[SIZE][SIZE][RGB];
   unsigned char output[SIZE][SIZE][RGB];
   char* outfile;
   

   // read file contents into input array
   int status = readRGBBMP(argv[1], input); 
   if(status != 0)
   {
      cout << "unable to open " << argv[1] << " for input." << endl;
      return -1;
   }
   //Input file is good, now look at next argument
 
   cout <<  "WHat the FUCK" << endl;

   if(strcmp("dummy ", argv[2]) == 0)
   {
     //do dummy
     dummy(output, input);
     outfile = argv[3];
   }
   else
   {
      cout << "unknown filter type." << endl;
      return -1;
   }

   if(writeRGBBMP(outfile, output) != 0)
   {
      cout << "error writing file " << argv[3] << endl;
   }

}   

#endif 

//=========================End Do not change code in main()=====================


// Creates an identity kernel (dummy kernel) that will simply
// copy input to output image and applies it via convolve()
//
// ** This function is complete and need not be changed.
// Use this as an example of how to create a kernel array, fill it in
// appropriately and then use it in a call to convolve.

void dummy(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB])
{
   double k[11][11];
   for (int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         k[i][j] = 0;
      }
   }
   k[1][1] = 1;
   convolve(out, in, 3, k);
}


// Convolves an input image with an NxN kernel to produce the output kernel
// You will need to complete this function by following the 
//  instructions in the comments
void convolve(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB], 
	      int N, double kernel[][11])
{
 
   for(int i = 0; i < SIZE; i++){
   		out[i][SIZE][2] = in[i][SIZE][2];
   }
  
  
}



int readRGBBMP(char filename[], unsigned char inputImage[][256][3]){

ifstream inFile;

inFile.open(filename);

if(!inFile){
   cout << "Oh God there's been an error" << endl;
   return 1;
  }

  else{
	for(int i = 0; i < SIZE; i++){
   		inFile >> inputImage[i][256][3];
 	 }
	
	}
return 0;
}

int writeRGBBMP(char filename[], unsigned char outputImage[][256][3]){

ofstream ofs;
ofs.open(filename);


for (int i = 0; i < SIZE; ++i)
{
	for(int j = 0; j<SIZE; j++){
	
	*filename = (unsigned char) outputImage[i][j][2];
	
	}

}
return 0;

}