/**
* Author: Artiom Dolghi
* Date Due: October 5, 2018
*
* This file is composed of the function definitions for hack 7
*/

#include<stdlib.h>
#include<stdio.h>
#include "array_utils.h"

int contains(const int *arr, int size, int x) {
  int i = 0;
  for (i = 0; i<size; i++) {

    if (arr[i] == x) {
      return 1;
    }
  }
  return 0;
}


int containsWithin(const int *arr, int size, int x, int i, int j) {

  for (int k = i; k<=j; k++) {
    if (arr[k] == x) {
      return 1;
  }
}
return 0;
}

int * paddedCopy(const int *arr, int oldSize, int newSize) {
  int *deepCopy = (int*) malloc(newSize * sizeof(int));
  int i = 0;
  if (newSize > oldSize) {
    for (i = 0; i<oldSize; i++){
      deepCopy[i] = arr[i];
      //printf("%d, ", deepCopy[i]);
    }
    for (int z=oldSize; z<newSize; z++) {
      deepCopy[z] = 0;
      // printf("%d, ", zeroes[z]);
    }
  } else {
    for (i = 0; i<newSize; i++){
      deepCopy[i] = arr[i];
      // printf("%d, ", deepCopy[i]);
    }
  }

return deepCopy;
}



void reverse(int *arr, int size) {
int i = 0;
int j = size - 1;
while (i<j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
  i++;j--;
}
}


int * reverseCopy(const int *arr, int size) {
int *deepCopy = (int*) malloc(size * sizeof(int));
int i = 0;
for (i = 0; i<size; i++){
  deepCopy[i] = arr[i];
}

reverse(deepCopy, size);

return deepCopy;
}
