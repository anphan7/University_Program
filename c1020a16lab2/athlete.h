#ifndef ATHLETE_H
#define ATHLETE_H

typedef struct {   
	char name[81];   
	char nationality[4]; // IOC 3-letter country code   
	char gender; // M or F  
 	char sport[31];   
	int gold, silver, bronze; // number of
} athlete_t;
 
// function prototype below
void print_Athlete(athlete_t);
int printMenu(int);
#endif
