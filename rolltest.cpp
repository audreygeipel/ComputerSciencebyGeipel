#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;


int roll() {
	srand(time(0));
	

	int r1 = rand() % 6 + 1;
	int r2 = rand() % 6 + 1;
	int r3 = rand() % 6 + 1;
	int r4 = rand() % 6 + 1;
	int r = r1 + r2 + r3 + r4;

	//cout << r1 << r2 << r3 << r4 << " " << r << endl;
	return r;

return 0;
}

int main() {

	int r = roll();

	//int a = roll();
	//int b = roll(); 
	//int c = roll();
	//int d = roll();

	//int e = a + b + c + d;

	cout << r << endl;
	
}