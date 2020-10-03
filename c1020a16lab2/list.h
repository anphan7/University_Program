#ifndef DBL_LINKED_LIST_H
#define DEL_LINKED_LIST_H
#include "node.h" 

#define NOT_FOUND -1
#define MAX_CHAR 256
#define TRUE 1
#define FALSE 0
typedef struct {
	node_t* headPtr;
	node_t* tailPtr;
} dbl_linked_list_t;

void createList( dbl_linked_list_t* );
void insertNode( dbl_linked_list_t*, node_t* );
void deleteList (dbl_linked_list_t*);
int find_Country(const dbl_linked_list_t*, int*, int*, int*,char*);
void find_Athlete (const dbl_linked_list_t*, char*, int);
void traverseStack (const dbl_linked_list_t*);
#endif
