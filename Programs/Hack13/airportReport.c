/**
* Author: Artiom Dolghi, Benoit Bikeli
* Date Due: November 16, 2018
*
* This program will test the functions from hack 13
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "airport.h"

int main(int argc, char **argv) {

  Airport *airport1 = createAirport("124B", "helipad", "Alaska Airport", 50, 100, 20, "Alaska", "US-AK");

  Airport *airport2 = createAirport("56AB", "medium", "Logan", 25, 50, 75, "Boston", "US-MA");

  Airport *airport3 = createAirport("98UN", "big", "LAX", 10, 20, 30, "Los Angeles", "US-LA");

  Airport *airport4 = createAirport("3L6S", "large_airport", "JFK", 60, 17, 12, "New York", "US-NY");

  Airport *airport5 = createAirport("MP86", "small", "Toronto Airport", 5, 80, 27, "Toronto", "CA");


  Airport *airports = malloc(sizeof(Airport) * 5);

  airports[0] = *airport1;
  airports[1] = *airport2;
  airports[2] = *airport3;
  airports[3] = *airport4;
  airports[4] = *airport5;

  generateReports(airports, 5);

  return 0;
}
