/**
* Author: Artiom Dolghi
* Date Due: October 19, 2018
*
* This program will run the convertPressure function
*/

#include<stdlib.h>
#include<stdio.h>
#include "pressure.h"

int main(int arg, char **argv) {

double pa = 0;
double psi = 0;
double atm = 0;
double torr = 0;

Scale scale = 0;

printf("1 - Pascal, 2 - Psi, 3 - Atm, 4 - Torr\n");
scanf("%d", &scale);

if (scale <= 4 && scale > 0) {
printf("Enter the value you wish to convert\n");
if (scale == 1) {
  scanf("%lf", &pa);
}
else if (scale == 2) {
  scanf("%lf", &psi);
}
else if (scale == 3) {
  scanf("%lf", &atm);
}
else if (scale == 4) {
  scanf("%lf", &torr);
}

convertPressure(&pa, &psi, &atm, &torr, scale);


printf("PA = %f\nPSI = %f\nATM = %f\nTORR = %f\n", pa, psi, atm, torr);
}

return 0;
}
