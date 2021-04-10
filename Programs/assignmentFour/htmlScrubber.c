/**
* Author: Artiom Dolghi
* Date Due: November 9, 2018
* This program will open an HTML file, scrub certain characters and write
* the results to a new output file
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Function that gets a file's contents and turns them into a string
char *getFileContents(const char *filePath);

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

  char *result = getFileContents(argv[1]);
  //Done with using f, contents now in a string
  fclose(f);

  int i = 0;

  //printing from string to output file g
  for (i = 0;i<strlen(result);i++) {
    if (result[i] == '&') {
      fprintf(g, "&amp;");
    }
    else if (result[i] == '<') {
      fprintf(g, "&lt;");
    }
    else if (result[i] == '>') {
      fprintf(g, "&gt;");
    }
    else if (result[i] == '"') {
      fprintf(g, "&quot;");
    }
    else {
      fprintf(g, "%c", result[i]);
    }
  }

  //closing output file g
  fclose(g);

  return 0;
}

//Function definition
char *getFileContents(const char *filePath) {
  FILE *f = fopen(filePath, "r");
  int buffer = 0;
  while ((fgetc(f)) != EOF) {
    buffer = buffer + 1;
  }
  char *str = (char*) malloc(sizeof(char) * (buffer + 1));
  rewind(f);
  int i = 0;
  for (i=0; i<buffer; i++) {
    str[i] = fgetc(f);
  }
  str[buffer] = '\0';
  fclose(f);
  return str;
}
