all: main

main: main.o split.o nodes.o callbacks.o functions.o
	gcc main.o split.o nodes.o callbacks.o functions.o -o main -Wall

main.o: main.c split.h nodes.h callbacks.h functions.h
	gcc main.c -c -Wall
	
split.o: split.c
	gcc split.c -c -Wall
	
nodes.o: nodes.c
	gcc nodes.c -c -Wall

callbacks.o: callbacks.c
	gcc callbacks.c -c -Wall

functions.o: functions.c
	gcc functions.c -c -Wall
	
clean:
	rm *.o main