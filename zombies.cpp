/*************************
CS 103 Zombie-pocalypse PA
Name: Audrey Geipel
USC email: ageipel@usc.edu
comments: help
***************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
using namespace std;

const int MAXPOP = 20000;
bool pop[MAXPOP];
int N;
int k;
int M;
int s;

int onesim(){
  int nights = 0;
  int zcount = k;
  int reset = k;
  //for every zombie, randomly pick one spot in the array to bite
  //set zcount to 0, then go through and count the zombies to use in the
  //next round of bites.
  //add a night eveyr time it goes around, and end the while loop when there are only zombies
 
  while(zcount < N){
   
    for(int i = 0; i<zcount; i++){
            pop[rand()%N] = true;
          }

      zcount = 0;
      for(int j = 0; j<N; j++){
        if(pop[j] == true){
          zcount++;
        }
      }
      nights++;
    }


  //reset everything back to the original
  zcount = reset;

  for(int j = 0; j<k; j++){
    pop[j] = true;
  }
  for (int l = k; l<N; l++){
    pop[l] = false;
  }

  //return
  return nights;
} //end of function



int main(){
  // first, declare all the variable being inputted, and ask for input
  cout << "Enter the following: N k M seed" << endl;
  cin >> N >> k >> M >> s;

  //set up the random number generator
  srand(s);

  //assign the array with the number of zombies 
  //and normal people
  for(int j = 0; j<k; j++){
    pop[j] = true;
  }
  for (int l = k; l<N; l++){
    pop[l] = false;
  }

  //declare a new array to store the results of the simulations
  //call the function for one simulation, assign the number of nights to a spot in the array
  int sims[10000];
  for(int e =0; e<10000;e++){
    sims[e] = 0;
  }

  for(int y = 0; y<M; y++){
    sims[y] = onesim();
  }


  //calculate the average, max, and min numbers 
  //from the array (used help from pg 257 of textbook)
  double sum = 0.0;
  for (int i = 0; i <M; i++){
    sum = sum + sims[i];
  }
  double avg = (sum)/ M;

  int max = sims[0];
  for (int t = 1; t < M; t++)
    {
      if (sims[t] > max)
	{
	  max = sims[t];
	} }

  int min = sims[0];
  for (int t = 1; t < M; t++)
    {
      if (sims[t] < min)
	{
	  min = sims[t];
	} }

  cout << "Average Nights: "<< avg << endl;
  cout << "Max Nights: " << max << endl;
  cout << "Min Nights: "  << min << endl;
  return 0;
}
