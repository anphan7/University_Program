#include "grocery.h"

Grocery::Grocery(){
    barcode[0] = '\0';
	name[0] = '\0';
	quantity = 0;
    numberEntries = 0;
}
Grocery::Grocery (const Grocery& g){ // copy constructor  
    strcpy (barcode, g.barcode);
    strcpy (name, g.name);
    quantity = g.quantity;
    numberEntries = g.numberEntries;
}
void Grocery::setBestBy(Date d){
    bestBy[numberEntries] = d;
    numberEntries++;
}
Grocery& Grocery::readFile(std::string line){
    std::string token;
    Date d;
    bool b_c = true;
    bool n = false;
    bool q = false;
    bool m = false; 
    bool the_d = false;
    bool y = false;
    line = line + ",";
    size_t found = line.find(",");
    token = line.substr(0, found);

    while (found != std::string::npos){
        if (b_c){
            setBarCode(token.c_str());
            b_c = false;
            n = true;
            //std::cout << token << " " ;
        }
        else if (n){
            setName(token.c_str());
            n = false;
            q = true;
            //std::cout << token << " " ;
        }
        else if (q){
            setQuantity(stoi(token));
            q = false;
            m = true;
            //std::cout << token << " " ;

        }
        else if (m){
            d.setMonth(stoi(token));
            m = false;
            the_d = true;
            //std::cout << token << " " ;

        }
        else if (the_d){
            d.setDay(stoi(token));
            the_d = false;
            y = true;
            //std::cout << token << " " ;

        }
        else if (y){
            d.setYear(stoi(token));
            y = false;
            the_d = true;
            //std::cout << token << " " ;
            //std::cout << std::endl;
        }
        line.erase(0, found + 1);
        found = line.find(",");
        token = line.substr(0, found);
    }

    return *this;
}

ostream& operator<< (ostream& outFile, const Grocery& g){
    Date d;
    outFile << g.barcode << " " << g.bestBy << " " << g.quantity << " " ;
    for (int i = 0; i < g.numberEntries; i++){
        outFile << g.bestBy[i].getDay() << " ";
        outFile << g.bestBy[i].getMonth() << " ";
        outFile << g.bestBy[i].getYear() << " ";
    }
    return outFile;
}
