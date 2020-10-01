/*
 * Name: Peter Phan
 * Due Date: April 2nd, 2019
 * Description: Racer class create variables 
 */ 
#ifndef RACER_H
#define RACER_H
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include "sensor.h"

using std::vector;
using std::stringstream;

class Racer
{
public:
    Racer();//default constructor
    Racer(const Racer&);//copy constructor
    
    virtual ~Racer(){}//deconstructor
     
     //These two functions are used to get and set the Number of the racer.
	void setRacerNum(int number){racerNum = number;}
    int getRacerNum() const {return racerNum;}
	void setRacerName(std::string name){racerName = name;}
    string getRacerName() const {return racerName;}
	void setRacerSensor(vector<Sensor> sensor_racer){ racerSensor = sensor_racer;}
	vector<Sensor> getRacerSensor() const {return racerSensor;}
	void setTotalSensors( unsigned int total_Sensor){totalSens = total_Sensor;}
	unsigned int getTotalSensors() const {return totalSens;}
    double calcTotalRaceTime(Sensor&);
    void setTotalRaceTime(double total) {if(total != 0){totalRaceTime = total;}}
    double getTotalRaceTime() const { return totalRaceTime; }
    //This is a function that can be used to compare total times of racers.
    bool cmpTotalTime(int i, int j) { return i < j; }
	void setTotalSpeed(double speed) {totalSpeed = speed;}
    double getTotalSpeed() const { return totalSpeed; }
	void setTotalDistance(double distance){totalDist = distance;}
    double getTotalDistance() const { return totalDist; }
    void setStartTimeRace(string);
    double getStartTimeofRaceInMS() const {return startTimeofRaceInMS;}
    void setStartTimeofRacerInMS(TimeStamp&);
    double getStartTimeofRacerInMS() const {return startTimeofRacerInMS;}
    //Check the cheater set and get function
	void setisCheater(Racer& r){isCheater = r.isCheater;}    
	bool getisCheater() {return isCheater;}
    
    //overloaded operators 
    friend istream& operator>>( istream&, Racer& );//This is to store the elements from the file.
    friend bool operator<( const Racer& r1, const Racer& r2 ){ return r1.totalRaceTime < r2.totalRaceTime; }
    //This is to compare the racer objects.
    
    //this is the overloaded= operator that accompanies the copy constructor.
    Racer operator=( const Racer& r );
    
    //Friend classes so the classes can be used as one.
    friend class Sensor;
    friend class TimeStamp;
private:
    string racerName;//Name of racer
    int racerNum;// Racer's tag number .
	unsigned int totalSens;// total of sensor they passed .
    vector<Sensor> racerSensor;//Variable for the sensorvectors
    double totalRaceTime;//Time of the racer.
    double totalSpeed;// Speed of racer.
    double totalDist;// Distance of racer .
    double startTimeofRaceInMS;// Star time of the race.
    double startTimeofRacerInMS;//start time of each racer.
    bool isCheater;//cheater.
};


#endif