#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int sumx (int *buffer){
unsigned int word, cksum=0;
int i=0;


while(i< (sizeof(buffer)/sizeof(int))) {
  word = buffer[i];
  cksum=cksum^word;
  i++;
}

return cksum;
}
