# Makefile for searches 

# Compiler:
CC=g++

CFLAGS= -c -Wextra
all: lab4

lab4: main.o activity.o participant.o 
	$(CC) main.cpp activity.h  participant.h participant.cpp -o lab4
 
main.o: main.cpp activity.h participant.h 
	$(CC) $(CFLAGS) main.cpp

activity.o: activity.h	
	$(CC) $(CFLAGS) activity.h

participant.o: participant.h 
	$(CC) $(CFLAGS) participant.h 

clean:
	$(RM) lab4 *.o *.gch *.exe *~