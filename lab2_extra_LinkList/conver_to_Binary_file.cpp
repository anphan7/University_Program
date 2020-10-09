#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using std::ios;
int main(){
	Participant p;
	std::ifstream inFile, inBin; // created the variable of input file
	std::ofstream outFile;
	std::string line;
	inFile.open("inventory.txt");
	outFile.open ("tracking.bin", ios::binary);
	inBin.open ("tracking.bin", ios::binary);
	while (getline (inFile, line, '\n')){
		p.setNumber_Entries(0);
		p.readFile(line);
		outFile.write ((char* )&p, sizeof (Participant) );
		inBin.read ((char*) &p, sizeof (Participant));
		std::cout << p << std::endl;
	}
}