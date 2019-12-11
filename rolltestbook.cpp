#include <iostream>
 #include <string>
 #include <cstdlib>
 #include <ctime>

 using namespace std;

 int main()
 {
 srand(time(0));

 int d1 = rand() % 6 + 1;
 int d2 = rand() % 6 + 1;
 int d3 = rand() % 6 + 1;
 int d4 = rand() % 6 + 1;
 int sum = d1 + d2 + d3 + d4;
 int r = sum;
 
 return r;
 }