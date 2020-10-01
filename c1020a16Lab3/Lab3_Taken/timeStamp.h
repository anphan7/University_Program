
/*
 * Name: Peter Phan
 * Due Date: April 2nd, 2019
 * Description: Time class create variables 
 */ 
 #ifndef TIMESTAMP_H
#define TIMESTAMP_H

class TimeStamp
{
public:
	TimeStamp(){hour = minute = second = milli_second = 0;}
    TimeStamp(const TimeStamp&);//copy ctor
    
    //Set and get function
	void setHour(int h){hour = h;}
	void setMinute(int m){minute = m;}
	void setSecond(int s){second = s;}
	void setMilliSecond(int ms){milli_second = ms;}
    int getHour() const {return hour;}
    int getMinute() const {return minute;}
    int getSecond() const {return second;}
    int getMilliSecond() const {return milli_second;}
    
	//convert times to millisecond
    int hourToMS(int);
    int minToMS(int);
    int secToMS(int);
    int calcTotalMS(int, int, int, int);
    //overloaded ops
    TimeStamp operator=( const TimeStamp& );
private:
    int hour;
    int minute;
    int second;
    int milli_second;
};

#endif