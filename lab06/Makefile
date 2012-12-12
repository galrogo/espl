%.o: %.c
	gcc -m32 -g -c -o $@ $<

%.o: %.asm
	nasm -g -O1 -f elf -o $@ $<

all: clean bsplitasm

bsplitasm: assembimp.o bsplit.o xsum.o
	gcc -m32 -Wall -o $@ $^
# 	ld  -melf_i386 -o $@ $^

bsplit.o: bsplit.c xsum.h
xsum.o: xsum.c xsum.h

clean:
	rm -f *.o 

distclean: clean
	rm -f bsplit bmerge
