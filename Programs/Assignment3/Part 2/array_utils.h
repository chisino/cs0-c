/**
* Author: Artiom Dolghi
* Date Due: October 19, 2018
*
* This file includes the prototypes and documentation for various
* array functions
* Assignment 3, part 2 (arrays)
*/

//This function takes an integer array and returns the sum
//of its elements between two given indices, i, j (inclusive for both)
int subSum(const int *a, int size, int i, int j);

//This function takes an integer array and returns
//the sum of all of its elements
int sum(const int *a, int size);

//This function takes an integer array and
//returns the sum of the maximum contiguous subarray
int maxSubArraySum(const int *a, int size);

//This function takes two integer arrays and determines if they are equal
int isEqual(const int *a, const int *b, int size);

//This function two integer arrays and determines if
//they both contain the same elements
int containsSameElements(const int *a, int sizeOfA, const int *b, int sizeOfB);

//This function finds the k-th order statistic
int orderStatistic(const int *a, int size, int k);

//This function helps with sorting in the orderStatistic function
void selectionSort(int *aCopy, int size);
