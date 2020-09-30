/*
 * Name: Peter Phan 
 * File Name: participant.cpp
 * Desription: the code expression of partipant.h
 * 
 */ 
#include "participant.h"

Participant::Participant(){
	firstName[0] = '\0';
	lastName[0] = '\0';
	height = 0;
	numberEntries = 0;
    totalMiles = 0;
}
Participant::Participant(const Participant& p){
	strcpy (firstName, p.firstName);
	strcpy (lastName, p.lastName);
	height = p.height;
	numberEntries = p.numberEntries;
    totalMiles = p.totalMiles;
}

void Participant::setActivity(Activity a){
	activity[numberEntries] = a;
	numberEntries++;
}
/*
 * 
 * 
 */ 
void  Participant::setTotalMiles(){
    totalMiles = 0;
	for (int i = 0; i < numberEntries; i++){
		totalMiles += activity[i].getMiles_Equivalent();
        
	}
   // cout << fixed << setprecision(2) << totalMiles << endl;
}

/*
 * opertor< : compares the first name concatenated to the last name of two participants
 * Parameter: p1, p2 - variables hold 2 participant 
 * Return: true or false the result of comparison 
 */ 
bool operator<(const Participant& p1, const Participant& p2){
	char p1Name[MAX_LENGTH];       // temp variable of p1
	strcpy (p1Name, p1.lastName); // copy the p1 first name to variable p1Name. Ex: now p1Name = 'Peter';
	strcat (p1Name, p1.firstName);  // concatenate p1 last name to p1Name. Ex: now p1Name = 'Peter Phan';
  	char p2Name[MAX_LENGTH];		// temp variable of p2
	strcpy (p2Name, p2.lastName); // copy the p1 first name to variable p2Name. Ex: now p2Name = 'Vy';
	strcat (p2Name, p2.firstName);  // concatenate p1 last name to p2Name. Ex: now p2Name = 'Vy Nguyen';
	
	if (strcmp (p1Name, p2Name) < 0) {return true;} // compare the 2 name. Return true if p1 < p2
	else {return false;} 							  // else return false		
}
/*
 * opertor< : compares the first name concatenated to the last name of two participants
 * Parameter: p1, p2 - variables hold 2 participant 
 * Return: true or false the result of comparison 
 */ 
bool operator== (const Participant& p1, const Participant& p2){
	char p1Name[MAX_LENGTH];       // temp variable of p1
	strcpy (p1Name, p1.lastName); // copy the p1 first name to variable p1Name. Ex: now p1Name = 'Peter';
	strcat (p1Name, p1.firstName);  // concatenate p1 last name to p1Name. Ex: now p1Name = 'Peter Phan';
  	char p2Name[MAX_LENGTH];		// temp variable of p2
	strcpy (p2Name, p2.lastName); // copy the p1 first name to variable p2Name. Ex: now p2Name = 'Vy';
	strcat (p2Name, p2.firstName);  // concatenate p1 last name to p2Name. Ex: now p2Name = 'Vy Nguyen';
	
	if (strcmp (p1Name, p2Name) == 0) {return true;} // compare the 2 name. Return true if p1 = p2
	else {return false;} 							  // else return false		
}
/*
 * opertor< : print out the table of participant 
 * Parameter: outFile - the stream of file 
			  p - the participant class 
 * Return: return the outFile work like cout in this operator  
 */ 
ostream& operator<<(ostream& outFile, const Participant& p){
	outFile <<  setw(15) << left << p.firstName;
	outFile << setw (16) << left << p.lastName;
	outFile << setw (12) << right << fixed << setprecision(2) << p.totalMiles;
	cout << endl;

    return outFile;
}



 /* 
  * write: writes the file to a binary output that keeps the participant type. 
  * Parameters: ostream& out - so we can know the file that we are outputting to.
  * Returns: none
  */
void Participant::write(ostream& out){ out.write((char*)this, sizeof(Participant));}

 /* 
  * operator=: to copy one participant to the other 
  * Parameters: Pariticpant& p - the participant we are copying
  * Returns: this - because this is the new participant.
  */
Participant Participant::operator=( const Participant& p ){
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
