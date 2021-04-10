/**
* Author: Artiom Dolghi
* Date Due: September 28, 2018
*
* This program computes the arithmetic-geometric mean of two positive numbers
*/
#include<stdlib.h>
#include<stdio.h>
#include <math.h>

int main(int argc, char **argv) {

double x = atof(argv[1]);
double y = atof(argv[2]);
double e = atof(argv[3]);

double a = 0.5 * (x + y);
double g = sqrt(x * y);


int i;
double aNext;
double gNext;
for (i = 1; fabs(a - g) >= e; i++) {
  aNext = 0.5 * (a + g);
  gNext = sqrt(a * g);
  a = aNext;
  g = gNext;
}


printf("M(%f, %f): %lf\n", x, y, a);




return 0;
}
