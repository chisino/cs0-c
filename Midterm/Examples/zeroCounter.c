#include<stdlib.h>
#include<stdio.h>

/**
 * This function takes an integer array and counts
 * the number of values in it that are zero, returning
 * that result.
 *
 * If the input is invalid, this function returns -1.
 */
int countZeros(const int *arr, int size);

//you may use this main function as you wish to test
//but it must be removed or commented out when turned in

int main(int argc, char **argv) {
  int n = 11;
  int arr[] = {10, 20, 0, 5, 3, 0, 2, 0, 0, 0, 0};
  int numZeros = countZeros(arr, n);
  printf("There are %d zeros in that array.\n", numZeros);
  return 0;
}

int countZeros(const int *arr, int size) {

  if(arr == NULL || size < 0) {
    return -1;
  }
  int numberOfZeros = 0;
  for(int i=0; i<size; i++) {
    if(arr[i] == 0) {
      numberOfZeros++;
    }
  }
  return numberOfZeros;
}
