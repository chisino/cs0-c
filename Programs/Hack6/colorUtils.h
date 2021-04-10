/**
* Author: Artiom Dolghi
* Date Due: September 28, 2018
*
* This file includes the prototypes and documentation of functions for hack 6
*/

//This function converts from an RGB color model to CMYK
int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k);


//This function converts from a CMYK color model to RGB
int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b);


//This enumerated type specifies which three modes will be used in the toGrayScale function
typedef enum {
	AVERAGE,
	LIGHTNESS,
	LUMINOSITY
}Mode;

//This function converts from RGB to grayscale
int toGrayScale(int *r, int *g, int *b, Mode m);
