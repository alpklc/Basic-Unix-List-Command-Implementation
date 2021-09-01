/****************************************/
/*                                      */
/* Alp Eren Kilic				*/
/*                                      */
/****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

void saveArray(FILE *inp,char *arr)
{
	int i = 0,status;

	for (status = fscanf(inp,"%c",&arr[i]);
		 status != EOF;
		 status = fscanf(inp,"%c",&arr[i]))
		++i;
}

int calculateTotalCharacterInFile(FILE *inp)
{
	int total = 0;
	char ch;
	int status;

	for (status = fscanf(inp,"%c",&ch);
		 status != EOF;
		 status = fscanf(inp,"%c",&ch))
	{
		++total;
	}

	return total;
}

void printUsage()
{
	fprintf(stderr, "\nUsage: list.c string file\n");
}

void searchAndPrint(char *text,int textSize,char *targetWord,int targetWordSize)
{
	int i,j,k,t = 0;
	int numberOfLine = 1;
	int row = 1;
	int column = 1;
	int numberOfTargetWordInFile = 0;
	int found = 0; /*1:found, 0:not found*/
	
	for (i = 0;i < (textSize - targetWordSize + 1);++i)
	{
		j = 0;
		found = 0;
		for (k = 0;k < targetWordSize;++k)
		{
			if (text[i + j] ==  targetWord[k])
			{
				if (j == 0)
				{
					++t;
					row = numberOfLine;
					column = t;
				}
				if ((k + 1) == targetWordSize)
				{
					found = 1;
					++numberOfTargetWordInFile;
				}
				
			} 
			else if (text[i + j] == '\n')
			{
				t = 0;
				
				--k;
				if (j == 0)
				{
					++numberOfLine;
					found = 0;
					k = targetWordSize;
				}
			}
			else if ((text[i + j] == ' ') || (text[i + j] == '\t'))
			{
				--k;
				
				if (j == 0)
				{
					++t;
					found = 0;
					k = targetWordSize;
				}
			}
			else
			{
				if (j == 0)
					++t;
				k = targetWordSize;
			}
			++j;

			if (found == 1)
				fprintf(stderr,"[%d, %d] konumunda ilk karakter bulundu.\n",row,column);
		}
		
	}
	fprintf(stderr, "\n%d adet %s bulundu.\n", numberOfTargetWordInFile,targetWord);

}

