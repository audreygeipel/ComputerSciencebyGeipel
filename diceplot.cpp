//Audrey Geipel
//ageipel@usc.edu

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

//the roll function, created with help from the book
 int roll() {

 int d1 = rand() % 6 + 1;
 int d2 = rand() % 6 + 1;
 int d3 = rand() % 6 + 1;
 int d4 = rand() % 6 + 1;
 int sum = d1 + d2 + d3 + d4;
 int r = sum;
 
 return r;
 }


void printHistogram(int counts[21])
{
//this uses a code similar to the triangle one, where it prints
//out the number of X's based on the count above

for(int x = 4; x<=24; x++){
		cout << x << ": ";

		for (int j = 0; j<counts[x-4]; j++){
		cout << "X";
		}
	cout << endl;
}
}


int main() {
srand(time(0));

//ask for the number of rolls, declare array, and set all counts to 0
int n;
cin >> n;

int counts[21];
for (int x = 0; x <= 21; x++){
	counts[x] = 0;
}

//do rolls and add a count to the number of the result

for (int i=1; i<=n; i++){
	int r = roll();
	
	counts[r-4] = counts[r-4] + 1;

}

 //print out that Histogram
 printHistogram(counts);

return 0;
}