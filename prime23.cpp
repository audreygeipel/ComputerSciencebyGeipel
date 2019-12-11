#include <iostream>
#include <cmath>

using namespace std;

int main() {

// declare variable, recieve input, and assign input to variable
//also declare variables for counting twos and threes
int n;
int twos = 0;
int threes = 0;

cout << "Enter a positive integer" << endl;

cin >> n;

//divide by 2 until you can't anymore, adding the number of
//times you divide with two
//then do the same with threes

while (n%2 == 0){
	if (n%2 ==0)
		{
			twos = twos +1;
		}	
		n = n/2;
}
while (n%3 == 0){
	if(n%3 == 0){
	threes = threes + 1;
	}
	n = n/3;
}


//check to make sure there are no other numbers that can go
//into it, if it's not 1, then there's other numbers that can
//be divided into it
if (n != 0 && n != 1){
	cout << "No" << endl;
}

//print out the number of twos and threes
else{
	cout << "Yes" << endl;
	cout << "Twos = " << twos << endl;

	cout << "Threes = " << threes << endl;
}


return 0;
}
