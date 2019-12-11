/*******************************************************************************
 * CS 103 Twenty-One (Blackjack) PA
 * Name: Audrey Geipel
 * USC email: ageipel@usc.edu
 * Comments (you want us to know):
 *
 *
 ******************************************************************************/

// Add other #includes if you need
#include <iostream>
#include <cstdlib>

using namespace std;

/* Prototypes */
void shuffle(int cards[]);
void printCard(int id);
int cardValue(int id);
void printHand(int hand[], int numCards);
int getBestScore(int hand[], int numCards);

//const int NUM_CARDS = 52;

/**
 * Global arrays to be used as look-up tables, if desired.
 * It is up to you if and how you want to use these 
 */
const char suit[4] = {'H','S','D','C'};
const char* type[13] = 
  {"2","3","4","5","6","7",
   "8","9","10","J","Q","K","A"};
const int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

/**
 * Should permute the deck of cards, effectively shuffling it.
 * You must use the Fisher-Yates / Durstenfeld shuffle algorithm
 *  described in the assignment writeup.
 */
void shuffle(int cards[])
{
//initalize array with cards from 0 to 51
for(int i = 0; i<=51; i++ ){
	cards[i] = i;
}
//shuffle the deck	
for(int h = 51; h>=1; h--){
		int j = rand()% (h + 1);
		int hold = cards[h];
		cards[h] = cards[j];
		cards[j] = hold;
	}
}

/**
 * Prints the card in a "pretty" format:   "type-suit"
 *  Examples:  K-C  (King of clubs), 2-H (2 of hearts)
 *  Valid Types are: 2,3,4,5,6,7,8,9,10,J,Q,K,A
 *  Valid Suits are: H, D, C, S
 **/
void printCard(int id)
{
	int z = id%13;
	char tid = *type[z];
	
	double y = (id/13);
	char sid = 'a';
	if(y<1){
	sid = suit[0];
	}
	if(y>=1 && y<2){
	sid = suit[1];
	}
	if(y>=2 && y<3){
	sid = suit[2];
	}
	if(y>=3){
	sid = suit[3];
	}
cout << tid << "-" << sid;
}

/**
 * Returns the numeric value of the card.
 *  Should return 11 for an ACE and can then
 *  be adjusted externally based on the sum of the score.
 */
int cardValue(int id){

	int z = (id%13);
	int vid = value[z];
	
return vid;
}

/**
 * Should print out each card in the hand separated by a space and
 * then print a newline at the end.  
 * Should use printCard() to print out each card.
 */
void printHand(int hand[], int numCards)
{
  /******** You complete ****************/
for(int i = 0; i< numCards; i++){
	printCard(hand[i]); 
	cout << " ";
}
cout << endl;


}

/**
 * Should return the total score of the provided hand.  
 * ACES should be treated as 11s to make the highest possible hand
 *  and only being reduced to 1s as needed to avoid busting.
 */
int getBestScore(int hand[], int numCards){

  /******** You complete ****************/
int hvalue = 0;
for(int j = 0; j<numCards; j++){
	hvalue = hvalue + cardValue(hand[j]);
	}

if(hvalue>21){
	for(int i = 0; i <numCards; i++){
		if (cardValue(hand[i]) == 11){
			hvalue = hvalue - 10;
			}
		}//end of for
	}

return hvalue;
}



/**
 * Main program logic for the game of 21
 */
int main(int argc, char* argv[])
{
  //---------------------------------------
  // Do not change this code -- Begin
  //---------------------------------------
  if(argc < 2){
    cout << "Error - Please provide the seed value." << endl;
    return 1;
  }
  int seed = atoi(argv[1]);
  srand(seed);

  int cards[52];
  int dhand[9];
  int phand[9];
  //---------------------------------------
  // Do not change this code -- End
  //---------------------------------------

  /******** You complete ****************/
//shuffle cards and do initial deal
char ans = 'y';

while(ans == 'y'){

shuffle(cards);


phand[0] = cards[0];
dhand[0] = cards[1];
phand[1] = cards[2];
dhand[1] = cards[3];

cout << "Dealer: " << "?" << " ";
printCard(dhand[1]);
cout << endl;
cout << "Player: ";
printHand(phand, 2);

int i = 2;

while(getBestScore(phand, i)<21){
	cout << "Type 'h' to hit and 's' to stay:";
	char move;
	cin >> move;

	if(getBestScore(phand,i)>21){
		break;
		}

	if(move == 'h'){
		phand[i] = cards[2+i];
		cout << "Player: ";
		printHand(phand,i+1);
		i++;
	}

	if(move == 's'){
		break;
	}


	}//end of while
//end of for

int j = 2;

if(getBestScore(phand,i)>21){
		cout << "Player busts" << endl;
		cout << "Lose"<< " "<< getBestScore(phand,i);
		cout << " " << getBestScore(dhand, j) << endl;
}

if(getBestScore(phand,i) == 21){
		while(getBestScore(dhand, j)<17){
			dhand[j] = cards[i+j];
			j++;
			}

		cout << "Dealer: ";
		printHand(dhand,j);
		cout << "Win"<< " "<< getBestScore(phand,i);
		cout << " " << getBestScore(dhand, j) << endl;
}

else
	if(getBestScore(phand,i) < 21){
			while(getBestScore(dhand, j)<17){
			dhand[j] = cards[i+j];
			j++;
			}

		cout << "Dealer: ";
		printHand(dhand,j);

	if(getBestScore(dhand,j)>21){
			cout << "Dealer busts" << endl;
			cout << "Win" << " " << getBestScore(phand,i);
			cout << " " << getBestScore(dhand, j) << endl;
		}else{

		if(getBestScore(dhand, j) > getBestScore(phand,i)){	
			cout << "Lose"<< " "<< getBestScore(phand,i);
			cout << " " << getBestScore(dhand, j) << endl;
		}if(getBestScore(dhand, j) < getBestScore(phand,i)){
			
			cout << "Win" << " " << getBestScore(phand,i);
			cout << " " << getBestScore(dhand, j) << endl;
		}if(getBestScore(dhand, j) == getBestScore(phand,i)){
			
			cout << "Tie" << " " << getBestScore(phand,i);
			cout << " " << getBestScore(dhand, j) << endl;
		}
	}
	}



cout << endl;
cout << "Play again? [y/n]" << endl;

cin >> ans;

if(ans == 'n'){
	return 0;
	}
}
/*for(int k = 0; k <52; k++){
	cout << cards[k] << " ";
	}
	cout << endl;
*/

  return 0;
}

