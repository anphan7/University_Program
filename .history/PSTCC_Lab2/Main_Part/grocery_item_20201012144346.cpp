#include <stdio.h>
#include <stdlib.h>
#include "grocery_item.h"

void print_prompt(grocery_item_t g){
    std::cout << " Bar code: " << g.barcode << std::endl;
    std::cout << " Description: " << g.name << std::endl;
    std::cout << " Quantity: " << g.quantity << std::endl;
    std::cout << " Best by date: " << g.bestBy.month << " " << g.bestBy.day << " " << g.bestBy.year << std::endl;
    std::cout << std::endl;
}