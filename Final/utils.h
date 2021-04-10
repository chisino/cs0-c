/**
 * Name: Artiom Dolghi
 *
 * CSCE 155E Final
 *
 * This file includes the function prototypes for the pokemon program
 */

//This structure defines the parts of a pokemon (pokemon.csv)
typedef struct {
  int pokeID;
  char* name;
  char* type;
} Pokemon;

//This function defines the pokemon type (pokemonTypes.dat)
typedef struct {
  char* attack;
  char* defense;
  double multiplier;
} pokemonType;

/**
 * Utility function that performs a deep copy of a string
 * This function has been implemented for you.
 */
char * deepCopy(const char *s);

/**
 * Utility function that splits a string into an array
 * of strings along the provided (single character) delimiter.  The last
 * parameter is used to inform the calling function of
 * how many tokens it found and thus the size of the
 * returned string array.
 *
 */
char ** split(const char *str, char delimiter, int *n);

/**
 * Removes any trailing whitespace characters from the
 * end of the given string
 */
void chomp(char *str);

/**
 * Utility function that frees an array of strings
 * that has n strings in it.
 */
void freeStringArray(char **stringArray, int n);

//This function finds the number of lines in the file
int getnumLines(const char *fileName);

//This function initializes an existing pokemon
void initPokemon(Pokemon* p, int pokeID, const char* name, const char* type);

//This function creates a new pokemon
Pokemon* createPokemon(int pokeID, const char* name, const char* type);

//This function creates an array of structures of pokemon
Pokemon* pokemonArray(const char *filePath);

//This function initializes an existing pokemon type
void initPokemonType(pokemonType* p, const char* attack, const char* defense, double multiplier);

//This function creates a new pokemon type
pokemonType* createPokemonType(const char* attack, const char* defense, double multiplier);
