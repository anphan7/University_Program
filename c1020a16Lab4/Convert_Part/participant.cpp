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
void  Participant::setTotalMiles(){
    totalMiles = 0;
	for (int i = 0; i < numberEntries; i++){
		totalMiles += activity[i].getMiles_Equivalent();
        //cout << activity[i].getMiles_Equivalent() << endl;
        //cout << totalMiles << endl;
	}
    cout << fixed << setprecision(2) << totalMiles << endl;
}



ostream& operator<< (ostream& outFile, const Participant& p){
	outFile << p.firstName << " " << p.lastName << " " << p.height << " ";
	for (int i = 0; i< p.numberEntries; i++){
		outFile << p.activity[i].getActivities_Code() <<" ";
		outFile << p.activity[i].getMinutes_Done() << " ";
        //outFile << p.activity[i].getMiles_Equivalent() << " ";
	}
		
		return outFile;
	}
Participant& Participant::readFile(string line){
		string token;
		Activity a;
	bool fn = true;
	bool ln = false;
	bool h = false; // height
	bool a_c = false; // activty code
	bool m = false; // minutes
	line = line + ",";
	size_t found = line.find(",");
	token = line.substr(0, found);
	
	while (found != string::npos){
		if (fn) {
			setFirstName(token.c_str());
			fn = false;
			ln = true;
			//cout << p.firstName << " ";
		}
		else if (ln){
			setLastName (token.c_str());
			ln = false;
			h = true;
			//cout << token << " ";
		}
		else if (h){
			setHeight (stod(token));
			h = false;
			a_c = true;
			//cout << token << " ";
		}
		else if (a_c){
			a.setActivities_Code(stoi(token));
			a_c = false;
			m = true;
			//cout << token << " ";

		}
		else if (m){
			a.setMinutes_Done(stod (token) );
			a.setMiles_Equivalent(height);
			setActivity(a);
			m = false;
			a_c = true;
			//a.clear_stuff();
			//cout << token << " ";
		}
		line.erase (0, found + 1);
		found = line.find(",");
		//cout << p << endl;
		token = line.substr(0, found);
	}
    //setTotalMilesofOne();
    setTotalMiles() ;
	return *this;
}