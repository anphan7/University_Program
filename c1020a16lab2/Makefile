# Makefile for searches 

# Compiler:
CC=gcc

#  compiler options
CFLAGS=-c -Wextra

all: lab2

lab2: main.o athlete.o node.o list.o ultilies.o
	$(CC) main.c athlete.c node.c list.c ultilies.o -o lab2
    
main: main.o athlete.h node.h list.h
	$(CC) $(CFLAGS) main.c

athlete: athlete.o athlete.h
	$(CC) $(CFLAGS) athelete.c

node: node.o
	$(CC) $(CFLAGS) node.c

list: list.o list.h
	$(CC) $(CFLAGS) list.c
	
ultilies: ultilies.o ultilies.h
	$(CC) $(CFLAGS) ultilies.c

clean:
	rm -rf *.o lab2 *.gch *.exe

