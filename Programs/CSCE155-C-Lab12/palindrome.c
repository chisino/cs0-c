
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This function should return true if the given (sub)string is
 * a palindrome.  The function should be recursive.
 */
int isPalindrome(const char *str, int left_index, int right_index);

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: isPalindrome word\n");
    exit(1);
  }

  int isPal = isPalindrome(argv[1], 0, strlen(argv[1]) - 1);
  if (isPal) {
    printf("%s is a palindrome!\n", argv[1]);
  } else {
    printf("%s is NOT a palindrome!\n", argv[1]);
  }
  return 0;
}

int isPalindrome(const char *str, int left_index, int right_index) {

int i = 0;

if (left_index >= right_index) {
  return 1;
}
if (str[left_index] == str[right_index]) {
  return isPalindrome(str, left_index + 1, right_index - 1);
}
return 0;
}
