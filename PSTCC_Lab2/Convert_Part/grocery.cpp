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
    line = line + ",";
    size_t found = line.find(",");
    token = line.substr(0, found);

    while (found != std::string::npos){
        if (b_c){
            setBarCode(token.c_str());
            b_c = false;
            n = true;
            std::cout << token << " ";
        }
        else if (n){
            setName(token.c_str());
            n = false;
            q = true;
            std::cout << token << " " ;
        }
        else if (q){
            setQuantity(stod(token));
            q = false;
            m = true;
        }
        line.erase(0, found + 1);
        found = line.find(",");
        token = line.substr(0, found);
    }

    return *this;
}