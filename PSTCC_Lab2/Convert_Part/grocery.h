#ifndef LIST_H
#define LIST_H
#include <cstring>
#include <string>
#include <iostream>
#define MAX_LENGTH 365
#include "date.h"


class Grocery {  
public:
    Grocery(); // default constructor
    Grocery (const Grocery&); // copy constructor  

    //-Set and Get functions for data and 
    void setBarCode (const char* temp_barcode) {strcpy (barcode, temp_barcode);}
    const char* getBarCode() const {return barcode;}

    void setName (const char* temp_name) {strcpy (name, temp_name); }
    const char * getName () const {return name;}

	void setQuantity(int temp_quantity) { quantity = temp_quantity;}
	double getQuanity() const {return quantity;}

    void setBestBy (Date);
    Date getBestBy (int i ) const {return bestBy[i]; }

    void setNumber_Entries(int number) { numberEntries = number;}
	int getNumber_Entries() const {return numberEntries;}

   //--Additional functions--
   	Grocery& readFile (std::string);




private: 
    char barcode[15];
    char name[MAX_LENGTH];
    int quantity;
    Date bestBy [MAX_LENGTH];    	
    int numberEntries; // Number of valid entries in array of Date objects

};


#endif