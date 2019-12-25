#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "bmplib.h" 
#include "queue.h"
using namespace std;

void usage() { 
    cerr << "usage: ./label <options>" << endl;
    cerr <<"Examples" << endl;
    cerr << "./label test_queue" << endl;
    cerr << "./label gray <input file> <outputfile>" << endl;
    cerr << "./label binary <inputfile> <outputfile>" << endl;
    cerr << "./label segment <inputfile> <outputfile>" << endl;
}

//function prototypes
void test_queue();
void rgb2gray(unsigned char ***in,unsigned char **out,int height,int width);
void gray2binary(unsigned char **in,unsigned char **out,int height,int width);
int component_labeling(unsigned char **binary_image,int **labeled_image,
    int height,int width);
void label2RGB(int  **labeled_image, unsigned char ***rgb_image,int num_segment,
    int height,int width);
void clean(unsigned char ***input,unsigned char **gray,unsigned char **binary, 
    int **labeled_image,int height , int width);


// main function, you do not need to make any changes to this function 
int main(int argc,char **argv) {



    srand( time(0) );
    if(argc < 2 )  {
        usage();
        return -1;
    }        
    unsigned char ***input=0;
    unsigned char **gray=0;
    unsigned char **binary=0;
    int **labeled_image=0;
    if( strcmp("test_queue",argv[1]) == 0 ) { 
        test_queue();
    } 
    else if(strcmp("gray",argv[1]) == 0 ) {
        if(argc <4 ) {
            cerr << "not enough arguemnt for gray" << endl;
            return -1;
        }
        int height = 1014;
        int width = 1917;
        input = readRGBBMP(argv[2],&height,&width);
        if(input == 0)
        {
            cerr << "unable to open " << argv[2] << " for input." << endl;
            return -1;
        }            
        gray = new unsigned char*[1014];
        for(int i=0;i<height;i++) 
            gray[i] = new unsigned char[1917];
        rgb2gray(input,gray,1014,1917);
        if(writeGSBMP(argv[3],gray,1014,1917) != 0) { 
            cerr << "error writing file " << argv[3] << endl;
            clean(input,gray,binary,labeled_image,1014,1917);
            return -1;
        }
        clean(input,gray,binary,labeled_image,1014,1917);

    }
    else if(strcmp("binary",argv[1]) == 0 ) {
        if(argc <4 ) {
            cerr << "not enough arguemnt for binary" << endl;
            return -1;
        }            
        int height,width;
        input = readRGBBMP(argv[2],&height,&width);
        if(input == 0)
        {
            cerr << "unable to open " << argv[2] << " for input." << endl;
            clean(input,gray,binary,labeled_image,1014,1917);
            return -1;
        }            

   cout << width << " x " << height << endl;


        gray = new unsigned char*[1014];
        for(int i=0;i<1014;i++) 
            gray[i] = new unsigned char[1917];
        rgb2gray(input,gray,1014,1917);

        binary = new unsigned char*[1014];
        for(int i=0;i<1014;i++)
            binary[i] = new unsigned char[1917];

        gray2binary(gray,binary,1014,1917);
        if(writeBinary(argv[3],binary,1014,1917) != 0) { 
            cerr << "error writing file " << argv[3] << endl;
            clean(input,gray,binary,labeled_image,1014,1917);
            return -1;
        }
        clean(input,gray,binary,labeled_image,1014,1917);
     
    }
    else if(strcmp("segment",argv[1]) == 0 ) {
        if(argc <4 ) {
            cerr << "not enough arguemnt for segment" << endl;
            return -1;
        } 
        int height,width;
        input = readRGBBMP(argv[2],&height,&width);
        if(input == 0)
        {
            cerr << "unable to open " << argv[2] << " for input." << endl;
            clean(input,gray,binary,labeled_image,1014,1917);
            return -1;
        }            

        gray = new unsigned char*[1014];
        for(int i=0;i<1014;i++) 
            gray[i] = new unsigned char[1917];
        rgb2gray(input,gray,1014,1917);

        binary = new unsigned char*[1014];
        for(int i=0;i<1014;i++)
            binary[i] = new unsigned char[1014];

        gray2binary(gray,binary,1014,1917);


        labeled_image = new int*[1014];
        for(int i=0;i<1014;i++) labeled_image[i] = new int[1917];
        int segments= component_labeling(binary, labeled_image,1014,1917); 



        for(int i=0;i<1014;i++) 
            for(int j=0;j<1917;j++) 
                for(int k=0;k<RGB;k++) 
                    input[i][j][k] = 0;
        label2RGB(labeled_image, input ,segments, 1014,1917);
        if(writeRGBBMP(argv[3],input,1014,1917) != 0) {
            cerr << "error writing file " << argv[3] << endl;
            clean(input,gray,binary,labeled_image,1014,1917);
            return -1;
        }
        clean(input,gray,binary,labeled_image,1014,1917);

    }

   return 0;
}

//This function is used to test your queue implementation. 
//You do not need to change it,
//though doing so might be useful/helpful

void test_queue() { 
    // create some locations;
    Location three_one, two_two;
    three_one.row = 3; three_one.col = 1;
    two_two.row = 2; two_two.col = 2;

    //create an Queue with max capacity 5
    Queue q(5);

    cout << boolalpha;
    cout << q.is_empty() << endl;           // true
    q.push(three_one);
    cout << q.is_empty() << endl;           // false
    q.push(two_two);

    Location loc = q.pop();
    cout << loc.row << " " << loc.col << endl; // 3 1
    loc = q.pop();
    cout << loc.row << " " << loc.col << endl; // 2 2
    cout << q.is_empty() << endl;           // true
}

//Loop over the 'in' image array and calculate the single 'out' 
//pixel value using the formula
// GS = 0.2989 * R + 0.5870 * G + 0.1140 * B 
void rgb2gray(unsigned char ***in,unsigned char **out,int height,int width) {
     
     for(int i = 0; i < height; i++){
        for(int j = 0; j<width; j++){
            out[i][j] = (unsigned char) 0;
        }
    }


     for(int i = 0; i < height; i++){
        for(int j = 0; j<width; j++){
            for(int k = 0; k < RGB; k++){
               double red = 0;
               double green = 0;
               double blue = 0;

                if(k == 0){
                   red =.2989*(int)(in[i][j][k]);
                }
                if(k == 1){
                    green = .5870*(int)(in[i][j][k]);
                }
                if(k == 2){
                    blue = .114*(int)(in[i][j][k]);
                }

                double color = red + green + blue;

                if(color>255){
                    color = 255;
                }
                if(color<0){
                    color = 0;
                }

                out[i][j] += (double)color;

            }
        }
     }

}

//Loop over the 'in' gray scale array and create a binary (0,1) 
//valued image 'out'
//Set the 'out' pixel to 1 if 'in' is above the threshold, else 0
void gray2binary(unsigned char **in,unsigned char **out,
    int height,int width) {
     for(int i = 0; i < height; i++){
        for(int j = 0; j<width; j++){

            if(in[i][j] > THRESHOLD){
                out[i][j] = 1;
            }else{
                out[i][j] = 0;
            }

        }
     }
}



//This is the function that does the work of looping over the binary 
//image and doing the connected component labeling
//See the .pdf for more details
int component_labeling(unsigned char **binary_image,int **label,
        int height,int width) {

int current_label = 1;
Location loc1;
    loc1.row = 0;
    loc1.col = 0;
Location loc;
    loc.row = 0;
    loc.col = 0;
Location locadd;
    locadd.row = 0;
    locadd.col = 0;
Queue search(height*width); 

for(int i = 0; i<height; i++){
    for(int j = 0; j<width; j++){
        label[i][j] = 0;
    }
}


for(int i = 0; i<height; i++){
    for(int j = 0; j<width; j++){
       
//if pixel is not background, label it current label and push into queue
      if(binary_image[i][j] == 0){
            label[i][j] = 0;
        //cout << "black" << endl;
        }

    else if(binary_image[i][j] == 1 && label[i][j] == 0){
        label[i][j] = current_label;
        
        loc1.row = i;
        loc1.col = j;
        search.push(loc1);

//perform BFS

while(search.is_empty() == false){
//for(search.push(loc1); search.is_empty() == true; i++){

        loc = search.pop();

      for(int r = -1; r<=1; r++){ 
        for(int c = -1; c<=1; c++){ 

            locadd.row = loc.row + r;
            locadd.col = loc.col + c;

            if(locadd.row >=height){
                locadd.row = height-1;
            }
            if(locadd.row < 0){
                locadd.row = 0;
            }
            if(locadd.col >=width){
                locadd.col = width-1;
            }
            if(locadd.col < 0){
                locadd.col = 0;
            }


        if(binary_image[locadd.row][locadd.col] == 1 && 
                label[locadd.row][locadd.col] == 0){
                     label[locadd.row][locadd.col] = current_label;
                    search.push(locadd);
                 }
                  locadd.row -= r;
                  locadd.col -= c;


             }
        }

    }//end of while

current_label++;
}   //end of else if

}//end of for j
}//end of for i

return current_label;
}    


//First make num_segments number of random colors to use for 
//coloring the labeled parts of the image.
//Then loop over the labeled image using the label to index 
//into your random colors array.
//Set the rgb_pixel to the corresponding color, or set to black 
//if the pixel was unlabeled.

#ifndef AUTOTEST
void label2RGB(int  **labeled_image, unsigned char ***rgb_image,
    int num_segments,int height,int width)
{

for(int i = 0; i < height; i++){
        for(int j = 0; j<width; j++){
            for(int k = 0; k<RGB; k++){
            rgb_image[i][j][k] = 0;
        }
    }
}

int** c = new int*[num_segments];
for(int i =0; i<num_segments; i++){
    c[i] = new int[RGB]; 
}
 
 //int c[num_segments][RGB];


for(int k = 0; k<num_segments; k++){
    for(int l = 0; l<RGB; l++){
    c[k][l] = rand()%255;
    }
}

   for(int i = 0; i < height; i++){
        for(int j = 0; j<width; j++){
            for(int k = 0; k<RGB; k++){
                for(int l = 0; l< num_segments; l++){
                         if(labeled_image[i][j] == 0){
                              rgb_image[i][j][k] = 0;
                         }
                         if(labeled_image[i][j] == l){
                              rgb_image[i][j][k] = (unsigned char)(c[l][k]);
                         }
                }
            }
        }
    }

for(int i = 0; i<num_segments; i++){
        delete[] c[i]; 
    }
    delete[] c;



}
#endif

//fill out this function to delete all of the dynamic arrays created
void clean(unsigned char ***input,unsigned char **gray,unsigned char **binary,
    int **labeled_image,int height , int width) {
    if(input != NULL) {
        for(int i =0; i<height; i++){
            for(int j = 0; j<width; j++){
            delete[] input[i][j];
            }
            delete[] input[i];
        }
        delete[] input;

        } 
        if(gray != NULL) {
        for(int i =0; i<height; i++){
            delete[] gray[i];
        } 
        delete[] gray;
        }

        if(binary !=NULL) {
            for(int i =0; i<height; i++){
                delete[] binary[i];
        }
        delete[] binary;
        }

        if(labeled_image != NULL) {
            
        for(int i =0; i<height; i++){
            delete[] labeled_image[i];
            } 
        delete[] labeled_image;

        }


}