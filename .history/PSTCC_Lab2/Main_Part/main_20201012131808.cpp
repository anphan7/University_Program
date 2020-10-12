#include <iostream>
#include <fstream>
#include "date.h"
#include "grocery_item.h"
#include "node.h"
#include "utilities.h"
#include "list.h"

int main(){
    grocery_item_t g;  // variable for participant class
	std::ifstream inFile; // variable for input file
    char c;

	inFile.open("tracking.bin", std::ios::binary); // open the file named "tracking.bin" in binary mode
    if (inFile.fail()){ // if the file can't open because there are no file 
        std::cout << "---THE BINARY INPUT FILE DOES NOT EXIST--- " << std::endl;
        for_space();
    }
    inFile.get(c); // get a char from the file to check for empty 
    if (!inFile.eof()){ // if the file is not end of file
		inFile.putback(c); // put the character back to file
	}
	else if (inFile.eof()){ // if the file is empty 
		std::cout << "---THE BINARY INPUT FILE IS EMPTY---" << std::endl;
        for_space();
    }
    while (inFile.read ((char*)&p, sizeof (grocery_item_t))){ // read in whatever the file have 
            
    }
    inFile.close(); 



    return 0;
}