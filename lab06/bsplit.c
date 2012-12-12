#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

FILE* openfile(char *fileNam);
void splitFile(int cksum, FILE *fp, char* fileName, int suffix);

int c_main(int argc, char *argv[]){
int opt, hex = 0, printChkSum=0;
unsigned int word, cksum=0, CHECKSUM=0;
int suffix = 1;
unsigned int size = sizeof(unsigned int);
char *fileName;
char prefName[50];

FILE *f;
FILE* fp;

fileName = argv[optind];
fp=fopen(fileName, "rb");

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

/*********************************************************/
FILE* openfile(char *fileNam){
  FILE* fp=fopen(fileNam, "rb");
  return fp;
  
}

void splitFile(int cksum, FILE *fp, char* fileName, int suffix){
  unsigned int size = sizeof(unsigned int);
  int buffer[size];
  char prefName[50];
  int CHECKSUM=0;
  FILE *f;
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
}