#include <stdlib.h>
#include <stdio.h>

extern int malami(char*);

int main(int argc, char **argv) {
	int a;
	a = malami(argv[1]);
	printf("%d\n", a);
	return 0;
}
