#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "node.h"
#include "grocery_item.h"
#include "utilities.h"
void createList ( dbl_linked_list_t* lPtr){

	lPtr -> headPtr = NULL;
	lPtr -> tailPtr = NULL;

}

void insertNode ( dbl_linked_list_t* lPtr, node_t* nPtr){
	node_t* curPtr;
        if ( lPtr != NULL ){
                if ( lPtr -> headPtr == NULL){
                        lPtr -> headPtr = nPtr; // get the same address of n
                        lPtr -> tailPtr = nPtr;
                 }
		// if nPtr need to be insert before the head of the list
                else if (strcmp (nPtr -> g.name, lPtr -> headPtr -> g.name) < 0){  // name of each item will be different
				lPtr -> headPtr -> prevPtr = nPtr;
				nPtr -> nextPtr = lPtr -> headPtr;
				lPtr -> headPtr = nPtr;				
		}
		else if (strcmp (nPtr -> g.name , lPtr -> tailPtr -> g.name) >= 0){
				lPtr -> tailPtr -> nextPtr = nPtr;
				nPtr -> prevPtr = lPtr -> tailPtr;
				lPtr -> tailPtr = nPtr;
		}
		else {
			curPtr = lPtr -> headPtr;
			while(curPtr != NULL){
				if (strcmp (nPtr -> g.name, curPtr  -> g.name ) < 0){
					nPtr -> nextPtr = curPtr;
                                        nPtr -> prevPtr = curPtr -> prevPtr;
                                        curPtr -> prevPtr -> nextPtr = nPtr;
                                        curPtr -> prevPtr = nPtr;
					break;

			}				
			curPtr= curPtr -> nextPtr;

			}				
		}
	}	
}

void deleteList ( dbl_linked_list_t* lPtr ){
	
	node_t* curPtr;
	
	if( lPtr != NULL && lPtr -> headPtr != NULL){

		curPtr = lPtr -> headPtr;
		while(curPtr != NULL){
			lPtr -> headPtr = curPtr -> nextPtr;
			free(curPtr);
			curPtr = lPtr -> headPtr;
		}
	}
	lPtr -> tailPtr = NULL;

}

void search

void find_Athlete (const dbl_linked_list_t* lPtr, char key_name[], int size){
	node_t* curPtr;
	int foundOne = FALSE;
	char temp [256];
	curPtr = lPtr -> headPtr;
	while (curPtr != NULL){
		strcpy (temp, curPtr -> a.name);
		to_Lower (temp);
		if (strncmp (temp, key_name, size - 1) == 0){
			foundOne = TRUE;
			print_Athlete (curPtr -> a);
		}
		curPtr = curPtr -> nextPtr;
	}
	if (foundOne == FALSE){
		printf (" There is no match for this athlete name\n");
	}
		
}