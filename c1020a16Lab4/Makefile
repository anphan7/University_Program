# Makefile for searches 

# Compiler:
CC=g++

CFLAGS= -c -Wextra
all: lab4

lab4: main.o activity.o binarySearchTree.o node.o participant.o position.o utilities.o
	$(CC) main.cpp activity.h binarySearchTree.h node.h participant.h position.h utilities.h -o lab4
 
main.o: main.cpp activity.h binarySearchTree.h node.h participant.h position.h utilities.h
	$(CC) $(CFLAGS) main.cpp

activity.o: activity.h	
	$(CC) $(CFLAGS) activity.h

binarySearchTree.o: binarySearchTree.h
	$(CC) $(CFLAGS) binarySearchTree.h

node.o: node.h
	$(CC) $(CFLAGS) node.h

participant.o: participant.h
	$(CC) $(CFLAGS) participant.h

position.o: position.h
	$(CC) $(CFLAGS) position.h

utilities.o: utilities.h
	$(CC) $(CFLAGS) utilities.h

clean:
	$(RM) lab4 *.o *.gch *.exe *~