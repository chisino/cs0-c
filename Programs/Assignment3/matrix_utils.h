/**
* Author: Artiom Dolghi
* Date Due: October 19, 2018
*
* This file includes the prototypes and documentation for the
* various matrices functions
* Assignment 3, part 3
*/

//This function constructs a new n x n identity matrix
int **getIdentityMatrix(int n);

//This function takes two matrices and determines if they are equal
int isEqual(int **A, int **B, int n);

//This function takes a matrix and an index i and returns
//a new array that is equal to the i-th row of the matrix.
int *getRow(int **A, int n, int i);

//This function takes a matrix and an index j
//and returns a new array that is equal to the j-th column of the matrix
int *getCol(int **A, int n, int j);

//This function computes the product of two n × n square matrices
int ** product(int **A, int **B, int n);
