// hangman.cpp
// Hangman game illustrates string library functions, 
// character arrays, arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Prototype. we'll define this below.
int processGuess(char* word, const char* targetWord, char guess);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s
const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn", 
                          "science", "engineer"};

const int numWords = 10;

bool letterGuessed;

int main()
{
  srand(time(0));
  char guess;
  //bool wordGuessed = false;
  int numTurns = 10;
  char ast = 42;

  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];

  // More initialization code as needed
  char word[80];  // a blank array to use to build up the answer
                  // It should be initialized with *'s and then
                  //  change them to the actual letters when the 
                  //  user guesses the letter
for(int i = 0; i<strlen(targetWord); i++){
	word[i] = ast;
}

cout << "Current word: ";
	for(int i = 0; i<strlen(targetWord); i++){
	cout << word[i];
	}
cout << endl;
cout << numTurns << " remain... Enter a letter to guess:" << endl;


while(numTurns>0){
  // An individual game continues until a word is guessed correctly or 10 turns have elapsed
	cin >> guess;
	int turn = processGuess(word, targetWord, guess);

if(turn == 1){
	if(numTurns>0){
		if(letterGuessed == false){
			numTurns = numTurns - 1;
				if(numTurns == 0){
					break;
				}
			cout << "Current word: ";
				for(int i = 0; i<strlen(targetWord); i++){
				cout << word[i];
				}
			cout << endl;
			cout << numTurns << " remain... Enter a letter to guess:" << endl;
			cout << endl;
		}
		if(letterGuessed == true){
			cout << "Current word: ";
				for(int i = 0; i<strlen(targetWord); i++){
				cout << word[i];
				}
			cout << endl;
			cout << numTurns << " remain... Enter a letter to guess:" << endl;
			cout << endl;
		}
	}

	
	} // end of turn == 1 loop

if(turn == 0){
	break;
	}

if(turn == 10){
	cout<< "Oh god there's been an error";
	}

}


//Print out end of game status
if(numTurns == 0){
	cout << "Too many turns!" << endl;
	cout<< "You lose!" << endl;
}
if(numTurns > 0){
	cout << "The word was: ";
	for(int i = 0; i<strlen(targetWord); i++){
		cout << word[i];
		}
	cout<< endl;
	cout << " You win!" << endl;
} 
  return 0;
}


// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found

int processGuess(char* word, const char* targetWord, char guess)
{
letterGuessed = false;

for(int i = 0; i<strlen(word);i++){
	if(targetWord[i] == guess){
		word[i] = guess;
		letterGuessed = true;
	}
}


if(strcmp(targetWord, word) == 0){
	return 0;
}
  
if(strcmp(targetWord, word) !=0){
	return 1;
}
return 10;
}

