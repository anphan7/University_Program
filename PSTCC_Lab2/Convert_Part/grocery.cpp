#include "grocery.h"

Grocery::Grocery(){
    barcode[0] = '\0';
	name[0] = '\0';
	quantity = 0;
}
Grocery::Grocery (const Grocery& g){ // copy constructor  
    strcpy (barcode, g.barcode);
    strcpy (name, g.name);
    quantity = g.quantity;
}
void Grocery::setBestBy(Date d){
    bestBy[numberEntries] = d;
    numberEntries++;
}
Grocery& Grocery::readFile(std::string line){
    std::string token;
    Grocery g;
    bool b_c = true;
    bool n, q, m, the_d, y = false;
    

    return *this;
}