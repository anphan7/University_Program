/*
 * Name: Peter Phan
 * Due Date: April 2nd, 2019
 * Description: Time class  
 */ 
#include "timeStamp.h"

TimeStamp::TimeStamp(const TimeStamp& t)
{
    hour = t.hour;
    minute = t.minute;
    second = t.second;
    milli_second = t.milli_second;
}


int TimeStamp::hourToMS(int h){int milli_second = (h*3600000); return milli_second;}
int TimeStamp::minToMS(int m){int milli_second = (m*60000);return milli_second; }
int TimeStamp::secToMS(int second) {int milli_second = (second*1000); return milli_second;}

TimeStamp TimeStamp::operator=( const TimeStamp& t ){
    hour = t.hour;
    minute = t.minute;
    second = t.second;
    milli_second = t.milli_second;
    return *this;
}
int TimeStamp::calcTotalMS(int h, int m, int second, int milli)
{
    int total_milli_second = ( (hourToMS(h) + minToMS(m) + secToMS(second) + milli) );
    return total_milli_second;
}