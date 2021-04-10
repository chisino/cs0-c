/**
* Author: Artiom Dolghi
* Date Due: September 28, 2018
*
* This program will run the functions from hack 6 and check the test cases
*/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "colorUtils.h"

int main(int arg, char **argv) {

  double c = 0.0;
  double m = 0.0;
  double y = 0.0;
  double k = 0.0;



  printf("Test cases for rgbToCMYK function:\n\n");

//Test case 1: r = 100, g = 50, b = 10

  int r = 100;
  int g = 50;
  int b = 10;

  rgbToCMYK(r, g, b, &c, &m, &y, &k);

  double expectedC = 0;
  double expectedM = .5;
  double expectedY = .9;
  double expectedK = .6078;

  printf("r = 100, g = 50, b = 10\n");

  printf("Result: %.3f, %.3f, %.3f, %.3f\nExpected: %.3f, %.3f, %.3f, %.3f\n\n", c, m, y, k, expectedC, expectedM, expectedY, expectedK);

//Test case 2: r = 30, g = 100, b = 80

  r = 30;
  g = 100;
  b = 80;

  rgbToCMYK(r, g, b, &c, &m, &y, &k);

  expectedC = .7;
  expectedM = 0;
  expectedY = .2;
  expectedK = .6078;

  printf("r = 30, g = 100, b = 80\n");

  printf("Result: %.3f, %.3f, %.3f, %.3f\nExpected: %.3f, %.3f, %.3f, %.3f\n\n", c, m, y, k, expectedC, expectedM, expectedY, expectedK);

//Test case 3: r = 200, g = 20, b = 100

  r = 200;
  g = 20;
  b = 100;

  rgbToCMYK(r, g, b, &c, &m, &y, &k);

  expectedC = 0;
  expectedM = .9;
  expectedY = .5;
  expectedK = .2157;

  printf("r = 200, g = 20, b = 100\n");

  printf("Result: %.3f, %.3f, %.3f, %.3f\nExpected: %.3f, %.3f, %.3f, %.3f\n\n", c, m, y, k, expectedC, expectedM, expectedY, expectedK);


////////////////////////////////////////////////////////////////////////////////
  r = 0.0;
  g = 0.0;
  b = 0.0;

  printf("Test cases for cmykToRGB function:\n\n");

//Test case 1: c = .2, m = .1, y = .4, k = .3

  c = .2;
  m = .1;
  y = .4;
  k = .3;

  cmykToRGB(c, m, y, k, &r, &g, &b);

  int expectedR = 143;
  int expectedG = 161;
  int expectedB = 107;

  printf("c = .2, m = .1, y = .4, k = .3\n");

  printf("Result: %d, %d, %d\nExpected: %d, %d, %d\n\n", r, g, b, expectedR, expectedG, expectedB);

//Test case 2: c = .6, m = .1, y = .05, k = .25

  c = .6;
  m = .1;
  y = .05;
  k = .25;

  cmykToRGB(c, m, y, k, &r, &g, &b);

  expectedR = 77;
  expectedG = 172;
  expectedB = 182;

  printf("c = .6, m = .1, y = .05, k = .25\n");

  printf("Result: %d, %d, %d\nExpected: %d, %d, %d\n\n", r, g, b, expectedR, expectedG, expectedB);

//Test case 3: c = .1, m = .2, y = .3, k = .4

  c = .1;
  m = .2;
  y = .3;
  k = .4;

  cmykToRGB(c, m, y, k, &r, &g, &b);

  expectedR = 138;
  expectedG = 122;
  expectedB = 107;

  printf("c = .1, m = .2, y = .3, k = .4\n");

  printf("Result: %d, %d, %d\nExpected: %d, %d, %d\n\n", r, g, b, expectedR, expectedG, expectedB);

////////////////////////////////////////////////////////////////////////////////

  printf("Test cases for toGrayScale function:\n\n");

//Test case 1: r = 150, g = 50, b = 30

  r = 150;
  g = 50;
  b = 30;

  toGrayScale(&r, &g, &b, m);

  expectedR = 77;
  expectedG = 77;
  expectedB = 77;

  printf("r = 150, g = 50, b = 30\n");

  printf("Result: %d, %d, %d\nExpected: %d, %d, %d\n\n", r, g, b, expectedR, expectedG, expectedB);

//Test case 2: r = 45, g = 100, b = 70

  r = 45;
  g = 100;
  b = 70;

  toGrayScale(&r, &g, &b, m);

  expectedR = 72;
  expectedG = 72;
  expectedB = 72;

  printf("r = 45, g = 100, b = 70\n");

  printf("Result: %d, %d, %d\nExpected: %d, %d, %d\n\n", r, g, b, expectedR, expectedG, expectedB);

//Test case 3: r = 10, g = 30, b = 200

  r = 10;
  g = 30;
  b = 200;

  toGrayScale(&r, &g, &b, m);

  expectedR = 80;
  expectedG = 80;
  expectedB = 80;

  printf("r = 10, g = 30, b = 200\n");

  printf("Result: %d, %d, %d\nExpected: %d, %d, %d\n\n", r, g, b, expectedR, expectedG, expectedB);

////////////////////////////////////////////////////////////////////////////////

  return 0;
}
