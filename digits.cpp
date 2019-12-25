#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	//this defines n, asks for the input, and assigns that input to n
	int n;
	cout << "Enter an integer between 0 and 999" << endl;
	cin >> n;

//this is the math to find the digits, by using the remainder fundtion and subtracting out each units place after it was found
	int x = n%100;
	int ones = x%10;

	int tens = (x-ones)/10;

	int hunds = (n - ones - tens)/100;

// this is printing out the answer
	cout << "1's digit is " << ones << endl;
	cout << "10's digit is " << tens << endl;
	cout << "100's digit is " << hunds << endl;



return 0;

}