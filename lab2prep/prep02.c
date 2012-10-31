/* Hello World program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


main()
{
		
 FILE *pfile;
 pfile= fopen("Text","r");
 int numLines = getNumberOfLines(pfile);
 rewind(pfile);
 srand(time(NULL));
 int line = rand() %(numLines +1);
 printLin(pfile, line);
 fclose(pfile);
 
 
}

int getNumberOfLines(FILE *myFile){
	FILE *begPos = myFile;
	char ch;
	int number_of_lines = 0;
 	do {
		ch = fgetc(myFile);
		if (ch == '\n')
			number_of_lines++;
	}while (ch != EOF);
return number_of_lines;
}


 printLin(FILE *myFile, int line){
	char myString[104];
	int i;
	for (i=1; i<=line; i++){
		fgets(myString, 100, myFile);
	}
	printf(myString);
}
