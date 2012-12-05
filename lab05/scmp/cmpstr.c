#include <stdlib.h>
#include <stdio.h>

int cmpstr(char *str1,char *str2){
int i;  
for (i=0; str1[i]!=0 && str2[i] != 0; i++){
  if (str1[i]>str2[i]) return 1;
  if (str1[i]<str2[i]) return 2;
}
if ( (str1[i] == 0) && (str2[i] == 0) ) return 0;
if (str1[i] == 0) return 2;
return 1;
}