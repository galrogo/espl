.PHONY: all clean

all: scmp

scmp: scmp.o cmpstr.o
	gcc -m32 -o $@ $^

scmp.o: scmp.c
	gcc -m32 -c -o $@ $<

cmpstr.o: cmpstr.asm
	nasm -g -f elf -o $@ $<

clean:
	rm -f *.o first

