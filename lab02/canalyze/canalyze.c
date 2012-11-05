#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "namelist.h"
#include "fgetname.h"

int isName(char *name){
   int ans = 1;
   int i;
   static char *keywords[] = {"auto","double", "int","long", "break","else","long", "switch", "case", "enum", "register","typedef", "char", "extern" ,"return", "if", "do", "union", "const", "float", "short", "if", "do", "while", "static","void"};
  for (i=0; i<(sizeof(keywords)/sizeof(char*)); i++)
    if (strcmp(name, keywords[i]) == 0 ){
      ans = 0;
      break;
    }
    return ans;
}

int myCompare(const void *arg1, const void *arg2){

  return strcmp(((namestat)arg1)->name, ((namestat)arg2)->name);
  
}

int main(int argc, char **argv) {
	int i;
	namelist nl = make_namelist();
 	for (i=1; i<argc; i++){
	FILE *stream = fopen(argv[1], "r");
	char name[64];
	if(!stream) {
		fprintf(stderr, "run the test in the source directory\n");
		return 1;
	}

	while(fgetname(name, sizeof(name), stream) != NULL)
		if (isName(name)) 
		{
		  add_name(nl, name);
		}
		
 	qsort(nl->names, nl->size, sizeof(struct namestat), myCompare);

		
	for (i=0; i<(nl->size); i++){
	  printf("%s %d\n",nl->names[i].name, nl->names[i].count);
	}
	
	printf("\n");
	fclose(stream);
	}
	
	return 0;
}

