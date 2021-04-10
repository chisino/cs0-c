/**
* Author: Artiom Dolghi, Benoit Bikeli
* Date Due: November 9, 2018
*
* This file is composed of the function definitions for hack 12
*/

#include <stdlib.h>
#include <stdio.h>
#include "binomial.h"

long choose(int n, int k) {

  if (k == 0 || n == k) {
    return 1;
  }

  else {
    return choose(n - 1, k) + choose(n - 1, k - 1);
  }
}

long memoization(int n, int k, long **pasTable) {

  if (k == 0 || n == k) {
   return 1;
  }

  if (pasTable[n][k] != -1) {
    return pasTable[n][k];
  }

  else {
    long x = memoization(n-1, k, pasTable) + memoization(n-1, k-1, pasTable);
    pasTable[n][k] = x;
    return x;
  }
}
