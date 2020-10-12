#include <iostream>
#include <fstream>
#include "date.h"
#include "grocery_item.h"
#include "node.h"
#include "utilities.h"
#include "list.h"

int main(){
    grocery_item_t g;  // variable for participant class
    dbl_linked_list_t list;
	std::ifstream inFile; // variable for input file
    node_t* nodePtr;
    char c;

	inFile.open("grocery.bin", std::ios::binary); // open the file named "tracking.bin" in binary mode
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
    createList(&list);
    inFile.read ((char*)& g, sizeof (grocery_item_t)); // read in whatever the file have 
        while (!inFile.eof()){
            nodePtr = initialize_a_Node(g);
            insertNode (&list, nodePtr);
            inFile.read((char*)& g, sizeof (grocery_item_t));
            print_prompt(g);
        }
    inFile.close(); 



    return 0;
}
