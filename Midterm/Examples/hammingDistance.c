#include<stdlib.h>
#include<stdio.h>

/**
 * This function computes the Hamming distance of the two
 * binary arrays both of the specified size and places
 * The value in the last parameter.
 *
 * An error code is returned for any potential errors including
 * the case that either a or b contain non-binary data (integer
 * values other than 0 or 1).
 */
int hammingDistance(const int *a, const int *b, int size, int *hamDist) {
  if(a == NULL || b == NULL || hamDist == NULL) {
    return 1;
  }
  int counter = 0;
  for(int i=0; i<size; i++) {
    if(a[i] < 0 || a[i] > 1 ||
       b[i] < 0 || b[i] > 1) {
         return 1;
       }
    if(a[i] != b[i]) {
      counter++;
    }
  }
  *hamDist = counter;
  return 0;
}

/*
You can/should use the following main function to test
your code, but IT SHOULD NOT BE INCLUDED IN THE FINAL
HAND IN!
*/
int main(int argc, char **argv) {
  int n = 7;
  int a[] = {0, 1, 1, 1, 0, 0, 1};
  int b[] = {1, 0, 0, 0, 1, 1, 0, 1};
  int result;
  int err = hammingDistance(a, b, n, &result);
  printf("err = %d, result = %d\n", err, result);
}
