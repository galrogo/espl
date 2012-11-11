#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
int opt, hex = 0;
unsigned int word, cksum=0;


while ((opt = getopt(argc, argv, "hx")) != -1) {
               switch (opt) {
               case 'h':
                   printf("usage: xsum [-x] [-h] FILE\n");
		   exit(EXIT_SUCCESS);
                   break;
               case 'x':
		    hex =1;
                   break;
               }
           }
           
if (optind >= argc) {
               fprintf(stderr, "Expected argument after options\n");
               exit(EXIT_FAILURE);
           }
           
FILE* fp=fopen(argv[optind], "r");
while(fread(&word, 1, sizeof(word), fp)) {
  cksum=cksum^word;
  word = 0;
}

if (hex)
  printf ("%x\n", cksum);
else
  printf ("%d\n", cksum);

fclose(fp);

return 0;
}
