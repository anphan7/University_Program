#ifndef LIST_H
#define LIST_H
#include <cstring>
#include <iostream>
#define MAX_LENGTH 365

struct date_t{
    int month, day, year;
};

struct grocery_item_t {   
    char barcode[15];
    char name[MAX_LENGTH];
    int quantity;
    date_t bestBy;    	
};


#endif