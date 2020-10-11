# Makefile for searches 

# Compiler:
CC=g++
#  compiler options
CFLAGS= -c -Wextra
all: lab2

lab2: main.o date.o list.o node.o utilities.o			
	$(CC) main.cpp date.h date.cpp list.h list.cpp node.h node.cpp utilities.h utilities.cpp -o lab2
 
main.o: main.cpp date.h list.h node.h utilities.h
	$(CC) $(CFLAGS) main.cpp

data.o: data.h	
	$(CC) $(CFLAGS) date.h

list.o: list.h
	$(CC) $(CFLAGS) list.h

node.o: node.h
	$(CC) $(CFLAGS) node.h

utilities.o: utilities.h 
	$(CC) $(CFLAGS) utilities.h 

clean:
	$(RM) lab2 *.o *.gch *.exe *~