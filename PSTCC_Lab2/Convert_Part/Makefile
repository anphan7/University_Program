# Makefile for searches 

# Compiler:
CC=g++
#  compiler options
CFLAGS= -c -Wextra
all: lab2

lab2: main.o grocery.o date.o		
	$(CC) main.cpp grocery.h grocery.cpp date.h date.cpp -o lab2
 
main.o: main.cpp grocery.h 
	$(CC) $(CFLAGS) main.cpp

date.o: date.h
	$(CC) $(CFLAGS) date.h

grocery.o: grocery.h
	$(CC) $(CFLAGS) grocery.h

clean:
	$(RM) lab2 *.o *.gch *.exe *.bin *~