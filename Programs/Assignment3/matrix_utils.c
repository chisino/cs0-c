/**
* Author: Artiom Dolghi
* Date Due: October 19, 2018
*
* This file is composed of the definitions of the various matrices functions
* Assignment 3, part 3
*/

#include<stdlib.h>
#include<stdio.h>
#include "matrix_utils.h"

int **getIdentityMatrix(int n) {

  int i = 0;
  int j = 0;

  int **result = NULL;

  result = (int**) malloc(n * sizeof(int*));
  for(i = 0; i<n; i++) {
    result[i] = (int*) malloc(n * sizeof(int));
}

  for (i = 0;i < n;i++) {
    for (j = 0;j < n;j++) {
      if (i == j) {
        result[i][j] = 1;
      }
      else {
        result[i][j] = 0;
      }
    }
  }


  return result;
  }



int isEqual(int **A, int **B, int n) {

  int i = 0;
  int j = 0;

  for (i = 0;i < n;i++) {
    for (j = 0;j < n;j++) {
      if (A[i][j] != B[i][j]) {
        return 0;
      }
    }
  }

  return 1;
}



int *getRow(int **A, int n, int i) {

  int *ICopy = A[i];

  return ICopy;
}



int *getCol(int **A, int n, int j) {

  int *JCopy = A[j];

  return JCopy;
}




int ** product(int **A, int **B, int n) {






}
