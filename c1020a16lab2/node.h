#ifndef NODE_H
#define NODE_H
#include "athlete.h"
typedef struct node_t {
	athlete_t a;
	struct node_t* nextPtr;
	struct node_t* prevPtr;
} node_t;

node_t* initNode( athlete_t );

#endif
