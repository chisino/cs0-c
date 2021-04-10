/**
 * Name: Chris Bourke
 *
 * CSCE 155E Midterm
 *
 * Write a full program to determine if two circles intersect.
 * Details are provided in the midterm handout.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  if(argc != 7) {
    printf("Expected 6 numbers\n");
    exit(1);
  }

  double x1 = atof(argv[1]);
  double y1 = atof(argv[2]);
  double r1 = atof(argv[3]);
  double x2 = atof(argv[4]);
  double y2 = atof(argv[5]);
  double r2 = atof(argv[6]);

  if(r1 < 0 || r2 < 0) {
    printf("Error: a radius cannot be negative\n");
    exit(1);
  }

  double distance = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );

  if(distance <= r1 + r2) {
    printf("Circles (%f, %f, %f) and (%f, %f, %f) intersect!!\n", x1, y1, r1, x2, y2, r2);
  } else {
    printf("Circles (%f, %f, %f) and (%f, %f, %f) do not intersect!!\n", x1, y1, r1, x2, y2, r2);
  }


  return 0;
}
