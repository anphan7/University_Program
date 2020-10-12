# Makefile for searches 

# Compiler:
CC=g++
#  compiler options
CFLAGS= -c -Wextra
all: lab2

lab2: main.o grocery_item.o 		
	$(CC) main.cpp grocery_item.h -o lab2
 
main.o: main.cpp grocery_item.h 
	$(CC) $(CFLAGS) main.cpp

grocery_item.o: grocery_item.h
	$(CC) $(CFLAGS) grocery_item.h

clean:
	$(RM) lab2 *.o *.gch *.exe *~