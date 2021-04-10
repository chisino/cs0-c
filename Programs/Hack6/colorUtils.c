/**
* Author: Artiom Dolghi
* Date Due: September 28, 2018
*
* This file is composed of the function definitions for hack 6
*/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "colorUtils.h"

int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k) {

	if (c == NULL) {
		return 1;
	}

	if (m == NULL) {
		return 1;
	}

	if (y == NULL) {
		return 1;
	}

	if (k == NULL) {
		return 1;
	}

	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0) {
		return 1;
	}
	else {

	double rConverted = r / 255.0;
	double gConverted = g / 255.0;
	double bConverted = b / 255.0;

	if (rConverted > gConverted && rConverted > bConverted) {
		*k = 1.0 - rConverted;
	}

	else if (rConverted > gConverted && rConverted == bConverted) {
		*k = 1.0 - rConverted;
	}

	else if (rConverted == gConverted && rConverted > bConverted) {
		*k = 1.0 - rConverted;
	}


	else if (gConverted > rConverted && gConverted > bConverted) {
		*k = 1.0 - gConverted;
	}

	else if (gConverted > rConverted && gConverted == bConverted) {
		*k = 1.0 - gConverted;
	}

	else if (gConverted == rConverted && gConverted > bConverted) {
		*k = 1.0 - gConverted;
	}


	else if (bConverted > rConverted && bConverted > gConverted) {
		*k = 1.0 - bConverted;
	}

	else if (bConverted > rConverted && bConverted == gConverted) {
		*k = 1.0 - bConverted;
	}

	else if (bConverted == rConverted && bConverted > gConverted) {
		*k = 1.0 - bConverted;
	}


	double cValue = (1.0 - rConverted - *k) / (1.0 - *k);
	double mValue = (1.0 - gConverted - *k) / (1.0 - *k);
	double yValue = (1.0 - bConverted - *k) / (1.0 - *k);

	*c = cValue;
	*m = mValue;
	*y = yValue;

return 0;

}
}

int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b) {

	if (r == NULL) {
		return 1;
	}

	if (g == NULL) {
		return 1;
	}

	if (b == NULL) {
		return 1;
	}

	if (c > 1 || c < 0 || m > 1 || m < 0 || y > 1 || y < 0 || k > 1 || k < 0) {
		return 1;
	}

	else {

	double rValue = 255 * (1 - c) * (1 - k);
	double gValue = 255 * (1 - m) * (1 - k);
	double bValue = 255 * (1 - y) * (1 - k);

	*r = round(rValue);
	*g = round(gValue);
	*b = round(bValue);

return 0;
}
}


int toGrayScale(int *r, int *g, int *b, Mode m) {

	if (r == NULL) {
		return 1;
	}

	if (g == NULL) {
		return 1;
	}

	if (b == NULL) {
		return 1;
	}

	if (m > 3) {
		return 1;
	}

	if (*r > 255 || *r < 0 || *g > 255 || *g < 0 || *b > 255 || *b < 0) {
		return 1;
	}

	else {

	double avgConvert = 0.0;
	double maxRGB = 0.0;
	double minRGB = 0.0;
	double lightConvert = 0.0;
	double luminConvert = 0.0;

	if (m == AVERAGE) {
		avgConvert = (*r + *g + *b) / 3.0;
		*r = round(avgConvert);
		*g = round(avgConvert);
		*b = round(avgConvert);
	}

	if (m == LIGHTNESS) {
		if (*r > *g && *r > *b) {
		maxRGB = *r;
		}

		else if (*r > *g && *r == *b) {
			maxRGB = *r;
		}

		else if (*r == *g && *r > *b) {
			maxRGB = *r;
		}


		else if (*g > *r && *g > *b) {
		maxRGB = *g;
		}

		else if (*g > *r && *g == *b) {
			maxRGB = *g;
		}

		else if (*g == *r && *g > *b) {
			maxRGB = *g;
		}


		else if (*b > *r && *b > *g) {
		maxRGB = *b;}

		else if (*b == *r && *b > *g) {
		maxRGB = *b;}

		else if (*b > *r && *b == *g) {
		maxRGB = *b;}


		if (*r < *g && *r < *b) {
		minRGB = *r;
		}

		else if (*r < *g && *r == *b) {
		minRGB = *r;
		}

		else if (*r == *g && *r < *b) {
		minRGB = *r;
		}


		else if (*g < *r && *g < *b) {
		minRGB = *g;
		}

		else if (*g < *r && *g == *b) {
		minRGB = *g;
		}

		else if (*g == *r && *g < *b) {
		minRGB = *g;
		}

		else if (*b < *r && *b < *g) {
		minRGB = *b;}

		else if (*b == *r && *b < *g) {
		minRGB = *b;}

		else if (*b < *r && *b == *g) {
		minRGB = *b;}


	lightConvert = (maxRGB + minRGB) / 2;
*r = round(lightConvert);
*g = round(lightConvert);
*b = round(lightConvert);

	}

	if (m == LUMINOSITY) {
		luminConvert = round((.21 * *r) + (.72 * *g) + (.07 * *b));
		*r = (luminConvert);
		*g = (luminConvert);
		*b = (luminConvert);
	}

	return 0;
}
	}
