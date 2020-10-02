#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ultilies.h"
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
void clearBuffer (FILE* inFile){
	while (getchar () != '\n');
}
int checkDigit(char a[]){
        int i;
        for (i = 0; a[i] = '\0'; i++){
                if (isdigit(a[i]) == 0 )
                        return FALSE;
        }
        return TRUE;
}


