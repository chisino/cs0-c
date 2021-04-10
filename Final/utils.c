/**
 * Name: Artiom Dolghi
 *
 * CSCE 155E Final
 *
 * This file includes the function definitions for the pokemon program
 */
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#include "utils.h"

char * deepCopy(const char *s) {
  char *copy = (char *) malloc( (strlen(s) + 1) * sizeof(char) );
  strcpy(copy, s);
  return copy;
}

char ** split(const char *str, char delimiter, int *n) {

  int i, numDelimiters = 0;
  char delimit[] = {delimiter, '\0'};
  char *s = deepCopy(str);
  chomp(s);
  for(i=0; i<strlen(str); i++) {
    if(str[i] == delimiter) {
      numDelimiters++;
    }
  }

  char **result = (char **) malloc(sizeof(char**) * (numDelimiters+1));
  char *token = strtok(s, delimit);
  i = 0;
  while(token != NULL) {
    result[i] = deepCopy(token);
    token = strtok(NULL, delimit);
    i++;
  }

  free(s);
  *n = (numDelimiters+1);
  return result;
}

void freeStringArray(char **stringArray, int n) {
  int i;
  for(i=0; i<n; i++) {
    free(stringArray[i]);
  }
  free(stringArray);
  return;
}

void chomp(char *str) {
  int i = strlen(str)-1;
  while(i >= 0 && isspace(str[i])) {
    str[i] = '\0';
    i--;
  }
}

int getnumLines(const char *fileName) {
	FILE *f = fopen(fileName, "r");
	// c is character
	char c ;
	int line = 0;
	if (f == NULL){
	return 0;
	}
	while ((c = fgetc(f)) != EOF)
	{
		if (c == '\n'){
			line++;
		}
	}
		fclose(f);
		return line;
}

void initPokemon(Pokemon* p, int pokeID, const char* name, const char* type) {

  //setting the fields of the structure
  p->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
  strcpy(p->name, name);

  p->type = (char *)malloc(sizeof(char) * (strlen(type) + 1));
  strcpy(p->type, type);

  p->pokeID = pokeID;
}

Pokemon* createPokemon(int pokeID, const char* name, const char* type) {

  //dynamically allocating the new structure
  Pokemon *p = (Pokemon *)malloc(sizeof(Pokemon) + 1);

  //calling init function so there is less repeated code
  initPokemon(p, pokeID, name, type);

  return p;
}

Pokemon* pokemonArray(const char *filePath) {
  FILE *f = fopen(filePath, "r");

  int n = getnumLines(filePath);

  Pokemon* pokemons = (Pokemon*) malloc(sizeof(Pokemon) * n);

  int i = 0;
  char buff[1000];

  for (i=0;i<n;i++) {
    int numTokens;
    fgets(buff,1000,f);
    char **tokens = split(buff, ',', &numTokens);
    Pokemon *p = createPokemon(atoi(tokens[0]), tokens[1], tokens[2]);
    pokemons[i] = *p;
    free(p);
  }

  fclose(f);

  return pokemons;
}

void initPokemonType(pokemonType* p, const char* attack, const char* defense, double multiplier) {

  //setting the fields of the structure
  p->attack = (char *)malloc(sizeof(char) * (strlen(attack) + 1));
  strcpy(p->attack, attack);

  p->defense = (char *)malloc(sizeof(char) * (strlen(defense) + 1));
  strcpy(p->defense, defense);

  p->multiplier = multiplier;
}

pokemonType* createPokemonType(const char* attack, const char* defense, double multiplier) {

  //dynamically allocating the new structure
  pokemonType *p = (pokemonType *)malloc(sizeof(pokemonType) + 1);

  //calling init function so there is less repeated code
  initPokemonType(p, attack, defense, multiplier);

  return p;
}

char* pokemonTypeToString(const pokemonType* p) {

  //figuring out how much space is needed
  int n = strlen(p->attack) + strlen(p->defense) + 1000;

  //allocating memory for the string
  char *str = (char *)malloc(sizeof(char) * n + 1);

  //putting the values into the string
  sprintf(str, "%s , %s (%f)\n", p->attack, p->defense, p->multiplier);

  str[n] = '\0';

  return str;
}

pokemonType* pokemonTypeArray(const char *filePath) {
  FILE *g = fopen(filePath, "r");

  int n = getnumLines(filePath);

  pokemonType* pokemonTypes = (pokemonType*) malloc(sizeof(pokemonType) * n);

  int i = 0;
  char buff[1000];

  for (i=0;i<n;i++) {
    int numTokens;
    fgets(buff,1000,g);
    char **tokens = split(buff, ' ', &numTokens);
    pokemonType *p = createPokemonType(tokens[0], tokens[1], atof(tokens[2]));
    pokemonTypes[i] = *p;
    free(p);
  }

  fclose(g);

  return pokemonTypes;
}
