#ifndef DATE_H
#define DATE_H
#include <cstring>
#include <iostream>
#define MAX_LENGTH 365

class Date {
public:
    Date() {month, day, year = 0;}

    //----Set and Get functions for private data----
    void setMonth(int the_month) { the_month = month;}
    int getMonth () const {return month;}

    void setDay (int the_day){the_day = day;}
    int getDay() const {return day;}

    void setYear(int the_year){the_year = year;}
    int getYear() const {return year;}



private:    
    int month, day, year;
};


#endif