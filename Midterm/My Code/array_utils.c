/**
* Author: Artiom Dolghi
* Midterm Exam
*
* This file is composed of the definition for the dotProduct function
*/

#include<stdlib.h>
#include<stdio.h>
#include "array_utils.h"

int dotProduct(const int *a, const int *b, int n, int *result) {
//error checking
  if (a == NULL || b == NULL) {
    return 1;
  }

  if (n < 0) {
    return 1;
  }

  int i = 0;

  int resultOne = 0;

//loop to add up results and get dot product
  for (i=0;i<n;i++) {
    resultOne += (a[i] * b[i]);
  }

  *result = resultOne;

  return 0;
}
