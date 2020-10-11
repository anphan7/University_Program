/*
 * Name : Peter Phan
 * Due Date: 4/23/2019
 * File name: utilities.h
 * Desription: this file perform some small task during the program 
 */ 
#ifndef ULTILIES_H
#define ULTILIES_H
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void to_Lower (char temp[] ){
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

#endif