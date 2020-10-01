/*
 * Name: Peter Phan
 * Due Date: April 2nd, 2019
 * Description: In many foot races, each competitor wears an RFID tag. When the racer crosses a sensor, data is retrieved from the tag such as racer number, the current time and the sensor number. 
 * This application initially reads racer data from a text file that contains logged data for a race and computes statistics for each racer. 
 * It also detects the possibility of cheating under the following circumstances:If the racer misses a sensor (did the racer take a short cut?)
 * If the speed between two sensors is greater than 14 miles per hour (did the racer get in a vehicle at some point?).
 * 
 */ 
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "racer.h"
#include "sensor.h"
#include "timeStamp.h"

using std::cin; 
using std::setw;
using std::setfill;
using std::left;
using std::right; 
using std::ifstream;
using std::sort;

int main(){    
	// initialized all the class
    Racer r;
    Sensor s;
    TimeStamp t;
	
    string fileName;
	double totalRaceTime, startTime, hours;
	int speed;
	
    cout << "Enter the file name: "; // ask for the name of the file to open
	cin >> fileName;//read in the name of file
    ifstream inFile;
    int line_count; 
    string line;
    inFile.open(fileName.c_str()); // open the file
    if(inFile.fail()){ //If it does not exist, notify the User and exit the program.
    
        cout << " Input file " << fileName << " does not exist. Please contact the administrator. " << endl;
		cout << " Check the name of the file again " << endl;
		return 0;
    }
    else { //Otherwise, check to see if the file is empty or not.
        while(getline(inFile, line)){
            line_count++;//Loop through the file and increment the line_count to keep track of the line
        }
        //If the line_count is empty
        if(line_count < 1){
        cout << " Input file " << fileName << " is empty. Please contact the administrator. " << endl;
		cout << " Check the file again. The program only work with the file that has data in it " << endl;
		return 0;
        }
        else { // if the file can open and not empty
            inFile.clear();
            inFile.seekg(0, inFile.beg);
            //Use line and Substr to parse through the file and look for the semicolon delimeter.
            getline(inFile, line);
            size_t place; 
            place = line.find(';');
            string startTimestr = line.substr(0,place);
            r.setStartTimeRace(startTimestr);//Call the function to store the variables inside the racer class.
//--------------------------------------------------------------------------------------------------------
            // This is the part when I looking for the semicolon
			// Use the stringstream and store it in the total sensor
			// set the one was read in the setTotalSensors function
			size_t position = line.find(';', place + 1); 
            int temp = position - (place + 1);
            string sensorCount = line.substr(place + 1, temp);
            stringstream convert(sensorCount);
			unsigned int sensor_count;
            convert >> sensor_count;
            r.setTotalSensors(sensor_count);
//--------------------------------------------------------------------------------------------------------
            // This is the part when I looking for the semicolon
			// Use the stringstream and store it in the total distance 
			// set the one was read in the setTotalDistance function
            place = line.find(';', position+1);
            temp = place - (position+1);
            string totalMiles = line.substr(position+1, temp);
            stringstream next_convert(totalMiles);
            int total_Miles_2;
            next_convert >> total_Miles_2;
            r.setTotalDistance(total_Miles_2);

			// Create vector_Racer to store racers in
            vector<Racer> vector_Racer;
            for(int i = 0; i < line_count-1; i++){
                inFile >> r; //As each racer is read in, store it in the vector so we can keep track of everything.
                vector_Racer.push_back(r);
            }
            inFile.close();//Close the file as soon as possible.
            //Now loop through the vector and set the start times for each of out racers.
           
			for(int i = 0; i < line_count-1; i++){
                //We have to create a vector of sensors so we can keep track of the 4 sensors
                //within each racer class.
                vector<Sensor> sensorVec = vector_Racer[i].getRacerSensor();
                for(int j = 0; j < 1; j++){
				//Using the Sensor function to reference our timeStamp, we are able to initialize the times.
                    t = sensorVec[j].getTimeStamp();
                    vector_Racer[i].setStartTimeofRacerInMS(t);
                }
            }
            //Format the table to match the assigment output
            cout << setw(43) <<left << "Name" <<setw(10) << left << "Number" << setw(13) << left << "Time" <<endl;
			cout << setw(66) << setfill('-') << "-" << setfill(' ') << endl; 
            sort(vector_Racer.begin(), vector_Racer.end()); // use soft function to to sort the time of racer
            for(int j = 0; j < line_count-1; j++){
                //Initialize a new sensorvector to keep track of where we are in the loop.
                vector<Sensor> sensorVec = vector_Racer[j].getRacerSensor();
                for(int k = 0; k < 1; k++){
                    TimeStamp t = sensorVec[k].getTimeStamp();
                    totalRaceTime = vector_Racer[j].getTotalRaceTime();
                    startTime = vector_Racer[j].getStartTimeofRacerInMS();
                    //time the racer took to finish the race.
                    hours = ((totalRaceTime - startTime)/3.6e+6);
                    int ms = (hours * 3600000);
                    int h = (ms/3600000) % 24;
                    int m = (ms/60000) % 60;
                    int s = (ms/1000) % 60;
                    ms = ms % 1000;
                    t.setMilliSecond(ms);
                    t.setHour(h);
                    t.setMinute(m);
                    t.setSecond(s);
                    speed = (vector_Racer[j].getTotalDistance() / hours); // speed to check for cheater
                    vector_Racer[j].setTotalSpeed(speed);
                    // if cheater missed sensor or they too fast (greater that 14)
                    if(sensorVec[j].isContiguous(sensorVec[j+1], sensorVec[j+2]) || speed > 14){cout << '*';} // mark the cheater with *
                    else{cout << " ";}
                    //Format the table with name, tag number and time
                    cout << setfill(' ') << setw(43) <<left << vector_Racer[j].getRacerName();
                    cout << setfill(' ') << setw(5) << right << vector_Racer[j].getRacerNum() << "  "; 
                    cout << setfill('0') << setw(2) <<right << t.getHour() << ':' << setw(2) 
						 << t.getMinute() << ':' << setw(2) << t.getSecond() << ':' << setw(3) << t.getMilliSecond() 
						 << endl;
                }
            }
        }
    }
    return 0;
}

