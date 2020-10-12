#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
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

void search_Barcode (const dbl_linked_list_t* lPtr, char barcode_key[], int size){
	node_t* curPtr;
	int found_One = FALSE;
	char temp[MAX_LENGTH];
	curPtr = lPtr -> headPtr;
	while (curPtr != NULL){
		strcpy(temp, curPtr -> g.barcode);
		to_Lower(temp);
		if (strncmp (temp, barcode_key, size -1 ) == 0){
			found_One = TRUE;
		}
		curPtr = curPtr -> nextPtr;
	}
	if (found_One == FALSE){
		std::cout << " There is no match for this BARCODE. " << std::endl;
	}
}
