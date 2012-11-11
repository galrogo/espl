#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
int opt, hex = 0, printChkSum=0;
unsigned int size = sizeof(unsigned int);
unsigned int word, cksum=0, CHECKSUM=0;
int suffix = 1;
char *fileName;
char prefName[50];

FILE *f;


while ((opt = getopt(argc, argv, "hb:x")) != -1) {
               switch (opt) {
               case 'h':
                   printf("usage: bsplit [-b SIZE] [-x] [-h] FILE\n");
		   exit(EXIT_SUCCESS);
		   break;
               case 'b':
		    size = atoi(optarg);
		    printf("%d",size);
		    break;
	       case 'x':
		 printChkSum = 1;
		 break;      
               }
           }
           
if (optind >= argc) {
               fprintf(stderr, "Expected argument after options\n");
               exit(EXIT_FAILURE);
           }


fileName = argv[optind];
FILE* fp=fopen(fileName, "rb");

int buffer[size];
while(fread(buffer, 1,size, fp)) {
  cksum = sumx(buffer);
  sprintf(prefName,"%s%s%d",fileName,".0",suffix);
  f = fopen(prefName, "wb");
//   fwrite(&cksum, 1,  sizeof(int), f);
  fprintf(f, "%x", cksum);
  fwrite(buffer, 1, size,f);
  fclose(f);
  memset(buffer, 0, size);
  CHECKSUM = CHECKSUM^cksum;
  suffix++;


}

if (printChkSum){
  printf ("%x\n", CHECKSUM);
}
fclose(fp);
}