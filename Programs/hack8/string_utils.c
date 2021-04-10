/**
* Author: Artiom Dolghi, Benoit Bikeli
* Date Due: October 12, 2018
*
* This file is composed of the function definitions for hack 8
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "string_utils.h"
#include <math.h>
#include <ctype.h>

void replaceChar(char *s, char oldChar, char newChar) {
  if(s == NULL) {
    exit(1);
  }

  if(isdigit(oldChar)) {
    exit(1);
  }

  if(isdigit(newChar)) {
    exit(1);
  }

  int i = 0;
  while (s[i] != '\0') {
  if (s[i] == oldChar) {
    s[i] = newChar;
  }
  i++;
  }
}


char * replaceCharCopy(const char *s, char oldChar, char newChar) {
  if(s == NULL) {
    exit(1);
  }

  if(isdigit(oldChar)) {
    exit(1);
  }

  if(isdigit(newChar)) {
    exit(1);
  }


  char* newCopy = (char *) malloc((strlen(s) + 1) * sizeof(char));

  strcpy(newCopy, s);

  int i = 0;
  for (i=0;i<strlen(newCopy);i++) {
    if (newCopy[i] == oldChar) {
      newCopy[i] = newChar;
    }
  }
  newCopy[strlen(newCopy)] = '\0';

  return newCopy;
}


void removeChar(char *s, char c) {
  if(s == NULL) {
    exit(1);
  }

  if(isdigit(c)) {
    exit(1);
  }

  int i = 0, j = 0;
  char *newRemoveCopy = (char *) malloc((strlen(s) +1) * sizeof(char));

  strcpy(newRemoveCopy, s);
  for (i=0;i<strlen(s);i++) {
    if (s[i] != c) {
      s[j] = newRemoveCopy[i];
      j++;
    }
  }
  s[j] = '\0';
  free(newRemoveCopy);
}

char * removeCharCopy(const char *s, char c) {
  if(s == NULL) {
    return NULL;
  }

  if(isdigit(c)) {
    return NULL;
  }

  int i = 0, j = 0;

  char *s2 = (char *) malloc((strlen(s) ) * sizeof(char));



  for (i=0;i<strlen(s);i++) {
    if (s[i] != c) {
      s2[j] = s[i];
      j++;
    }
  }
  s2[j] = '\0';

  return s2;
}


char **lengthSplit(const char *s, int n)
{
  if(s == NULL) {
    exit(1);
  }

  if(isalpha(n)) {
    exit(1);
  }

	int i = 0;
	int total = 0;
	total = ceil((double)strlen(s)/n);
char** split = (char**)malloc(sizeof(char*)*total);
int counter = 0;

for (i=0; i<strlen(s)/n; i++)
 {
	 split[i]= (char*)malloc(sizeof(char)*(n+1));
	 strncpy(split[i],&s[counter],n);
   printf("%s,", split[i]);
	counter = counter + 3;
 }

 return split;
}
