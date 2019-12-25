#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

#include "matrix_ops.h"

using namespace std;

//Program is called like: ./matrix t1.txt add
//First argument is filename
//Second argument is operation to perform
int main(int argc, char const *argv[])
{
	//First check if there are enough arguments
	if(argc < 3)
	{
		cout << "Not enough arguments: ./matrix <filename> <operation>" << endl;
		return 1;
	}

	//Now create an ifstream object and try to open the file,
	//If this fails print a message and return 1
	//See the writeup for the error message	
const char* filename = argv[1];

ifstream inFile;

inFile.open(filename);

if(!inFile){
   cout << "Unable to open file: " << filename << endl;
   return 1;
  }

	//The first line of the file is #rows #cols for the A matrix.
	//Read in these two integer values into appropriately named variables
int rowsA;
int colsA;
inFile >> rowsA;
inFile >> colsA;

	//Pass these values to the matrix_allocate function to allocate 
	//a row x col sized array of doubles
 double** arrayA = matrix_allocate(rowsA, colsA);

	//Write the code needed to read in matrix A into 
	//the array you just allocated
for(int i = 0; i<rowsA; i++){
	for(int j = 0; j<colsA;j++){
		inFile >> arrayA[i][j];
	}
}

	//The next line of the file is #rows #cols for the B matrix
	//Read in these two integer values into appropriately named variables
int rowsB;
int colsB;
inFile >> rowsB;
inFile >> colsB;

	//Pass these two values to the matrix_allocate function to allocate 
	//a row x col sized array of doubles
 double** arrayB = matrix_allocate(rowsB, colsB);
	
	//Write the code needed to read in matrix B 
	//into the array you just allocated
for(int i = 0; i<rowsB; i++){
	for(int j = 0; j<colsB;j++){
		inFile >> arrayB[i][j];
	}
}
	
	//Now verify the dimensions are compatible with the operation specified.
	//The operation comes from the 2nd command line argument
	//If the dimensions aren't compatible, then quit with an error message
	//See the writeup for the error message.
	//If the 2nd command line argument isn't one of {add, subtract, multiply}
	//Then print out an error message and return 1. See writeup for message.
	//Return 1 in all failure cases
	
const char* operation = argv[2];

const char* add = "add";
const char* subtract = "subtract";
const char* multiply = "multiply";

if(strcmp(operation,add) == 0 || strcmp(operation, subtract) == 0){
	if(rowsA != rowsB || colsA != colsB){
		cout << "Number of rows and number of columns must ";
		cout << "match for add or subtract." << endl;
		return 1;
	}
}

if(strcmp(operation,multiply) == 0){
	if(colsA != rowsB || colsA != colsB){
		cout << "Number of columns in A must match number of rows ";
		cout << "in B for multiply." << endl;
		return 1;
	}
}

if(strcmp(operation,add) != 0 && 
	strcmp(operation,subtract) != 0 && strcmp(operation,multiply) != 0)
{
	cout << "Unknown operation: " << operation << endl;
	cout << "Valid operations: add, subtract, multiply" << endl;
	return 1;
}


	double** result = NULL;

	//Now perform the operation. 
	//The functions matrix_add, matrix_subtract and matrix_multiply allocate 
	//the result matrix for you.
	//They will return a pointer to this matrix. 
	//Don't forget to caputure that pointer. You'll need it.
	
	if(strcmp(operation,add) == 0){
		result = matrix_add(arrayA, arrayB, rowsA, colsA);
	}
	if(strcmp(operation,subtract) == 0){
		result = matrix_subtract(arrayA, arrayB, rowsB, colsB);
	}
	if(strcmp(operation,multiply) == 0){
		result = matrix_multiply(arrayA, rowsA, colsA, arrayB, rowsB, colsB);
	}

	//Store the size of the result in these variables.
	//For add and subtract it's easy, for multiply check the docs.
	int rows = 0;
	int cols = 0;

if(strcmp(operation,subtract) == 0 || strcmp(operation,add) == 0){
		rows = rowsA;
		cols = colsA;
	}
else if(strcmp(operation,multiply) == 0){
		rows = rowsA;
		cols = colsB;
	}

	//Based on the 2nd command line argument call the proper function in
	//matrix_ops. Set rows and cols to the proper value
	
	//At this point assuming your matrix_ops functions are correct,
	//then YOU'RE almost DONE! ;-) See below for one last thing.

	//We give you the code to print out the resulting matrix
	for(int r = 0; r<rows;r++)
	{
		for(int c = 0; c<cols;c++)
		{
			cout << fixed << setprecision(2) << setw(7) << result[r][c];
		}
		cout << endl;
	}

	//Now delete A, B and result using matrix_delete();
	

	matrix_delete(arrayA, rowsA);
	matrix_delete(arrayB, rowsB);

	return 0;
}
