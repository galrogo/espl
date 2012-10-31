%.o: %.c
	gcc -c -o $@ $<

all: fortune

fortune: fortune.o
	gcc -g -Wall -ansi -o $@ $^ 

.PHONY: clean

#Clean the build directory
clean:
	rm -f *.o
