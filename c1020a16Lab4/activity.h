
/*
 *	Name: Peter Phan 
 * 	Due Date: April 23, 2019
 * 	Description: activity.h that implements an Activity class with private data and public member functions listed below.
 *	Some constants to hold activity names, step equivalents and codes. If this (these) constant(s) are in the class, they should be static. 
 *	Some arrays might be nice so that ACTIVITY_NAMES[BASKETBALL_SHOOTING] makes sense. In this example, BASKETBALL_SHOOTING = 1 and ACTIVITY_NAMES[BASKETBALL_SHOOTING] = “basketball”. 
 *	A constant like STEPS[BASKETBALL_SHOOTING] = 136 could also be useful because you could use the activity code as the index to compute steps taken for a particular activity. 
 *	Activity code (from table). Minutes done (i.e., 15 minutes). Default constructor
 *	Set and get functions for private data that doesn’t set data to nonsensical values. The set function for miles equivalent will need a parameter of height.
 *	A function that returns the miles equivalent of the activity (i.e., 15 minutes of tennis = 212*15 = 3180 steps. 
 *	Assuming 2.13 feet per step, that’s 3180 * 2.13 = 6773.4 feet = ~1.28 miles). The function has one parameter, height.
 */ 
#ifndef ACTIVITY_H
#define ACTIVITY_H
#include <cstring>
#include <iostream>
using std::string;

enum { ASSEMBLY_LINE, BASKETBALL_SHOOTING, BASKETBALL_GAME, BICYCLING_UNDER_10MPH, BICYCLING, COOKING, DANCE,
	   FOOTBALL, HIKING, HOUSE_CLEANING, GARDENING, MINI_GOLF, RACQUETBALL, ROWING, RUNNING_6_MPH, RUNNING_7_MPH,
	   RUNNING_8_MPH, SHOPPING, SOCCER, SOFTBALL, STAIRS, SWIMMING_LAPS, TENNIS, WALKING_3_MPH, WALKING_4_MPH, WEIGHT_LIFTING, YOGA
}; // enum type assign activity name ( ASSEMBLY_LINE = 0, ... ,YOGA = 26)
const string ACTIVITIES[] = { "assembly line", "basketball shooting", "basketball game", "bicycling under 10mph", "bicycling", "cooking",
						  "dance", "football", "hiking", "house cleaning", "gardening", "miniature gold", "racquetball", "rowing",
						  "running 6mph", "running 7mph", "running 8mph", "shopping", "soccer", "softball", "stairs", "swimming laps",
						  "tennis", "walking 3mph", "walking 4mph", "weight lifting", "yoga"
};  // const string so that enum type = activities name (ex: [BASKETBALL_SHOOTING] = "basketball shooting")
const int STEPS[] = { 85, 136, 242, 121, 242, 61, 167, 242, 182, 91, 99, 91, 212, 212, 303, 348, 409, 70, 212, 152,
				  273, 212, 212, 100, 152, 121, 76
}; // steps match activities name
class Activity {
public:
	Activity() { activities_code = 0 ; minutes_done = 0; miles_equivalent = 0;}
	
	//------set and get function for private data----
	void setActivities_Code (int code) {activities_code = code;}
	int getActivities_Code() const {return activities_code;}
	
	void setMinutes_Done (int minutes) {minutes_done = minutes;}
	int getMinutes_Done () const {return minutes_done;}
	


	double getMiles_Equivalent() const {return miles_equivalent;}
	
	void clear_stuff() {activities_code = 0; minutes_done = 0;}
/*
 * Function: miles_equivalent - calculate the miles the minutes of a activity to miles
 * Parameter: h - height
 * Return: miles - the miles of equivalent of the activity
 */
double setMiles_Equivalent (double h){
	double f;
	double total;
	f = (0.413 * h) / 12;
	total = minutes_done * STEPS[activities_code] * f;
	miles_equivalent = (total/5280.0); 
	return miles_equivalent;
}
	
private:
	int activities_code; // code of activities
	int minutes_done;    // minutes done one activity
	double miles_equivalent; // miles_equivalent for return the calculated miles.


};

#endif