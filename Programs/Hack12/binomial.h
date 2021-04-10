/**
* Author: Artiom Dolghi, Benoit Bikeli
* Date Due: November 9, 2018
*
* This file includes the prototypes and documentation of functions for hack 12
*/

//This function takes n and k and computes "n choose k" using Pascal's rule
long choose(int n, int k);

//This function utilizes a table in order to find "n choose k" quicker
long memoization(int n, int k, long **pasTable);
