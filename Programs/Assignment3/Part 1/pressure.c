/**
* Author: Artiom Dolghi
* Date Due: October 19, 2018
*
* This file is composed of the definition of the function convertPressure
* Assignment 3, part 1
*/

#include<stdlib.h>
#include<stdio.h>
#include "pressure.h"

int convertPressure(double *pa, double *psi, double *atm, double *torr, Scale scale) {

if (pa == NULL || psi == NULL || atm == NULL || torr == NULL) {
  return 1;
}

if (scale > 4 || scale < 0) {
  return 1;
}

  if (scale == PASCAL) {
    if (*pa < 0) {
      return 1;
    }
    else {
  *psi = *pa / 6894.75729;
  *atm = *pa / 101325.0;
  *torr = *pa / (101325 / 760.0);
}
 }

 else if (scale == PSI) {
   if (*psi < 0) {
     return 1;
   }
   else {
   *pa = *psi * 6894.75729;
   *atm = *psi * .068045964;
   *torr = (*psi * .068045964) * 760.0;
 }
  }

 else if (scale == ATM) {
   if (*atm < 0) {
     return 1;
   }
   else {
   *psi = *atm / .068045964;
   *pa = *atm * 101325.0;
   *torr = *atm * 760.0;
 }
  }

else if (scale == TORR) {
  if (*torr < 0) {
    return 1;
  }
  else {
  *pa = *torr * (101325.0 / 760.0);
  *atm = *torr / 760.0;
  *psi = (*torr * (101325.0 / 760.0)) / 6894.75729;
}
  }

return 0;
}
