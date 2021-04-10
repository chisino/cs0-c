/**
* Author: Artiom Dolghi
* Date Due: October 12, 2018
*
* This file includes the prototypes and documentation of functions for hack 8
*/

//This function replaces instances of a given character with a different
//character in a string
void replaceChar(char *s, char oldChar, char newChar);

//This function takes a string and creates a new copy of it but with
//instances of a given character replaced with a different character.
char * replaceCharCopy(const char *s, char oldChar, char newChar);

//This function takes a string and removes all instances of a
//certain character from it.
void removeChar(char *s, char c);

//This function takes a string and creates a new copy of it
//but with all instances of a specified character removed from it.
char * removeCharCopy(const char *s, char c);

//This function takes a string and splits it up to an array of strings.
char **lengthSplit(const char *s, int n);
