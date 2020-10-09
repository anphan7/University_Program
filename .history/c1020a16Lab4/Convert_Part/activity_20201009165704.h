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
	Activity() {activities_code = 0 ; minutes_done = 0;}
	
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
	double total = 0;
	f = (0.413 * h) / 12;
	total = minutes_done * STEPS[activities_code] * f;
	miles_equivalent = (total/5280.0); 
	return miles_equivalent;
}
	
private:
	int activities_code; // code of activities
	int minutes_done;    // minutes done one activity
	double miles_equivalent;
};

#endif