#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   // Enter your code here

   double red; // this is getting all of the RGB values from the input
   double green;
   double blue;
   cout << "Enter the red value" << endl;
   cin >> red;
   cout << "Enter the green value" << endl;
   cin >> green;
   cout << "Enter the blue value" << endl;
   cin >> blue;
   
   double w = max((red/255),(green/255));
   double white = max((blue/255),w);
   double c = (white - (red/255))/white;
   double m = (white - (green/255))/white;
   double y = (white - (blue/255))/white;
   double k = 1- white;

   cout << "cyan: " << c << endl;
   cout << "magenta: " << m << endl;
   cout << "yellow: " << y << endl;
   cout << "black: " << k << endl;


   return 0;
}
