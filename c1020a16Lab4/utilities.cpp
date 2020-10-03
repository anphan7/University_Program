/*
 * Name : Peter Phan
 * Due Date: 4/23/2019
 * Description: this file perform some small task during the program 
 */ 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utilities.h"
#include <iostream>
void to_Lower (char temp[]){
        int i;
	for (i = 0; temp[i] != '\0' ; i++){
                temp[i] = tolower(temp[i]);
        }
}



void to_Upper (char temp[] ){
        int i;
	for (i = 0; temp[i] != '\0' ; i++){
                temp[i] = toupper(temp[i]);
        }
}

void for_space(){
        std::cout << std::endl;
}
