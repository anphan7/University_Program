CC=g++

CFLAGS= -c -Wall
all: lab3

lab3: main.o racer.o sensor.o timeStamp.o
	$(CC) main.cpp racer.h sensor.h timeStamp.h -o lab3 
 
main: main.o racer.h sensor.h timeStamp.h
	$(CC) $(CFLAGS) main.cpp

racer: racer.o racer.h	
	$(CC) $(CFLAGS) racer.cpp

sensor: sensor.o sensor.h
	$(CC) $(CFLAGS) sensor.cpp

timeStamp: timeStamp.o timeStamp.h
	$(CC) $(CFLAGS) timeStamp.cpp

clean:
	rm -rf *o lab3