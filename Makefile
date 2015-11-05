all: main

main: main.o split.o nodes.o
	gcc -std=c99 main.o split.o nodes.o -o main -Wall

main.o: main.c split.h nodes.h
	gcc -std=c99 main.c -c -Wall
	
split.o: split.c
	gcc -std=c99 split.c -c -Wall
	
nodes.o: nodes.c
	gcc -std=c99 nodes.c -c -Wall
	
clean:
	rm *.o