/**
* Author: Artiom Dolghi
* Date Due: October 19, 2018
*
* This file is composed of various array function definitions
* Assignment 3, part 2 (arrays)
*/

#include<stdlib.h>
#include<stdio.h>
#include "array_utils.h"

int subSum(const int *a, int size, int i, int j) {

  int x = 0;
  int sumResult = 0;

    for (x = i;x <= j; x++) {
      sumResult += a[x];
  }

  return sumResult;
}



int sum(const int *a, int size) {
  int i = 0;
  int sumCalc = 0;

  for (i = 0;i < size;i++) {
  sumCalc += a[i];
  }

  return sumCalc;
}



int maxSubArraySum(const int *a, int size) {

  int i = 0;
  int j = 0;
  int k = 0;

  int sum = 0;
  int maxSum = 0;

    for(i = 0; i < size; i++) {
      for(j = i; j < size; j++) {
        sum = 0;
        for(k = i ; k < j; k++) {
          sum = sum + a[k];
        }
        if(sum > maxSum)
          maxSum = sum;
      }
     }
     return maxSum;
}




int isEqual(const int *a, const int *b, int size) {

  int i = 0;
  for (i = 0;i < size; i++) {
    if (a[i] != b[i]) {
      return 0;
    }
  }

  return 1;
}



int containsSameElements(const int *a, int sizeOfA, const int *b, int sizeOfB) {

  int i = 0;
  int counter = 0;

if (sizeOfA < sizeOfB) {
  for (i = 0;i < sizeOfB;i++) {
    if (b[i] == a[i]) {
      counter++;
    }
  }
  if (counter == sizeOfA) {
    return 1;
  }
  else if (counter != sizeOfA) {
    return 0;
  }
}

else if (sizeOfA > sizeOfB) {
  for (i = 0; i < sizeOfA;i++) {
    if (b[i] == a[i]) {
      counter++;
    }
  }
  if (counter == sizeOfB) {
    return 1;
  }
  else if (counter != sizeOfB) {
    return 0;
  }

else if (sizeOfA == sizeOfB) {
  for (i=0;i<sizeOfA;i++) {
    if (b[i] == a[i]) {
          counter++;
        }
      }
  if (counter == sizeOfA) {
    return 1;
  }
  else if (counter != sizeOfA) {
  return 0;
  }
}


}
return 0;
}



int orderStatistic(const int *a, int size, int k) {
   int i = 0;

   int *aCopy = (int *) malloc(size * sizeof(int));
   for(i=0; i<size; i++) {
     aCopy[i] = a[i];
   }

   selectionSort(aCopy, size);

   int result = aCopy[k];


   free(aCopy);


   return result;
}



void selectionSort(int *aCopy, int size) {
  int i, j, minIndex;
  for(i=0; i<size-1; i++) {
    minIndex = i;
    for(j=i+1; j<size; j++) {
      if(aCopy[minIndex] > aCopy[j]) {
        minIndex = j;
  }
}
//swap
    int t = aCopy[i];
    aCopy[i] = aCopy[minIndex];
    aCopy[minIndex] = t;
  }
}
