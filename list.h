/****************************************/
/*                                      */
/* Alp Eren Kilic				*/
/*                                      */
/****************************************/


#ifndef LIST_H__
#define LIST_H__

/*function declarations*/
void printUsage();
int calculateTotalCharacterInFile(FILE *inp);
void saveArray(FILE *inp,char *arr);
void searchAndPrint(char *text,int textSize,char *targetWord,int targetWordSize);

#endif
