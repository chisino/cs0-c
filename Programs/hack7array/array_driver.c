/**
* Author: Artiom Dolghi
* Date Due: October 5, 2018
*
* This program will run the functions from hack 7 and check the test cases
*/

#include<stdlib.h>
#include<stdio.h>
#include "array_utils.h"

int main(int arg, char **argv) {

  //int contains test cases:

  int arr[] = {1, 2, 3, 4, 5};
  int x = 3;
  int size = 5;

  contains(arr, size, x);

  ///////////////////////////////

  // int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
  // int x = 14;
  // int size = 8;
  //
  // contains(arr, size, x);

  ///////////////////////////////

  // int arr[] = {3, 6, 9};
  // int x = 10;
  // int size = 3;
  //
  // contains(arr, size, x);

  //////////////////////////////////////////////////////////////////////////////


//int containsWithin test cases:

// int arr[] = {1, 2, 3, 4, 5};
// int x = 3;
// int size = 5;
// int i = 2;
// int j = 4;
//
// containsWithin(arr, size, x, i, j);

////////////////////////////////////

// int arr[] = {4, 8, 12, 16, 20};
// int x = 16;
// int size = 5;
// int i = 2;
// int j = 4;
//
// containsWithin(arr, size, x, i, j);

///////////////////////////////////

// int arr[] = {3, 6, 9, 12, 15, 18, 21, 24};
// int x = 3;
// int size = 8;
// int i = 2;
// int j = 4;
//
// containsWithin(arr, size, x, i, j);

///////////////////////////////////////////////////////////////////////////////

//int *paddedCopy test cases

// int arr[] = {1, 2, 3, 4, 5};
// int oldSize = 5;
// int newSize = 10;
//
// *paddedCopy(arr, oldSize, newSize);

////////////////////////////////////

// int arr[] = {1, 2, 3, 4, 5};
// int oldSize = 10;
// int newSize = 5;
//
// *paddedCopy(arr, oldSize, newSize);

///////////////////////////////////////////////////////////////////////////////

//void reverse test cases

// int arr[] = {1, 2, 3, 4, 5};
// int size = 5;
//
// reverse(arr, size);

//////////////////////////////////////////////////////////////////////////////

//int reverseCopy test cases

// int arr[] = {1, 2 ,3 ,4 ,5};
// int size = 5;
//
// *reverseCopy(arr, size);

return 0;
}
