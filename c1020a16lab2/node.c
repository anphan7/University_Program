#include <stdlib.h>
#include <stdio.h>
#include "node.h"

node_t* initNode( athlete_t athlete ) {

	node_t* nodePtr = (node_t*) malloc( sizeof( node_t ) );
	nodePtr-> a = athlete;
	nodePtr->nextPtr = NULL;
	nodePtr->prevPtr = NULL;
	return nodePtr;

}



