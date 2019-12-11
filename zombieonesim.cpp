#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
using namespace std;

const int MAXPOP = 1000;

int main(){
int nights = 0;
bool pop[MAXPOP];
srand(137957);


for(int j = 0; j<5; j++){
	pop[j] = true;
}
for (int l = 5; l<=100; l++){
	pop[l] = false;
}

int k = 5;
int N = 100;
int z = k;

while(pop[N-1] == false){
	for(int w = 0; w<k; w++){

		if(pop[rand() % 100] == false){
			//if a zombie bites a normal person, there is one more zombie
			pop[z] = true;
			z++;
		} 
			} 
			k = z;
		nights++;
	}

cout << nights << endl;

return 0;
}