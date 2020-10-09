/*
 * Name: Peter Phan
 * File Name: participant.h
 * Desription: participant.h and participant.cpp that implements a Participant class with private data and public member functions
			Last name. First name. Height in inches
			Array of 365 Activity objects
			Number of valid entries in array of Activity objects
			Set and get functions for private data. You can write the get function for Activity objects with one parameter, an index, and just return the Activity at that index, (i.e., activity[i]).
			Overloaded operator< that compares the first name concatenated to the last name of two participants
			Overloaded operator== that compares the first name concatenated to the last name of two participants
			
 */ 
 
#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "activity.h"
#include <cstring>
#include "utilities.h"
using std::istream;
using std::ostream;
using std::vector;
using std::string;
using std::stod;
using std::stoi;
using std::cout;
using std::fixed;
using std::setprecision;
using std::endl;
using std::setfill;
using std::setw;
using std::left;
using std::right;
const int MAX_LENGTH = 256;

class Participant {
public:

	Participant(){
		firstName[0] = '\0';
		lastName[0] = '\0';
		height = 0;
		numberEntries = 0;
		totalMiles = 0;
	}; // Default constructor
	Participant(const Participant&){};//Copy ctor

	//-----Set and Get private data functions-----
	void setFirstName(const char* f_name ){ strcpy (firstName, f_name);}
	const char* getFirstName() const {return firstName;}
	
	void setLastName(const char* l_name){ strcpy (lastName, l_name);}
	const char* getLastName() const {return lastName;}
	
	void setHeight(double h) { height = h;}
	double getHeight() const {return height;}
	
	void setActivity(Activity){};
	Activity getActivity(int i) const { return activity[i]; }
	
	void setNumber_Entries(int number) { numberEntries = number;}
	int getNumber_Entries() const {return numberEntries;}
	
	void setTotalMiles(){};
	double getTotalMiles() const {return totalMiles;}
	 
	//-----Overload Operator Functions-----
	friend bool operator< (const Participant&, const Participant&){return 0;}; //Overloaded operator< that compares the first name concatenated to the last name of two participants
	friend bool operator== (const Participant&, const Participant&){return 0;}; // Overloaded operator== that compares the first name concatenated to the last name of two participants
	friend ostream& operator<<(ostream& out, const Participant&){return out;}; // Overloaded operator<< that print out 
	Participant operator=( const Participant& ){return *this;};

	//-----Additional Functions-----
	void write(ostream&){};
	Participant& readFile (string);


private:
	char firstName[MAX_LENGTH]; // first name of participant 
	char lastName [MAX_LENGTH]; // last name of participant
	double height; // height in inches
	Activity activity[365]; // Array of 365 Activity objects
	int numberEntries; // Number of valid entries in array of Activity objects
	double totalMiles; // the total miles 
};

#endif