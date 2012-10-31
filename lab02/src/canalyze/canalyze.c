#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "namelist.h"
#include "fgetname.h"

int isName(char *name){
   int ans = 1;
   int i;
   static char *keywords[] = {"auto","double", "int","long", "break","else","long", "switch", "case", "enum", "register","typedef", "char", "extern" ,"return", "if", "do", "union", "const", "float", "short", "if", "do", "while", "static"};
  for (i=0; i<(sizeof(keywords)/sizeof(char)); i++)
    if (strcmp(name, keywords[i]) == 0 ){
      ans = 0;
      break;
    }
    return ans;
}

int main(int argc, char **argv) {
	int i;
	namelist nl = make_namelist();
	for (i=0; i<argc; i++){
	FILE *stream = fopen(argv[i], "r");
	char name[64];
	if(!stream) {
		fprintf(stderr, "run the test in the source directory\n");
		return 1;
	}

	while(fgetname(name, sizeof(name), stream))
		if (isName(name) == 1) 
		{
		  add_name(nl, name);
		  printf(name);
		}
	
	printf("\n");
	fclose(stream);
	}
	
	//qsort(nl->names, nl->size, sizeof(??), compare)
	return 0;
}

