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
	} // Default constructor
	Participant(const Participant& p){
		strcpy (firstName, p.firstName);
		strcpy (lastName, p.lastName);
		height = p.height;
		numberEntries = p.numberEntries;
		totalMiles = p.totalMiles;
	}//Copy ctor

	//-----Set and Get private data functions-----
	void setFirstName(const char* f_name ){ strcpy (firstName, f_name);}
	const char* getFirstName() const {return firstName;}
	
	void setLastName(const char* l_name){ strcpy (lastName, l_name);}
	const char* getLastName() const {return lastName;}
	
	void setHeight(double h) { height = h;}
	double getHeight() const {return height;}
	
	void setActivity(Activity a){
		activity[numberEntries] = a;
		numberEntries++;
	}
	Activity getActivity(int i) const { return activity[i]; }
	
	void setNumber_Entries(int number) { numberEntries = number;}
	int getNumber_Entries() const {return numberEntries;}
	
	void setTotalMiles(){
		totalMiles = 0;
		for (int i = 0; i < numberEntries; i++){
				totalMiles += activity[i].getMiles_Equivalent();
		}	
	}
	double getTotalMiles() const {return totalMiles;}
	 
	//-----Overload Operator Functions-----
	friend bool operator< (const Participant& p1, const Participant& p2){
		char p1Name[MAX_LENGTH];       // temp variable of p1
		strcpy (p1Name, p1.lastName); // copy the p1 first name to variable p1Name. Ex: now p1Name = 'Peter';
		strcat (p1Name, p1.firstName);  // concatenate p1 last name to p1Name. Ex: now p1Name = 'Peter Phan';
		char p2Name[MAX_LENGTH];		// temp variable of p2
		strcpy (p2Name, p2.lastName); // copy the p1 first name to variable p2Name. Ex: now p2Name = 'Vy';
		strcat (p2Name, p2.firstName);  // concatenate p1 last name to p2Name. Ex: now p2Name = 'Vy Nguyen';
	
		if (strcmp (p1Name, p2Name) < 0) {return true;} // compare the 2 name. Return true if p1 < p2
		else {return false;} 							  // else return false		
	} //Overloaded operator< that compares the first name concatenated to the last name of two participants
	
	friend bool operator== (const Participant& p1, const Participant& p2){
		char p1Name[MAX_LENGTH];       // temp variable of p1
		strcpy (p1Name, p1.lastName); // copy the p1 first name to variable p1Name. Ex: now p1Name = 'Peter';
		strcat (p1Name, p1.firstName);  // concatenate p1 last name to p1Name. Ex: now p1Name = 'Peter Phan';
		char p2Name[MAX_LENGTH];		// temp variable of p2
		strcpy (p2Name, p2.lastName); // copy the p1 first name to variable p2Name. Ex: now p2Name = 'Vy';
		strcat (p2Name, p2.firstName);  // concatenate p1 last name to p2Name. Ex: now p2Name = 'Vy Nguyen';
		
		if (strcmp (p1Name, p2Name) == 0) {return true;} // compare the 2 name. Return true if p1 = p2
		else {return false;} 							  // else return false		
	} // Overloaded operator== that compares the first name concatenated to the last name of two participants
	
	friend ostream& operator<<(ostream& outFile, const Participant& p){
		outFile <<  setw(15) << left << p.firstName;
		outFile << setw (16) << left << p.lastName;
		outFile << setw (12) << right << fixed << setprecision(2) << p.totalMiles;
		cout << endl;

		return outFile;
	} // Ovverloaded operator<< that print out 
	Participant operator=( const Participant& p ){
		if(this != &p){
			strcpy(firstName, p.firstName);
			strcpy(lastName, p.lastName);
			height = p.height;
			totalMiles = p.totalMiles;
			numberEntries = p.numberEntries;
			for(int i = 0; i < p.numberEntries; i++){
				activity[i] = p.getActivity(i);
			}
    	}
    return *this;
	}

	//-----Additional Functions-----
	//void write(ostream&);
	void write(ostream& out){ out.write((char*)this, sizeof(Participant));}


private:
	char firstName[MAX_LENGTH]; // first name of participant 
	char lastName [MAX_LENGTH]; // last name of participant
	double height; // height in inches
	Activity activity[365]; // Array of 365 Activity objects
	int numberEntries; // Number of valid entries in array of Activity objects
	double totalMiles; // the total miles 
};

#endif