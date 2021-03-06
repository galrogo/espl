#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
int opt, hex = 0, chkSumFlag=0;
unsigned int size = sizeof(unsigned int);
unsigned int CHECKSUM=0;
unsigned int* cksum;
int totalBytes = 0;
int suffix = 1;
char *prefix; 
char *fileName =NULL;
char prefName[50];
int buffer[size];

cksum = malloc(sizeof(unsigned int));

FILE *f;


while ((opt = getopt(argc, argv, "ho:x")) != -1) {
               switch (opt) {
               case 'h':
                   printf("usage: bsplit [-o OUTPUT] [-x] [-h] PREFIX\n");
		   exit(EXIT_SUCCESS);
                   break;
               case 'o':
		    fileName = strdup(optarg);
		    break;
	       case 'x':
		 chkSumFlag = 1;
		 break;      
               }
           }

          
if (fileName == NULL)
  fileName = strdup(argv[optind]);
prefix = strdup(argv[optind]);


FILE* target = fopen(fileName,"wb");


  sprintf(prefName, "%s%s%d", prefix, ".0", suffix);
  FILE* fp = fopen(prefName, "r");
  
  while(fp){
//     fread(cksum, 1,  size ,fp);
    fscanf(fp, "%x", cksum);
    CHECKSUM = CHECKSUM^*cksum;
    memset(cksum, 0, size);
    while (fread(buffer,1,size,fp)){
//       printf("%d\n", *buffer);
      fwrite(buffer,1,size,target);
      memset(buffer,0,size);
      totalBytes = totalBytes +4;
    }
    suffix++;
    sprintf(prefName, "%s%s%d", prefix, ".0", suffix);
    fclose(fp);
    fp = fopen(prefName, "r");
  }
  
 //calculate checksum
if (chkSumFlag){
rewind(target);
char buffer2[totalBytes];
fread(buffer2, totalBytes, 1, target);
*cksum = sumx(buffer2);
printf("%s %s\n", "Checksum validation is", (*cksum==CHECKSUM) ? "true" : "false");
}

fclose(target);

free(fileName);
free(prefix);
free(cksum);

}

	 
  