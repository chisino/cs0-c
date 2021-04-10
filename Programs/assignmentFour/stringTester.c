/**
* Author: Artiom Dolghi
* Date Due: November 9, 2018
*
* This program will test the functions from assignment 3 (part 1)
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "string_utils.h"

int main(int argc, char **argv) {

  char *s = "Lincoln";

  int beginningIndex = 1;

  int size = 3;

  char *result = substringSize(s, beginningIndex, size);

  printf("%s\n", result);

  return 0;
}
