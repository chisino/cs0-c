/**
 * Name: Artiom Dolghi
 *
 * CSCE 155E Final
 *
 * This program outputs the result of the two pokemon selected
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"


int main(int argc, char **argv) {

  if(argc != 3) {
    printf("Usage: %s pokemonName1 pokemonName2\n", argv[0]);
    exit(1);
  }

  Pokemon* pokemons = pokemonArray("pokemon.csv");

  pokemonType* pokemonTypes = pokemonTypeArray("pokemonTypes.dat");

  int i = 0;

  int pokeLines = getnumLines("pokemon.csv");

  for (i=0;i<pokeLines;i++) {
    if ( strcmp(pokemons[i].name, argv[1]) == 0 ) {
      break;
    }
  }

  int j = 0;

  for (j=0;j<pokeLines;j++) {
    if ( strcmp(pokemons[j].name, argv[2]) == 0 ) {
      break;
    }
  }

  int k = 0;

  int typeLines = getnumLines("pokemonTypes.dat");

  for (k=0;k<typeLines;k++) {
    if ( strcmp(pokemonTypes[k].attack, pokemons[i].type) == 0 ) {
      printf("%s (%s) attacks %s (%s) does x%.2f damage!\n", argv[1], pokemons[i].type,
                                                             argv[2], pokemons[j].type,
                                                             pokemonTypes[k].multiplier);
      break;
    }
  }


  return 0;
}
