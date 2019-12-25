#include <iostream>
#include <cmath>

using namespace std;

int main() {

int i = 0;

//declare a as the angle value, ask for input, asign input to angle value
double a;
cout << "Enter a theta value between 15 and 75: ";
cin >> a;

//convert a from degrees into radians, then do the equation to find the length of the bottom using trig
a = (a*3.14159265)/180;

double l = 30/ (tan(a));

l = floor (l);

//input the length of the bottom into the equation for printing out the triangle
for(i = 1; i<=l; ++i) {

for (int n = 1; n <= floor(i); ++n){

	cout << "*";
}
 cout << endl;
}

return 0;
}