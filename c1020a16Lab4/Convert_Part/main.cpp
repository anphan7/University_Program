#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;
#include "activity.h"
#include "participant.h"
int main(){
	Participant p;
	ifstream inFile, inBin; // created the variable of input file
	ofstream outFile;
	string line;
	inFile.open("textFile.txt", ios::in);
	outFile.open ("tracking.bin", ios::binary);
	inBin.open ("tracking.bin", ios::binary);
	while (getline (inFile, line, '\n')){
		p.setNumber_Entries(0);
		p.readFile(line);
		outFile.write ((char* )&p, sizeof (Participant) );
		inBin.read ((char*) &p, sizeof (Participant));
		//cout << line << endl;
	}	

	inFile.close();
	inBin.close();
}