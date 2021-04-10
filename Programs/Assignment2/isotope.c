/**
* Author: Artiom Dolghi
* Date Due: September 14, 2018
*
* This program will produce a table detailing the amount of an element that
* remains after each year until less than 50% of the original amount remains
* using the formula: r = m x (1/2)pow(y, H)
*/
#include<stdlib.h>
#include<stdio.h>
#include <math.h>

int main(int argc, char **argv) {

int atomicNumber = atoi(argv[1]);
int atomicNumPrint = atomicNumber;

char elementName = atoi(argv[2]);
char elementSymbol = atoi(argv[3]);
double halfLife = atof(argv[4]);
double initialMass = atof(argv[5]);

printf("%s (%d-%s)\n", argv[2], atomicNumPrint, argv[3]);
printf("Year   Amount\n");
printf("------------\n");

int i = 0;
double elementRemaining1 = pow(.5, i / halfLife);
double elementRemaining2 = initialMass * elementRemaining1;
double halfRemaining = .5 * elementRemaining2;

for (i=0; elementRemaining2 > halfRemaining; i++ ) {

elementRemaining1 = pow(.5, i / halfLife);
elementRemaining2 = initialMass * elementRemaining1;


  printf("%2d %10.3fg \n", i, elementRemaining2);
}





return 0;
}
