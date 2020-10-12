#include <iostream>
#include <fstream>
#include <string>
#include "grocery_item.h"

int main(){
    std::ifstream inFile, inBin;
    std::ofstream outFile;
    std::string line;
    grocery_item_t g;
    inFile.open("inventory.txt", std::ios::in);
    outFile.open("grocery.bin", std::ios::out | std::ios::binary);
    while (getline (inFile, line, '\n')){
         std::cout << line << std::endl; // cout information from file
        outFile.write((char*)&g, sizeof (grocery_item_t)); // write to grocery.bin 
        inBin.read((char*)&g, sizeof (grocery_item_t));
    }
    inFile.close();
    outFile.close();
    return 0;
}
