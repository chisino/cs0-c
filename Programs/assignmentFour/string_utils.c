/**
* Author: Artiom Dolghi
* Date Due: November 9, 2018
*
* This file is composed of the function definitions for assignment 3
* (part 1)
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "string_utils.h"

int strContains(const char *str, const char *subStr) {

  char* result = strstr(str, subStr);

  if (result == NULL) {
    return 0;
  }

  else {
    return 1;
  }
}



char *concatenate(const char *s, const char *t) {

  char *result = (char *) malloc((strlen(s) + strlen(t) + 1) * sizeof(char));

  strcpy(result, s);

  strcat(result, t);

  return result;
}



char *append(const char *s, const char *t) {

  //same as concatenate function
  return concatenate(s, t);
}



char *prepend(const char *s, const char *t) {

  //opposite of appending
  return concatenate(t, s);
}



char *substringToEnd(const char *s, int beginningIndex) {

  int i = beginningIndex;

  char *subStr = (char *) malloc((strlen(s) + 1) * sizeof(char));

  for (i=beginningIndex;i<strlen(s);i++) {
    subStr[i - beginningIndex] = s[i];
  }

  subStr[strlen(s) - beginningIndex] = '\0';

  return subStr;
}



char *substringIndex(const char *s, int beginIndex, int endIndex) {

  //error checking for invalid arguments
  if (beginIndex > endIndex) {
    return NULL;
  }

  int i = beginIndex;

  char *subStr = (char *) malloc((strlen(s) + 1) * sizeof(char));

  for (i=beginIndex;i<endIndex;i++) {
    subStr[i - beginIndex] = s[i];
  }

  subStr[endIndex - beginIndex] = '\0';

  return subStr;
}



char *substringSize(const char *s, int beginningIndex, int size) {

    int i = beginningIndex;
    int j = 0;

    char *subStr = (char *) malloc((size + 1) * sizeof(char));

    for (i=beginningIndex;i<strlen(s);i++) {
      while (j != size) {
      subStr[j] = s[i];
      j++;
      i++;
    }
  }

    subStr[size] = '\0';

    return subStr;
}
