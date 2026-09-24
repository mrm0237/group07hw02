#modify this makefile so that it will work for this new assignment
CC=g++

all: main

main: main.o
	$(CC) -std=c++11 main.o -o a.out

main.o: main.cpp
	$(CC) -std=c++11 -c main.cpp

clean:
	rm -f *.o *.out

