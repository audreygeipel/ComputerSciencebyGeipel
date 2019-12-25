#include <string>
#include <vector>
#include "bigint.h"
#include <iostream>
// importing a whole namespace in a header is frowned upon
// this will at least let us write 'string'/'vector' below
using std::string;
using std::vector;
using std::cout;
using std::endl;

// convert string to BigInt
BigInt::BigInt(string s)
{
int k = 0;

for (int i = s.size() - 1; i>=0; i--)
	{
	vect.push_back((int)s[i] - 48);
	k++;
	}

}

// get string representation
string BigInt::to_string()
{

restring = "";

for(int i = vect.size()-1; i>=0; i--)
{
	restring.push_back((char)(vect[i] + 48));
}

return restring;
} 


// add another BigInt to this one
void BigInt::add(BigInt b)
{

//check the sizes and make sure each vector has the same size
//fill in the smaller one with zeros to make them the same size

if(b.vect.size() > vect.size()){
	for(int i = vect.size(); i < b.vect.size(); i++){
			vect.push_back(0);
	}
}
if(vect.size() > b.vect.size()){
	for(int i = b.vect.size(); i < vect.size(); i++){
			b.vect.push_back(0);
	}
}


//go through the vector and add the units places together
for(int i = 0; i < vect.size(); i++)
	{
	
	int sum = vect[i] + b.vect[i];
	


//if the sum of the diigts is 10 or greater and it is the last
//digits place, then push back to add an extra digits place and
//make it one
	if(sum >=10 && i == vect.size()-1){
		int carrysum = sum - 10;
		vect.push_back(1);
		vect[i] = carrysum;
		break;
	}


//if the sum is greater than 9, subtract 10 and put that value
//in the spot, then carry a one to the next spot. 

	else if(sum > 9){
		int carrysum = sum - 10;

		vect[i+1] = vect[i+1] + 1;

		vect[i] = carrysum;
	}


//if it's just a normal less-than-10 sum, just add them 
	else
	{
		vect[i] = sum;
	}

	}

} 
