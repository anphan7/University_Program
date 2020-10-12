#ifndef LIST_H
#define LIST_H
#include <cstring>
#include <iostream>
#define MAX_LENGTH 256
#include "date.h"

struct grocery_item_t {   
    char barcode[15];
    char name[MAX_LENGTH];
    int quantity;
    date_t bestBy;    	
};

void print_prompt(grocery_item_t g){
    std::cout << " Bar code: " << g.barcode << std::endl;
    std::cout << " Description: " << g.name << std::endl;
    std::cout << " Quantity: " << g.quantity << std::endl;
    std::cout << " Best by date: " << g.bestBy.month << " " << g.bestBy.day << " " << g.bestBy.year << std::endl;
}
#endif
