#include <iostream>
#include <fstream>
#include <string>
#include "grocery.h"
#include "date.h"
int main(){
    std::ifstream inFile, inBin;
    std::ofstream outFile;
    std::string line;
    Grocery g;
    inFile.open("inventory.txt", std::ios::in);
    outFile.open("grocery.bin", std::ios::out | std::ios::binary);
    while (getline (inFile, line, '\n')){

        //g.setNumber_Entries(0);
        g.readFile(line);    
        outFile.write((char*)&g, sizeof (Grocery)); // write to grocery.bin 
        inBin.read((char*)&g, sizeof (Grocery));
        //std::cout << line << std::endl; // cout information from file

    }
    inFile.close();
    outFile.close();
    return 0;
}
