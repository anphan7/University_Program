/*
 * Name: Peter Phan
 * Due Date: April 2nd, 2019
 * Description: Sensor class
 */ 
#include "sensor.h"
#include <iostream>

istream& operator>>(istream& inStream, Sensor& s){
    string line;
    getline( inStream, line);
    size_t pos1 = line.find(';');
    string tempSensorNum = line.substr(0, pos1);
    cout << tempSensorNum << endl;
    return inStream;
}


/*
 * overloaded operator=: The function is to equal another sensor
 * Parameters: sensor to set them equal
 * Returns: *this
 */ 
Sensor Sensor::operator=( const Sensor& s ){
    sensNum = s.sensNum;
    mileMarker = s.mileMarker;
    t = s.t;
    return *this;
}


/*
 * isContigous: The function is to determine if the sensors are supposed to be after each other.
 * Parameters: s2, s1 to compare
 * Returns: true or false, depending if they are where they are supposed to be or not.
 */ 
bool Sensor::isContiguous(Sensor& s1, Sensor& s2){
    if((s1.sensNum + 1) == s2.sensNum){return true;}
    else{return false;}
}