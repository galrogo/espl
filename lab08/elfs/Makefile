CC=gcc
CFLAGS=-O -g -m32

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: secret-elf-encode secret-elf-decode


secret-elf-encode: secret-elf-b secret-elf-c
	$(CC) $(CFLAGS) -o $@ $^

secret-elf-decode: secret-elf-a secret-elf-c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o secret-elf-b secret-elf-a testbc