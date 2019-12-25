#include "matrix_ops.h"

double** matrix_allocate(int rows, int cols){ 
	//Allocate a 2D array of doubles using new
	//return that pointer

double** array = new double*[rows];
for(int i =0; i<rows; i++){
	array[i] = new double[cols]; 
}
return array; 
}

void matrix_delete(double** M, int rows){
	//delete a 2D array with 'rows' #of rows
	
	for(int i =0; i<rows; i++){
		delete[] M[i]; 
	}
	
}

double** matrix_add(double** A, double** B, int rows, int cols){
	//Allocate a new 2D array of the proper size (hint: use matrix allocate)
	//Calculate A+B into your new array
	//Return the pointer to the new array
double** result = new double*[rows];
for(int i =0; i<rows; i++){
	result[i] = new double[cols]; 
}

for(int i =0; i<rows; i++){
	for(int j = 0; j<cols; j++){
		result[i][j] = A[i][j] + B[i][j];
	}
}
	return result;
}

double** matrix_subtract(double** A, double** B, int rows, int cols){
	//Allocate a new 2D array of the proper size (hint: use matrix allocate)
	//Calculate A-B into your new array
	//Return the pointer to the new array
double** result = new double*[rows];
for(int i =0; i<rows; i++){
	result[i] = new double[cols]; 
}

for(int i =0; i<rows; i++){
	for(int j = 0; j<cols; j++){
		result[i][j] = A[i][j] - B[i][j];
	}
}
	return result; //Replace this line. This included to make the skeleton compile
}

double** matrix_multiply(double** A, int rows_A, int cols_A, double** B, 
	                     int rows_B, int cols_B){

    //Allocate a new 2D array to hold the result of A*B
    //See the writeup for the proper dimensions

double** result = new double*[rows_A];
for(int i =0; i<rows_A; i++){
	result[i] = new double[cols_B]; 
}

    //For matrix multiply you'll want to initilize all elements
    //of this new array to 0.0
for(int i = 0; i<=rows_A-1; i++){
	for(int j = 0; j<=cols_B-1; j++){
		result[i][j] = 0.0;
	}
}
    //Now follow the pseudo-code in the writeup to perform A*B

if(cols_A == rows_B){
for(int i = 0; i<=rows_A-1; i++){

	for(int j = 0; j<=cols_B-1; j++){

		for(int x = 0; x<=cols_A-1; x++){

			result[i][j] += (A[i][x])*(B[x][j]);
		}
	}
}
}


    return result; 

}
