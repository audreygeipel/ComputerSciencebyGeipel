#include "bigint.h"
#include <iostream>
using namespace std;


int main() {
   BigInt a("123");
   BigInt b("8");
   a.add(b);
   cout << a.to_string() << endl;
   return 0;
}
