/**
* Author: Artiom Dolghi, Benoit Bikeli
* Date Due: November 9, 2018
*
* This program will run the functions from hack 12
*/

#include <stdlib.h>
#include <stdio.h>
#include "binomial.h"

int main(int arg, char **argv) {

  int n = atoi(argv[1]);

  int k = atoi(argv[2]);

  long **pasTable = (long **)malloc(sizeof(long) * (n+1));

  int i = 0;

  int j = 0;

  for(i=0;i<n+1;i++) {
	 pasTable[i] = (long *)malloc(sizeof(long) * (k+1));
		for (j=0;j<k+1;j++) {
			pasTable[i][j] = -1;
		}
   }

  long result = memoization(n, k, pasTable);

  printf("C(%d , %d) = %ld\n", n, k, result);


  return 0;
}
