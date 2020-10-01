/*
 * Name: Peter Phan
 * Due Date: April 2nd, 2019
 * Description: Racer class
 */ 
#include "racer.h"
#include <string>

/*
 * Class constructor
 * Create all the variable and it will equal to 0
 */ 
Racer::Racer()
{
    racerName = "";
    racerNum = 0;
    totalSens = 0;
    totalRaceTime = 0;
    totalDist = 0;
    totalSpeed = 0;
    startTimeofRaceInMS = 0;
    startTimeofRacerInMS = 0;
    isCheater = 0;
}

 /*
  * Copy constructor
  * Copy each variable 
  */ 
Racer::Racer(const Racer& r)
{
    racerName = r.racerName;
    racerNum = r.racerNum;
    totalSens = r.totalSens;
    racerSensor = r.racerSensor;
    totalRaceTime = r.totalRaceTime;
    totalDist = r.totalDist;
    totalSpeed = r.totalSpeed;
    startTimeofRaceInMS = r.startTimeofRaceInMS;
    startTimeofRacerInMS = r.startTimeofRacerInMS;
    isCheater = r.isCheater;
}

/*
 * Overload operator >> : read in the file 
 * Paramater: inStream - the stream to let the data flow into using stringstrea
 * 			  Racer& : racer class
 * Return: inStream
 */ 
istream& operator>>( istream& inStream, Racer& r){
    vector <size_t> position;//vector of sensors to keep track of variables.
   vector <Sensor> sensorVec(r.getTotalSensors());
    
    //Read in the first object in the line, which is the name of the racer.
    string line; // the variable of string called line
    getline( inStream, line); // read in the first line from file Ex:
	
    position.push_back(line.find(';')); // Vectors start with empty. Adds a new element at the end of the vector, after its current last element. (Ex: Paula Radcliffe;)
	string rName = line.substr(0, position[0]); // cut the name from the file before semi-colon
    r.setRacerName(rName); // set the rName in the function setRacerName
    
    //Next, we get the number for the racer, notice we are incrementing the position vector and
    //using a temp for length.
    position.push_back(line.find(';', position[0]+1)); // adds a new element at the end of the vector before semi-colon and plus 1 for the next element in file
    double temp = position[1] - position[0]; // the length of tag number Ex: 
	string tempRacerNum = line.substr(position[0]+1, temp-1); 
	stringstream tempSS(tempRacerNum);
    int tempRacerNumint;
    tempSS >> tempRacerNumint;
    r.setRacerNum(tempRacerNumint);
    
    //Declare the TimeStamp object so we can store all of the time variables.
    TimeStamp t;
    //variable used for incrementing in the loop.
	unsigned int j = 0;
    
    //Used for incrementing the posvector.
    int i = position.size();
    
    //All of these are used to get our total times.
    double hours = 0;
    double mins = 0;
    double secs = 0;
    double ms = 0;
    double totalTime = 0;
    
    //While j is less than the total number of sensors, gather the information.
    while(j < r.getTotalSensors()){
        //With the same process but here I reading the sensor number
        position.push_back(line.find(';', position[i-1]+1));
        temp = position[i] - position[i-1];
		string temp_Sensor_number = line.substr(position[i-1]+1, temp-1);
        stringstream tempSensor(temp_Sensor_number);
        int sensor_number;
        tempSensor >> sensor_number;
        sensorVec[j].setSensorNumber(sensor_number);
        i++;//increment the i so the position it changed.
        
        //With the same process but here I reading the miles
        position.push_back(line.find(';', position[i-1]+1));
        temp = position[i] - position[i-1];
        string temp_Miles = line.substr(position[i-1]+1, temp-1);
        stringstream tempSSmarker(temp_Miles);
        double miles_Marked;
        tempSSmarker >> miles_Marked;
        i++;
        sensorVec[j].setMileMarker(miles_Marked);
        
        //With the same process but here I reading the hours
        position.push_back(line.find(':', position[i-1]));
        temp = position[i] - position[i-1];
        string temp_hour = line.substr(position[i-1]+1, temp-1);
        stringstream tempSSHour(temp_hour);
        int hours_Marked;
        tempSSHour >> hours_Marked;
        t.setHour(hours_Marked);
        i++;
        
        //With the same process but here I reading the minutes
        position.push_back(line.find(':', position[i-1]+1));
        temp = position[i] - position[i-1];
        string temp_minute = line.substr(position[i-1]+1, temp-1);
        stringstream tempSSMinute(temp_minute);
        int minute_Marked;
        tempSSMinute >> minute_Marked;
        t.setMinute(minute_Marked);
        i++;
        
        //With the same process but here I reading the seconds
        position.push_back(line.find(':', position[i-1]+1));
        temp = position[i] - position[i-1];
        string temp_second = line.substr(position[i-1]+1, temp-1);
        stringstream tempSSSeccond(temp_second);
        int second_Marked;
        tempSSSeccond >> second_Marked;
        t.setSecond(second_Marked);
        i++;
        
        //Here, if the last semicolon can not be found, then we are at the end of the line.
        if(line.find(';', position[i-1]+1) ==string::npos)
        {
            string temp_MilliSecond = line.substr(position[i-1]+1, 2);
           stringstream tempSSMilliSecond(temp_MilliSecond);
            int milli_Marked;
            tempSSMilliSecond >> milli_Marked;
            t.setMilliSecond(milli_Marked);
        }
        
        // I getting the last number which is the semicolon
        position.push_back(line.find(';', position[i-1]+1));
        temp = position[i] - position[i-1];
        string temp_MilliSecond = line.substr(position[i-1]+1, temp-1);
      
        stringstream tempSSMilliSecond(temp_MilliSecond);
        int milli_Marked;
        tempSSMilliSecond >> milli_Marked;
        t.setMilliSecond(milli_Marked);
        i++;

        
		hours = t.hourToMS(t.getHour());
        mins = t.minToMS(t.getMinute());
        secs = t.secToMS(t.getSecond());
        ms = t.getMilliSecond();
		totalTime = hours + mins + secs + ms;
        r.setTotalRaceTime(totalTime);
        sensorVec[j].setTimeStamp(t);
        r.setRacerSensor(sensorVec);
        j++;
    }

    return inStream;
}


/*
 * Overloaded operator=: The function is to set all of these racer variables equal to another racer.
 * Parameters: const Racer&
 * Returns: *this
 */ 
Racer Racer::operator=( const Racer& r )
{
    if(this != &r)
    {
        racerName = r.racerName;
        racerNum = r.racerNum;
        totalSens = r.totalSens;
        racerSensor = r.racerSensor;
        totalRaceTime = r.totalRaceTime;
        startTimeofRaceInMS = r.startTimeofRaceInMS;
        startTimeofRacerInMS = r.startTimeofRacerInMS;
        isCheater = r.isCheater;
    }
    return *this;
}

/*
 * setStartTimeRace: The function is to convert the start race time to MS.
 * Parameters: st
 * Returns: none
 */ 
void Racer::setStartTimeRace(string st)
{
    TimeStamp t;
    size_t place = st.find(':');
    string tempHour = st.substr(0, place);
    stringstream tempSShour(tempHour);
    double startTimeHour;
    tempSShour >> startTimeHour;
    
    size_t next_place = st.find(':', place+1);
    int temp = next_place - (place+1);
    string tempMin = st.substr(place+1, temp);
    stringstream tempSSMin(tempMin);
    double startTimeMin;
    tempSSMin >> startTimeMin;
    
    place = st.find(':', next_place+1);
    temp = place - (next_place+1);
    string tempSec = st.substr(next_place+1, temp);
    stringstream tempSSSec(tempSec);
    double startTimeSec;
    tempSSSec >> startTimeSec;
    
    next_place = st.find(':', place+1);
    temp = next_place - (place+1);
    string tempMS = st.substr(place+1, temp);
    stringstream tempSSMS(tempSec);
    double startTimeMS;
    tempSSMS >> startTimeMS;
    
    double totalMS = ( (t.hourToMS(startTimeHour) + t.minToMS(startTimeMin) + t.secToMS(startTimeSec) + startTimeMS) );
    startTimeofRaceInMS = totalMS;
}


/*
 * setStartTimeofRacerInMS: The function is to set the racer start times to ms.
 * Parameters: timestamp 
 * Returns: *this, which is just a racer type.
 */ 
void Racer::setStartTimeofRacerInMS(TimeStamp& t)
{
    double h = t.hourToMS(t.getHour());
    double m = t.minToMS(t.getMinute());
    double s = t.secToMS(t.getSecond());
    double m_s = t.getMilliSecond();
    double totalStartTime = h + m + s + m_s;
    startTimeofRacerInMS = totalStartTime;
    
}
