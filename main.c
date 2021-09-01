/****************************************/
/* Unix List Command Implementation		  */
/*                                      */
/* Alp Eren Kilic				                */
/*                                      */
/****************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int main(int argc,char *argv[])
{

	FILE *inp;
	char *text;	/*text in file*/
	int totalCh;
	int targetWordSize;
	

	if (argc != 3)
	{
		printUsage();
		exit(1);
	}

	/*------------------------------------------------*/
	inp = fopen(argv[2],"r");
	if (inp == NULL) {
		fprintf(stderr, "%s can't open\n", argv[2]);
		exit(1);
	}	
	totalCh = calculateTotalCharacterInFile(inp);
	fclose(inp);
	/*------------------------------------------------*/

	/*allocate heap memory for text in file*/
	text = (char *) malloc(sizeof(char) * totalCh);

	/*------------------------------------------------*/
	inp = fopen(argv[2],"r");
	if (inp == NULL) {
		fprintf(stderr, "%s can't open\n", argv[2]);
		exit(1);
	}
	saveArray(inp,text);
	fclose(inp);
	/*------------------------------------------------*/



	targetWordSize = (int) strlen(argv[1]);

	searchAndPrint(text,totalCh,argv[1],targetWordSize);
	

	
	/*deallocate heap memory*/
	free(text);

	return 0;
}



