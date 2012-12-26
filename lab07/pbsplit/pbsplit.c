#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "xsum.h"

#define MAX_FILENAME_LENGTH 1024

int numOfProc;


void readAndWrite(FILE* src, FILE* dest, int chunksize){
  unsigned int size = sizeof(unsigned int);
  int cksum;
//   fopen(src);
//   fopen(dest);
  int buffer[chunksize];
  if (fread(buffer,1, chunksize,src) <= 0){
    perror("Error reading from file");
    exit(EXIT_FAILURE);
  }
  else printf("%s", "read success\n");
  cksum = sumx(buffer);
  fprintf(dest, "%x", cksum);
  if (fwrite(buffer, 1 ,chunksize, dest) <= 0){
        perror("Error writing from file");
	exit(EXIT_FAILURE);
  }
//   fclose(src);
//   fclose(dest);
}
  
//     int nchunks = (filesize +chunksize -1)/chunksize


  
  void ForkSplit(char* fileName, long chunksize, int nchunks, int numOfProc){
  FILE* srcFile;
  FILE* destFile;
  int currentChunk;
  int numberActive = 0;
  pid_t process;
  process = 1;
  int status;
  
  for (currentChunk=0; currentChunk < nchunks; currentChunk++, numberActive++){
    
    for (;numberActive>=numOfProc;--numberActive)
      wait(&status);
    if (process!=0)
      //only for from parent
      process = fork();
    //child
    if (process == 0){
     srcFile = fopen(fileName, "r");
     if (!srcFile){
     perror("Can't open file");
     exit(EXIT_FAILURE);
     }
    fseek(srcFile, currentChunk*chunksize, SEEK_SET);
    char destFileName[MAX_FILENAME_LENGTH];
    snprintf(destFileName, MAX_FILENAME_LENGTH, "%s.0%d", fileName, currentChunk);
    destFile = fopen(destFileName, "w+");
     if (!destFile){
     perror("Can't open file");
     exit(EXIT_FAILURE);
     }
    readAndWrite(srcFile,destFile, chunksize);
    fclose(srcFile);
    fclose(destFile);
    
    exit(0);
  }
  
  }
  while (numberActive>0){
    wait(&status);
    numberActive--;
  }
    
  }

int main(int argc, char *argv[]){
int opt, hex = 0, printChkSum=0;
unsigned int word, cksum=0, CHECKSUM=0;
int suffix = 1;
char *fileName;
char prefName[50];
int chunksize;
int nchunks;

FILE *f;

// default
numOfProc = 10;

while ((opt = getopt(argc, argv, "hb:xp:")) != -1) {
               switch (opt) {
               case 'h':
                   printf("usage: pbsplit [-b SIZE] [-x] [-h] [-p NUMOFPROC] FILE\n");
		   exit(EXIT_SUCCESS);
		   break;
               case 'b':
		    chunksize = atoi(optarg);
// 		    printf("%d\n",chunksize);
		    break;
	       case 'x':
		 printChkSum = 1;
		 break;      
	       case 'p':
		 numOfProc = atoi(optarg);
		 break;
               }
           }
           
if (optind >= argc) {
               fprintf(stderr, "Expected argument after options\n");
               exit(EXIT_FAILURE);
           }

//get file size
fileName = argv[optind];
FILE* fp=fopen(fileName, "rb");
fseek(fp, 0, SEEK_END); // seek to end of file
long filesize = ftell(fp); // get offset
fseek(fp, 0, SEEK_SET); // seek back to beginning of file
fclose(fp);

nchunks = (filesize +chunksize -1)/chunksize;
ForkSplit(fileName, chunksize, nchunks, numOfProc);


if (printChkSum){
  printf ("%x\n", CHECKSUM);
}

}



