#include <iostream>
#include <cmath>

using namespace std;

int main() {

int y = 0;
int x = 0;
//declare a as the angle value, ask for input, asign input to angle value
double a;
cout << "Enter a theta value between 15 and 75: ";
cin >> a;

//convert a from degrees into radians, then do the equation to find the length of the bottom using trig
a = (a*3.14159265)/180;

double l = 31*(tan(a));

l = floor (l);

//input the equation for the length of the bottom into the for loop
//use that in a for loop for when the x value is not 20-30
//add an if statement for when the x value is between 20-30, 
//and then make those lines print out 20 *

for(y = 0; y<=30; ++y) {
	for (x = 0; x<=floor(y*(tan(a))); ++x)
	{
		if(floor(y*(tan(a)))<20 || floor(y*(tan(a)))>30){
			cout << "*";	
		}
		} 
	
	if(x>20 && x<=30){
		cout << "********************";	
			
		}
 cout << endl;

	}

return 0;
} 