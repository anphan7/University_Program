#ifndef NODE_H
#define NODE_H
#include "grocery_item.h"

typedef struct node_t {
	grocery_item_t g;
	struct node_t* nextPtr;
	struct node_t* prevPtr;
} node_t;

node_t* initialize_a_Node( grocery_item_t );

#endif