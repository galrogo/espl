%.o: %.c
	gcc -c -o $@ $<

all: prep02

prep02: prep02.o
	gcc -g -Wall -ansi -o $@ $^ 

.PHONY: clean

#Clean the build directory
clean:
	rm -f *.o
