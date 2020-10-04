/*
 * Name: Peter Phan
 * Due Date: April 2nd, 2019
 * Description: Sensor class create variables 
 */ 
#ifndef SENSOR_H
#define SENSOR_H
#include "timeStamp.h"
#include <iostream>
using std::string;
using std::cout;
using std::endl; 
using std::size_t;
using std::istream;
class Sensor
{
public:
	Sensor(){sensNum = mileMarker = 0;}

	Sensor(const Sensor& sensor) {sensNum = sensor.sensNum; mileMarker = sensor.mileMarker; t = sensor.t;}
    
    //sets and gets all of the class variables.
	void setSensorNumber(int sn){ sensNum = sn;}
    unsigned int getSensorNumber() const {return sensNum;}
	void setMileMarker(double mm){ mileMarker = mm;}
    double getMileMarker() const {return mileMarker;}
	void setTimeStamp(TimeStamp ts){ t = ts;}
    TimeStamp getTimeStamp() const {return t;}
    
    //Overloaded operator to read in the file.
    friend std::istream& operator>>( istream&, Sensor& );
    //Function to determine of two sensors are where they are supposed to be.
    bool isContiguous( Sensor& , Sensor& ){return true;};
    
    //overloaded operator=
    Sensor operator=( const Sensor&) {return *this;};
    friend class TimeStamp;
    virtual ~Sensor() {}
    
private:
    TimeStamp t;
	unsigned int sensNum;
    double mileMarker;
};

#endif