#include <stdio.h>
#include <stdlib.h>
#include "grocery.h"

void print_Athlete(athlete_t a){
	int i;
	printf("%s, %s, %s \n", a.name, a.nationality, a.sport);
	printf("\tGold   Silver   Bronze\n");
	printf( "\t--------------------------\n" );	
	printf( "\t%4d%8d%9d\n", a.gold, a.silver, a.bronze);
	
}