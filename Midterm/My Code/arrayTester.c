
#include<stdlib.h>
#include<stdio.h>

#include "array_utils.h"

int main(int argc, char **argv) {

  int n = 5;
  int a[] = {1, 6, 7, 2, 3};
  int b[] = {9, 4, 2, 5, 2};

  int d;
  int err = dotProduct(a, b, n, &d);
  if(err) {
    printf("There were an error.\n");
  } else {
    printf("dot product = %d\n", d);
  }
  return 0;
}
