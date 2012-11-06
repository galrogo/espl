%.o: %.c
	gcc -c -o $@ $<

all: xsum

xsum: xsum.o
	gcc -Wall -o $@ $^

.PHONY: clean

#Clean the build directory
clean:
	rm -f *.o first 
