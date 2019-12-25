#include <string>
#include <vector>
#include "bigint.h"

// importing a whole namespace in a header is frowned upon
// this will at least let us write 'string'/'vector' below
using std::string;
using std::vector;

int main(){

BigInt::BigInt(string s)
{
int k = 0;

bstr = s;

for (int i = bstr.size() - 1; i>=0; i--){
	push_back(vect);
	
	vect[k] = (int)bstr[i] - 48;

	k++;
}

}
	   // convert string to BigInt

string BigInt::to_string()
{
int j = 0;

for(int i = 0; i < vect.size(); i--)
{
	restring[j] = (string)(vect[i] + 48);
	j++;
}

} // get string representation
     
void BigInt::add(BigInt b)
{


} // add another BigInt to this one
  
}