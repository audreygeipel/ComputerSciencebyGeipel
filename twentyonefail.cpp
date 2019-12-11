//Audrey Geipel
//ageipel@usc.edu

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>

using namespace std;

//int cards[52];

/*const char* type[13] = 
  {"2","3","4","5","6","7",
   "8","9","10","J","Q","K","A"};
*/
const int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

int main(){
int cards[52];

//initalize array with cards from 0 to 51
	for(int i = 0; i<52; i++ ){
		cards[i] = i;
	}
//shuffle the deck	
srand(37);

for(int h = 51; h>=0; h--){
		int j = rand()% (h + 1);
		int hold = cards[h];
		cards[h] = cards[j];
		cards[j] = hold;
	}
/*
char* type[52] = 
{"2-H","3-H","4-H","5-H","6-H","7-H","8-H","9-H","10-H","J-H","Q-H","K-H","A-H",
"2-S","3-S","4-S","5-S","6-S","7-S","8-S","9-S","10-S","J-S","Q-S","K-S","A-S",
"2-D","3-D","4-D","5-D","6-D","7-D","8-D","9-D","10-D","J-D","Q-D","K-D","A-D",
"2-C","3-C","4-C","5-C","6-C","7-C","8-C","9-C","10-C","J-C","Q-C","K-C","A-C"};

int value[52] = 
{2,3,4,5,6,7,8,9,10,10,10,10,11,
2,3,4,5,6,7,8,9,10,10,10,10,11,
2,3,4,5,6,7,8,9,10,10,10,10,11,
2,3,4,5,6,7,8,9,10,10,10,10,11};
//deal two cards to the dealer and the player. Only show the player's cards
char* player[30];
char* dealer[30];

player[1] = type[cards[1]];
dealer[1] = type[cards[2]];
player[2] = type[cards[3]];
dealer[2] = type[cards[4]];

int playervalue[10];
int dealervalue[10];
for(inr i = 0; i<10; i++){
	playervalue[i] = 0;
	dealervalue[i]= 0;
}

playervalue[1] = value[cards[1]];
dealervalue[1] = value[cards[2]];
playervalue[2] = value[cards[3]];
dealervalue[2] = value[cards[4]];

cout << "Dealer: " << "?" << " " << dealer[1] << endl;
cout << "Player: " << player[1] << " " << player[2] << endl;
cout << playervalue[1] << " " << playervalue[2] << endl;

while(playervalue[1] + playervalue[2] + playervalue[3] + playervalue[4] + playervalue[5] + playervalue[6] <=21){
	char move;
	cout << "Type 'h' to hit and 's' to stay" << endl;
	cin << move;
	if(move = h){
		player[3 +i] = type[cards[5 + 1]];
		playervalue[3 +i] = type[cards[3+1]]
		}
	if(move = s){
		break;
		}
	else{
		break;
		}

}
int playersum = playervalue[1] + playervalue[2] + playervalue[3] + playervalue[4] + playervalue[5] + playervalue[6];
int dealersum = dealervalue[1] + dealervalue[2] + dealervalue[3] + dealervalue[4] + dealervalue[5] + dealervalue[6];

if(playersum > 21)
{
	cout << "Player busts" << endl;
	cout<< "Lose" << endl;
	cout << playersum << " " << "" << dealersum << endl;
}
*/
/*char faces[52];

for(int i = 0; i <=12; i++){
	faces[i] = *type[i];
}
for(int j = 13; j<=25; j++){
	faces[j] = *type[j-13];
}
for(int k = 26; k<=38; k++){
	faces[k] = *type[k-26];
}
for(int l = 39; l<=51; l++){
	faces[l] = *type[l-39];
}
 */

/*
char* faces[52];
char suits[52];

for(int i = 0; i<=12; i++){
	faces[i] = type[i];
}
for(int i = 13; i<=25; i++){
	faces[i] = type[i-13];
}
for(int i = 26; i<=38; i++){
	faces[3] = type[i-26];
}
for(int i = 39; i<=51; i++){
	faces[4] = type[i-39];
}




for(int i = 0; i<=12; i++){
	suits[i] = suit[0];
}
for(int i = 0; i<=12; i++){
	suits[i] = suit[1];
}
for(int i = 0; i<=12; i++){
	suits[i]=suit[2];
}
for(int i = 0; i<=12; i++){
	suits[i]=suit[3];
}

for(int i = 0; i<=12; i++){
	cardvalue[i+13] = value[i];
}
for(int i = 0; i<=12; i++){
	cardvalue[i+26] = value[i];
}
for(int i = 0; i<=12; i++){
	cardvalue[i+39] = value[i];
}

	return cardvalue[id];
*/




int	cardvalue[52];

for(int i = 0; i<=51; i++){
	int j = cards[i];
	int z = (j%13);
	cardvalue[i] = value[z];
	}



for(int k = 0; k <52; k++){
	cout << cards[k] << " ";
	}
	cout << endl;

for(int k = 0; k <52; k++){
	cout << cardvalue[k] << " ";
	}
	cout << endl;


	return 0;
}