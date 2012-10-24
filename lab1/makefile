
all: run

run: first.o
	gcc -m32 -Wall -o first bin/first.o

first.o: 
	gcc -m32 -g -Wall -ansi -c -o bin/first.o src/firstexercise.c 

.PHONY: clean

#Clean the build directory
clean:
	rm -f *.o first
