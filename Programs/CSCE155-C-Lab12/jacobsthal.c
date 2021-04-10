#include <stdio.h>
#include <stdlib.h>

int jacobsthalFunction(int n);

int main(int argc, char **argv) {
  int n = atoi(argv[1]);

  int result = jacobsthalFunction(n);

  printf("f(%d) = %d\n", n, result);

  return 0;
}

int jacobsthalFunction(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return jacobsthalFunction(n - 1) + 2*(jacobsthalFunction(n - 2));
  }
}
