/**
* Authors: Benoit Bikeli Bikeli;  Judith Kwassieu;  Artiom Dolghi
* Date: October 25, 2018
*/

#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <math.h>
#include "protein_utils.h"
#include "file_utils.h"

// remove the character
void removeChar(char *s, char c);

// replace the character
void replaceChar(char *s, char oldChar, char newChar);
//return a split
char **lengthSplit(const char *s, int n, int *numSplit);

int main(int argc, char** argv){
	if(argc != 3) {
		fprintf(stderr, "Usage: %s RNA\n", argv[0]);
		exit(1);
	}

	char *inputfile =  (argv[1]);
	FILE *f = fopen(inputfile, "r");
	char *outputfile = (argv[2]);
	FILE *g = fopen(outputfile, "w");
	char *str = getFileContents(inputfile);

	replaceChar(str, 'T', 'U' ); // call the function replace
	removeChar(str,'\n');  // call the function remove
	removeChar(str, ' ');  // call the function remove
	int numLine;
	char **arr = lengthSplit(str, 3, &numLine);

	for(int i=0; i<numLine; i++){
		char protein = rnaToProtein(arr[i]);
		if(protein == 'x'){
			break;
		}
		if(protein != '\0'){
			fprintf(g, "%c", protein);
		}

	}
	fclose(f);
	fclose(g);
	return 0;
}

void removeChar(char *s, char c){
	int i = 0, j = 0;
	char *newRemoveCopy = (char *) malloc((strlen(s)+1 ) * sizeof(char));

	strcpy(newRemoveCopy, s);
	for (i=0;i<strlen(s);i++) {
		if (s[i] != c) {
			s[j] = newRemoveCopy[i];
			j++;
		}
	}
	s[j] = '\0';
}

void replaceChar(char *s, char oldChar, char newChar)
{
  int i=0;
  while (s[i]!= '\0')
  {
    if (s[i]== oldChar)
      {
       s[i] = newChar;
      }
    i++;
  }
}

char **lengthSplit(const char *s, int n, int *numSplit)
{
	int input= 0;
	float a = strlen(s)/(float)n;
	int total = ceil(a);
	*numSplit = total;
	char **split = (char **)malloc(sizeof(char *)*total);
	int i = 0;

	while (input < total)
	{
		split[input] = (char *)malloc(sizeof(char)*(n+1));
		strncpy(split[input], &s[i], n);
		split[input][n]='\0';
		input++;
		i= i+n;

	}

	return split;

}
