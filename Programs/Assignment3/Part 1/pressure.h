/**
* Author: Artiom Dolghi
* Date Due: October 19, 2018
*
* This file includes the prototypes and documentation for the
* convertPressure function and the enum declaration
* Assignment 3, part 1
*/

//This enumerated type will take a value that dictates what the converrsion
//is from and will be used to convert to the remaining three

typedef enum {
  PASCAL = 1,
  PSI,
  ATM,
  TORR,
} Scale;

//This function will convert a single value to all 4 scales of:
//Pascal (Pa), Pound-force Per Square Inch (psi), Atmosphere (atm),
//and torr

int convertPressure(double *pa,
                    double *psi,
                    double *atm,
                    double *torr,
                    Scale scale);
