 
#include <assert.h>
#include <stdio.h>
#include "bclib.h"

char** encodetobar(int numOfWords, char** string)
{
  int i=0,j=0,k=0;
  int barcodes[BC_WIDTH][BC_NBITS]={0};
  printf("%d \n",numOfWords); 
  for (i=1;i<numOfWords-1; i++)
    { 
      printf("%d" ,i); 
      while (string[i][j]!='\0')
      {
      bc_char2bits(string[j][i],barcodes[k]);
      k++;
      } 
      j=0;
    }
    for(j=0;j<8;j++)
    {
      for(i=0;i<k;i++)
      {
	if (barcodes[i][j]==1)
	  printf ("#");
	else
	  printf(" ");
      }
      printf("\n");
    }
    printf ("\n");
 
}




int main(int argc, char **argv) 



{
	encodetobar(argc,argv);

    return 0;
}
