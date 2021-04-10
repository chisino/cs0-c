/**
* Author: Artiom Dolghi
* Date Due: November 9, 2018
* This program will open an HTML file, scrub certain characters and write
* the results to a new output file
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){

  //error checking to make sure # of args is correct
  if (argc < 3 || argc > 3) {

    return 0;
  }

  //opening the input file (f) for reading and output file (g) for writing
  FILE *f = fopen(argv[1], "r");

	FILE *g = fopen(argv[2], "w");

  //error checking to make sure either file is not NULL
  if (f == NULL || g == NULL) {

    return 0;
  }

  char checkChar;

  //loop for writing to the output file
  while ((checkChar = fgetc(f)) != EOF) {

    if (checkChar == '&') {
      fputs("&amp;", g);
    }

    else if (checkChar == '<') {
      fputs("&lt;", g);
    }

    else if (checkChar == '>') {
      fputs("&gt;", g);
    }

    else if (checkChar == '"') {
     fputs("&quot;", g);
    }

    //if there are no characters to replace, just print the character from f
    else {
      putc(checkChar, g);
    }
  }

    //closing the input (f) file and output (g) file
    fclose(f);
    fclose(g);

  return 0;
}
