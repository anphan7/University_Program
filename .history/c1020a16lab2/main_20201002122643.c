/* File: main.c
   Name: Peter Phan
   Description:
   Problem: 
	    can't match name with space
	    medal stuff 
	    empty file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "athlete.h"
#include "ultilies.h"
#include "node.h"
#include "list.h"

void print_Medal (int gold, int silver, int bronze);
int main (int argc, char* argv[]){
	FILE* inFile;
	dbl_linked_list_t list; // send list by reference everytime use 
	node_t* nodePtr;
	athlete_t a;
	char fileName[MAX_CHAR];
	char choice[MAX_CHAR];
	int choice_number;
	char answer[MAX_CHAR];
	int i , c;
	if (argc == 2 ){
		strcpy (fileName, argv[1]);
		inFile = fopen (fileName, "rb");
	}
	else {
		printf ("Usage: lab2 filename\n");
		return (0);
	}
	if (inFile == 0){
		printf("Input file %s is doesn't exist. Please contact the administrator.\n", argv[1]);
		return (0);
	}
	c = fgetc(inFile);
	if (c == EOF){
		printf("Input file %s is empty. Please contact the administrator.\n", argv[1]);
                return (0);
	}
	else{
		ungetc(c, inFile);


	}
	if (inFile != NULL){
		createList (&list);
		// if inFile != NULL
		fread(&a, sizeof(athlete_t), 1, inFile); // inside sizeof need type
		while ( !feof (inFile) ){
			nodePtr = initNode(a);
			insertNode (&list, nodePtr); 
			fread(&a, sizeof(athlete_t), 1, inFile); 
		}
		fclose (inFile); // close the file 
		do{
			printf ("Welcome to 2016 Summer Olympics statistics\n");
			printf ("	1 Search by country code\n");        
		        printf ("	2 Search by athlete\n");
       	 		printf ("	3 Exit\n");        
        		printf ("	Option? ");
        		scanf ("%s", choice);
			getchar();
			for (i = 0 ; choice[i] != '\0'; i++){
				if (isdigit(choice[i])){
					atoi (choice);
				}
				else {
					printf("Invalid option: %s\n", choice);
					break;
				}
			}
			choice_number = atoi(choice);
			if (choice_number > 3 ){
				printf(" Invalid option: %d\n", choice_number);
			}
			else if (choice_number == 1){
				int gold = 0;
				int silver = 0;
				int bronze = 0;
				printf("Country code: ");
				scanf ("%s", answer);
				to_Upper(answer);
				printf("%s Medals\n", answer);
				int country_Code = find_Country(&list, &gold, &silver, &bronze, answer);
				if (country_Code){
					print_Medal (gold, silver, bronze);		 
			
				}
				else
					printf("There is not a match for this country code\n");
			}
			else if (choice_number == 2){
				printf("Athlete: ");
				fgets (answer, MAX_CHAR, stdin);
				int size = strlen (answer);
				to_Lower (answer);
				answer [size-1] = '\0' ;
				find_Athlete (&list, answer, size );
				
			}
			else if (choice_number == 3) {
				printf("Thank you for using the program\n");
				return (0);
			}
			
		}while (choice_number != 3);
		deleteList (&list);		

	}
}

void print_Medal (int gold, int silver, int bronze){
        printf("Gold   Silver   Bronze\n");
        printf( "--------------------------\n" );
        printf( "%4d%8d%9d\n", gold, silver, bronze);
}

