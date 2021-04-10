/**
* Author: Artiom Dolghi
* Date Due: October 12, 2018
*
* This program will run the functions from hack 8
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "string_utils.h"
#include <math.h>
#include <ctype.h>

int main(int arg, char **argv) {

printf("Test cases for replaceChar function:\n\n");

//Test case 1

char s[] = "Hello World";
char oldChar = 'l';
char newChar = 'y';

replaceChar(s, oldChar, newChar);

printf("%s\n\n", s);

//Test case 2

char s2[] = "Hello World";

strcpy(s, s2);

oldChar = 'o';
newChar = 'u';

replaceChar(s, oldChar, newChar);

printf("%s\n\n", s);

//Test case 3

strcpy(s, s2);

oldChar = 'd';
newChar = 'v';

replaceChar(s, oldChar, newChar);

printf("%s\n\n", s);


////////////////////////////////////////////////////////////////////////////////

printf("Test cases for replaceCharCopy function:\n\n");

//Test case 1
strcpy(s, s2);

oldChar = 'l';
newChar = 'y';

char* result = replaceCharCopy(s, oldChar, newChar);

printf("%s\n\n", result);

//Test case 2
strcpy(s, s2);

oldChar = 'o';
newChar = 'u';

result = replaceCharCopy(s, oldChar, newChar);

printf("%s\n\n", result);

//Test case 3
strcpy(s, s2);

oldChar = 'd';
newChar = 'v';

result = replaceCharCopy(s, oldChar, newChar);

printf("%s\n\n", result);

////////////////////////////////////////////////////////////////////////////////

printf("Test cases for removeChar function:\n\n");

//Test case 1
strcpy(s, s2);

char c = 'o';

removeChar(s,c);

printf("%s\n\n", s);

//Test case 2
strcpy(s, s2);

c = 'l';

removeChar(s,c);

printf("%s\n\n", s);

//Test case 3
strcpy(s, s2);

c = 'r';

removeChar(s,c);

printf("%s\n\n", s);

////////////////////////////////////////////////////////////////////////////////

printf("Test cases for removeCharCopy function:\n\n");

//Test case 1
strcpy(s, s2);

c = 'o';

char* result2 = removeCharCopy(s,c);

printf("%s\n\n", result2);

//Test case 2
strcpy(s, s2);

c = 'l';

result2 = removeCharCopy(s,c);

printf("%s\n\n", result2);

//Test case 3
strcpy(s, s2);

c = 'r';

result2 = removeCharCopy(s,c);

printf("%s\n\n", result2);

////////////////////////////////////////////////////////////////////////////////

printf("Test cases for lengthSplit function:\n\n");

//Test case 1

strcpy(s, s2);
int n = 3;

char** result3 = lengthSplit(s, n);


printf("%s\n\n", *result3);





return 0;
}
