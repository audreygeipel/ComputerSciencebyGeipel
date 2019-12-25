#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "person.h"

using namespace std;

int main(int argc, char const *argv[]){

	ifstream ifile("data.txt");

	getline(ifile, line);
	stringstream sn;
	int num_records;
	sn >> num_records;
	cout << "This file contains " << num_records << " records!! WOO!" << endl;

	for(int i = 0; i<num_records; i++){
		string first, last;
		ifile >> first >> last;

		getline(ifile, line);
		stringstream sy(line);
		int year;
		sy >> year;

		vector<string> colors;
		string line, color;

		getline(ifile, line);
		string stream sc(line);
		while(sc >> color)
		{
			colors.push_back(color);
		}
		
		int zip;
		vector<int> zips;
		getline(ifile, line);
		stringstream sz(line);
		while(sz >> zip)
		{
			zips.push_back(zip);
		}

		Person person(last, first, year, colors, zips);
		people.push_back(person);

	}
	people[0].Print();

	return 0;
}