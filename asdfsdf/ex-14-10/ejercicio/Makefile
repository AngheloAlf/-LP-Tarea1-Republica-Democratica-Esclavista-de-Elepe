all: exercise

exercise: list.o
	gcc -o exercise exercise.c list.o

list.o:
	gcc -c list.c

clean:
	rm -f *.o

run: exercise clean
	./exercise
	rm exercise

