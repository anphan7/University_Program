/*
 *	Name: Peter Phan 
 * 	Due Date: April 23, 2019
 * 	Description: This application is some of the code that might go into a fitness application. 
 *  It allows the user to input an activity and the number of minutes spent on that activity then calculates the equivalent number of steps walked. 
 * 	It is the code that might be part of an app for a Fitbitâ˘, for example.
 * 
 * 
 */ 
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
#include "activity.h"
#include "binarySearchTree.h"
#include "node.h"
#include "position.h"
#include "participant.h"
#include "utilities.h"
int main(){
	Participant p;  // variable for participant class
	BinarySearchTree<Participant> tree; // variable for the tree
	ifstream inFile; // variable for input file
    int option, activity_code; 
    char first_Name [MAX_LENGTH];
    char last_Name [MAX_LENGTH];	
	double heightInInches, minutes;
    char choice[256];
    char c;
	Participant temp;
	Activity a;
    cout << " Hello " << endl;
	inFile.open("tracking.bin", ios::binary); // open the file named "tracking.bin" in binary mode
    if (inFile.fail()){ // if the file can't open because there are no file 
        cout << "---THE BINARY INPUT FILE DOES NOT EXIST. CREATING AN EMPTY TREE--- " << endl;
        cout << endl;
    }
    inFile.get(c); // get a char from the file to check for empty 
    if (!inFile.eof()){ // if the file is not end of file
		inFile.putback(c); // put the character back to file
	}
	else if (inFile.eof()){ // if the file is empty 
		cout << "---THE BINARY INPUT FILE IS EMPTY. CREATING AN EMPTY TREE---" << endl;
        cout << endl;
    }
    while (inFile.read ((char*)&p, sizeof (Participant))){ // read in whatever the file have 
        p.setTotalMiles(); // set the total miles for future use
        tree.insert(p); // insert everybody to the tree until it end of file 
    }
    inFile.close(); // close the file after use 
	//tree.traverseAndPrint(tree.root(), PREORDER); // test 
	
	
		cout << "---Welcome to Fitness Tracking App---" << endl; // welcome message
		do{	
			cout << " Choose One Of The Following Opition " << endl; // the menu drop down
			cout << " 1 Remove Participant " << endl;
			cout << " 2 Add Participant " << endl;
			cout << " 3 Add Activity " << endl;
			cout << " 4 Calculate Total Miles Walked " << endl;
			cout << " 5 Pre-order Print " << endl;
			cout << " 6 Exit and Save " << endl;
			cout << " Option> " ; //option intake from user
			cin >> choice;
			getchar();
			for (int i = 0 ; choice[i] != '\0'; i++){ // check every char in choice
				if (isdigit(choice[i])){ // if the choice is number
					atoi (choice);
				} 
			}
			option = atoi(choice); // if the choice is number. Cast it to int
			if (option == 1){
                cout << "---Removing a participant---" << endl;
				cout << " Last Name: " ; // asking for last name 
				cin >> last_Name;
				cout << " First Name: "; // asking for first name 
				cin >> first_Name;
                to_Lower (last_Name); // make to lower case last and first name 
				to_Lower (first_Name);
				first_Name[0] = toupper (first_Name[0]); // make the first and last name's letter to upper case
				last_Name[0] = toupper (last_Name[0]);
                temp.setLastName(last_Name); // set the new last and first name to search
				temp.setFirstName(first_Name);
				Position<Participant> t = tree.find (temp);
				if (t.getItem() == temp){  // if the program found a matching 
					cout << " Participant " << t.getItem().getFirstName()<< " " << t.getItem().getLastName() <<" "
											<< fixed << setprecision(2) << t.getItem().getTotalMiles() << " total miles walked removed " << endl;
					tree.erase(temp); // remove the participant from the tree
                    for_space();
				}
				else {cout << first_Name << " " << last_Name << " is not a participant. " << endl;}	// if participant not in the tree
			}
			else if (option == 2){ 
                cout << " ---Adding a participant--- " << endl;
				cout << " Last Name: " ; // asking for last name 
				cin >> last_Name;
				cout << " First Name: "; // asking for first name 
				cin >> first_Name;
                to_Lower (last_Name); // make to lower case last and first name 
				to_Lower (first_Name);
				first_Name[0] = toupper (first_Name[0]); // make the first and last name's letter to upper case
				last_Name[0] = toupper (last_Name[0]);
                temp.setLastName(last_Name); // set the new last and first name to search
				temp.setFirstName(first_Name);
				Position<Participant> t = tree.find (temp);
				
				if (t.getItem() == temp) {cout << first_Name << " " << last_Name << " is already a participant. " << endl;} // can't add new participant if they already a memeber 
				else {
					cout << " Height in inches: "; // asking for inches
					cin >> heightInInches;
					p.setFirstName(first_Name); // set new first, last name, and height 
					p.setLastName(last_Name);
					p.setHeight(heightInInches);
					p.setNumber_Entries(0);
					tree.insert(p); // insert new people into the tree 
                    cout << first_Name << " " << last_Name << " with " << heightInInches << " added " << endl; // message to let user know participant was added 
                    cout << endl;
                    for_space();
				}
			}
			else if (option == 3){
                cout << " ---Adding an activity for a participant--- " << endl;
				string tempActivityName;
				cout << " Last Name: " ;// asking for last name 
				cin >> last_Name;
				cout << " First Name: ";// asking for first name 
				cin >> first_Name;
                to_Lower (last_Name); // make to lower case last and first name
				to_Lower (first_Name);
				first_Name[0] = toupper (first_Name[0]);// make the first and last name's letter to upper case
				last_Name[0] = toupper (last_Name[0]);
                temp.setLastName(last_Name);// set the new last and first name to search
				temp.setFirstName(first_Name);
				Position<Participant> t = tree.find (temp);

				if (t.getItem() == temp ){
					
					cout << " ***--CHOOSE THE ACTIVITY FROM THE LIST BELOW--*** " << endl; // ask activity 
					cout << " Assembly Line = 0 " << endl;
                    cout << " Basketball (shooting baskets) = 1 " << endl;
                    cout << " Basketball game = 2 " << endl;
                    cout << " Bicycling under 10mph = 3 " << endl;
                    cout << " Bicycling = 4" << endl;
                    cout << " Cooking = 5 " << endl;
                    cout << " Dance = 6 " << endl;
                    cout << " Football = 7 " << endl;
                    cout << " Hiking = 8 " << endl;
                    cout << " House cleaning = 9 " << endl;
                    cout << " Gardening = 10 " << endl;
                    cout << " Miniature golf = 11 " << endl;
                    cout << " Racquetball = 12 " << endl;
                    cout << " Rowing = 13 " << endl;
                    cout << " Running 6 mph = 14 " << endl;
                    cout << " Running 7 mph = 15 " << endl;
                    cout << " Running 8 mph = 16 " << endl;
                    cout << " Shopping = 17 " << endl;
                    cout << " Soccer = 18 " << endl;
                    cout << " Softball = 19" << endl;
                    cout << " Stairs = 20 " << endl;
                    cout << " Swimming laps = 21" << endl;
                    cout << " Tennis = 22 " << endl;
                    cout << " Walking 3mph = 23 " << endl;
                    cout << " Walking 4mph = 24 " << endl;
                    cout << " Weight lifting = 25 " << endl;
                    cout << " Choice: ";
                    cin >> activity_code;
					cout << " Minutes: " ; // and minutes they did 
					cin >> minutes;
					
					a.setMinutes_Done(minutes);  // set new minutues
					a.setActivities_Code(activity_code); // set new activity
					a.setMiles_Equivalent(t.getItem().getHeight()); // calculate the miles they got 
					
					temp = tree.find(p).getItem();
					tree.erase(p);  // erase old participant because constant variable 
					temp.setActivity(a); // set the activity for new people 
					temp.setTotalMiles(); // set total miles for new people
					tree.insert(temp); // insert new people to the tree 
					tempActivityName = ACTIVITIES[activity_code]; 
					a.setActivities_Code(activity_code); // set the activity code 
					
					cout << " Added " << first_Name << " " << last_Name << ", " << ACTIVITIES[activity_code] 
						 << " "<< minutes << " minutes = " << fixed << setprecision(2) << a.getMiles_Equivalent()  << endl;
                    for_space();
                }
				else{
                    cout << first_Name << " " << last_Name << " is not a participant." << endl;
                    for_space();
                }
			
			
			}
			else if (option == 4){
                cout << " ---Calculating the total miles of everyone in the tree--- " << endl;
				double total = tree.traverseAndCalcTotalMiles(tree.root()); // call this function to calculate the total miles of everyone in the tree 
				cout << " Total miles walked by *everyone* = " << total << "!"  << endl;
				for_space();
			}
			else if (option == 5){
				cout  << "\t\tTracking Result " << endl;
				cout << setw(50) << setfill('-') << "-" << setfill(' ') << endl; 
				tree.traverseAndPrint(tree.root(), PREORDER); // print from the tree 
                for_space();
            }
			else if (option == 6){
				cout << "Exiting and saving the contents to filename \"tracking.bin.\"" << endl;
                ofstream outFile; // variable of the out file 
                outFile.open("tracking.bin", ios::binary); // open the tracking.bin in binary mode again to overwrite  
                tree.writeTree(outFile, tree.root()); // write to the file 
                for_space();
                return 0;
			
			}
			else { cout << " Invalid input. Please choose your option again" << endl;} // if user input something other than number or invalid numbers
			
			
		} while (option != 6);  // if user don't want to exit, keep the program running. 
	
	
 
	return 0;
}
