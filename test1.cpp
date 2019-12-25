#include "bigint.h"
#include <iostream>
using namespace std;

int main() {
   BigInt a("13");
   BigInt b("42");
   b.add(a);    // increase b by a
   cout << b.to_string() << endl; // prints 55
   b.add(a);    // increase b by a
   cout << b.to_string() << endl; // prints 68
}

//13
//42


//can add smaller numbers ot bigger ones 
//but not bigger ones to smaller ones


