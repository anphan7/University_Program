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
                else if (strcmp (nPtr -> g.barcode, lPtr -> headPtr -> g.barcode) < 0){ 
				lPtr -> headPtr -> prevPtr = nPtr;
				nPtr -> nextPtr = lPtr -> headPtr;
				lPtr -> headPtr = nPtr;				
		}
		else if (strcmp (nPtr -> g.barcode , lPtr -> tailPtr -> g.barcode) >= 0){
				lPtr -> tailPtr -> nextPtr = nPtr;
				nPtr -> prevPtr = lPtr -> tailPtr;
				lPtr -> tailPtr = nPtr;
		}
		else {
			curPtr = lPtr -> headPtr;
			while(curPtr != NULL){
				if (strcmp (nPtr -> g.barcode, curPtr  -> g.barcode ) < 0){
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


