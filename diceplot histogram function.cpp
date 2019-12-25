#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;


 int roll() {
	srand(time(0));
	int r = rand() % 6 + 1;
	return r;
} 


void printHistogram(int counts[21])
{
	//this sets up the counting of X's
	//int counti = 0;

//this is for one roll of four dice
//for (int rolls = 0; rolls<=1; rolls++){
	//	int x = roll();

//for every time is rolls, if x is equal to the slot, it adds one to the count for that row		
//	for (int i = 0; i<=21; i++){
//	if ((x-4) == i){
//			counts[i] = counti;
//			counti++;
//		}
//	}

//this uses a code similar to the triangle one, where it prints
//out the number of X's based on the count above

// } 
for(int x = 4; x<=24; x++){
		cout << x << ": ";

		for (int j = 0; j< counts[x-4]; j++){
		cout << "X";

	}
	cout << endl;
}
}


int main() {


int testCounts[21]; // 21 options of sum of 4 dice => [4,24]
 for (int i=0; i<21; i++)
 testCounts[i] = i/2; // fill the array
 printHistogram(testCounts); // call your method





// ask for the number of rolls
//int n;
//cin << n;

//int counts[21];

//for (int a = 1; a<=n; a++){
 //int r = roll() + roll() + roll() + roll();
//	}

return 0;
}