#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "node.h"

node_t* initialize_a_Node( grocery_item_t grocery ) {

	node_t* nodePtr = (node_t*) malloc( sizeof( node_t ) );
	nodePtr-> g = grocery;
	nodePtr->nextPtr = NULL;
	nodePtr->prevPtr = NULL;
	return nodePtr;

}