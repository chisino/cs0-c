/**
* Author: Artiom Dolghi
* Date Due: October 5, 2018
*
* This file includes the prototypes and documentation of functions for hack 7
*/

//This function determines if an array contains "x" anywhere within the array
int contains(const int *arr, int size, int x);

//This function determines if an array contains x within "i" and "j"
int containsWithin(const int *arr, int size, int x, int i, int j);

//This function creates a new deep copy of an array
int * paddedCopy(const int *arr, int oldSize, int newSize);

//This function reverses the elements in an array
void reverse(int *arr, int size);

//This function creates and returns a new copy of an array in reversed order
int * reverseCopy(const int *arr, int size);
