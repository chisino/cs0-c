#include <stdio.h>
#include <stdlib.h>

void rec(char *a, int n) {
  if (n==1) {
    printf("%s\n", a);
  }
  else {
    printf("%s\n", a);
    a = a + 1;
    rec(a, n-1);
  }
  }



int main(int agrc, char **argv) {
  rec(argv[1], sizeof(argv[1]));
  return 0;
}
