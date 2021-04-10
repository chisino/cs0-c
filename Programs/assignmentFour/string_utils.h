/**
* Author: Artiom Dolghi
* Date Due: November 9, 2018
*
* This file includes the prototypes and documentation of functions for assignment 3
* (part 1)
*/

//This function determines if str contains subStr
int strContains(const char *str, const char *subStr);

//This function takes two strings and concatenates them into a new string
char *concatenate(const char *s, const char *t);

//This function takes two strings and appends t to s, returning a new string
char *append(const char *s, const char *t);

//This function takes two strings and prepends t to s, returning a new string
char *prepend(const char *s, const char *t);

//This function takes a string and returns a new copy of a substring of it
//starting from a specific index to the end of the string
char *substringToEnd(const char *s, int beginningIndex);

/*This function takes a string and returns a new copy of a substring of
*it starting from a specified index (inclusive) and going a specified ending
*index (exclusive)
*/
char *substringIndex(const char *s, int beginIndex, int endIndex);

//This function takes a string and returns a new copy of a substring of it
//starting from a specified index of a particular size
char *substringSize(const char *s, int beginningIndex, int size);
