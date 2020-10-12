#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream inFile, inBin;
    std::ofstream outFile;
    std::string line;
    inFile.open("inventory.txt", std::ios::in);
    outFile.open("grocery.bin", std::ios::binary);
    while (getline (inFile, line, '\n')){
        outFile.write()
    }
    inFile.close();
    outFile.close();
    return 0;
}
