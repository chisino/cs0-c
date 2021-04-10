/**
* Author: Artiom Dolghi, Benoit Bikeli
* Date Due: November 16, 2018
*
* This file is composed of the function definitions for hack 13
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "airport.h"

void initAirport(Airport* airport,
                 const char* gpsId,
                 const char* type,
                 const char* name,
                 double latitude,
                 double longitude,
                 int elevationFeet,
                 const char* city,
                 const char* countryAbbrv) {

  //setting the fields of the structure
  airport->gpsId = (char *)malloc(sizeof(char) * (strlen(gpsId) + 1));
  strcpy(airport->gpsId, gpsId);

  airport->type = (char *)malloc(sizeof(char) * (strlen(type) + 1));
  strcpy(airport->type, type);

  airport->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
  strcpy(airport->name, name);

  airport->latitude = latitude;
  airport->longitude = longitude;
  airport->elevationFeet = elevationFeet;

  airport->city = (char *)malloc(sizeof(char) * (strlen(city) + 1));
  strcpy(airport->city, city);

  airport->countryAbbrv = (char *)malloc(sizeof(char) * (strlen(countryAbbrv) + 1));
  strcpy(airport->countryAbbrv, countryAbbrv);
}

Airport* createAirport(const char* gpsId,
                       const char* type,
                       const char* name,
                       double latitude,
                       double longitude,
                       int elevationFeet,
                       const char* city,
                       const char* countryAbbrv) {

  //dynamically allocating the new structure
  Airport *airport = (Airport *)malloc(sizeof(Airport) + 1);

  //calling initAirport function so there is less repeated code
  initAirport(airport, gpsId, type, name, latitude, longitude,
                  elevationFeet, city, countryAbbrv);

  return airport;
}

double getAirDistance(const Airport* origin, const Airport* destination) {

  //setting the variables up
  double latA = origin->latitude;
  double longA = origin->longitude;

  double latB = destination->latitude;
  double longB = destination->longitude;

  //converting from degrees to radians b/c equation assumes radians
  latA = (latA / 180) * M_PI;
  longA = (longA / 180) * M_PI;
  latB = (latB / 180) * M_PI;
  longB = (longB / 180) * M_PI;

  //calculating the distance
  double equationAnswer = acos(sin(latA) * sin(latB) + cos(latA) * cos(latB) * cos(longB - longA)) * 6371;

  return equationAnswer;
}

char* airportToString(const Airport* a) {

  //figuring out how much space is needed
  int n = strlen(a->gpsId) + strlen(a->type) + strlen(a->name) + strlen(a->city)
          + strlen(a->countryAbbrv) + 1000;

  //allocating memory for the string
  char *str = (char *)malloc(sizeof(char) * n + 1);

  //putting the values into the string
  sprintf(str, "%s\n%s\n%s\n(%.2f, %.2f)\n%d ft\n(%s, %s)\n",
         a->gpsId, a->type, a->name, a->latitude, a->longitude, a->elevationFeet, a->city, a->countryAbbrv);

  str[n] = '\0';

  return str;
}

double getEstimatedTravelTime(const Airport* stops,
                              int size,
                              double aveKmsPerHour,
                              double aveLayoverTimeHrs) {

  int i = 0;

  double distance = 0.0;

  //loop to calculate distance between all stops
  for (i=0;i<size-1;i++) {
    distance += getAirDistance(&stops[i], &stops[i+1]);
  }

  //calculating time
  double time = distance / aveKmsPerHour;

  time = time + (aveLayoverTimeHrs * (size-2));

  return time;
}

int cmpInt(const void *a, const void *b) {
  const int *x = (const int *)a;
  const int *y = (const int *)b;
  if(*x < *y) {
    return -1;
  } else if(*x > *y) {
    return 1;
  } else {
    return 0;
  }
  return 0;
}

int cmpDouble(const void *a, const void *b) {
  const double *x = (const double *)a;
  const double *y = (const double *)b;
  if(*x < *y) {
    return -1;
  } else if(*x > *y) {
    return 1;
  } else {
    return 0;
  }
  return 0;
}

int cmpByGPSId(const void* a, const void* b) {
  const Airport *x = (const Airport *) a;
  const Airport *y = (const Airport *) b;

  return cmpInt( &(x->gpsId), &(y->gpsId) );
}

int cmpByType(const void* a, const void* b) {
  const Airport *x = (const Airport *) a;
  const Airport *y = (const Airport *) b;

  return strcmp(x->type, y->type);
}

int cmpByName(const void* a, const void* b) {
  const Airport *x = (const Airport *) a;
  const Airport *y = (const Airport *) b;

  return strcmp(x->name, y->name);
}

int cmpByNameDesc(const void* a, const void* b) {
  const Airport *x = (const Airport *) a;
  const Airport *y = (const Airport *) b;

  return strcmp(y->name, x->name);
}

int cmpByCountryCity(const void* a, const void* b) {
  const Airport *x = (const Airport *) a;
  const Airport *y = (const Airport *) b;

  int result = strcmp(x->countryAbbrv, y->countryAbbrv);
    if (result != 0) {
      return result;
    }
    else {
      return strcmp(x->city, y->city);
    }
}

int cmpByLatitude(const void* a, const void* b) {
  const Airport *x = (const Airport *) a;
  const Airport *y = (const Airport *) b;

  return cmpDouble( &(x->latitude), &(y->latitude) );
}

int cmpByLongitude(const void* a, const void* b) {
  const Airport *x = (const Airport *) a;
  const Airport *y = (const Airport *) b;

  return cmpDouble(&(x->longitude), &(y->longitude));
}

int cmpByLincolnDistance(const void* a, const void* b) {
  const Airport *x = (const Airport *) a;
  const Airport *y = (const Airport *) b;

  Airport *Lincoln = createAirport("0R2", "airport", "Lincoln Airport", 40.846176, -96.75471, 100, "Lincoln", "US");

  double distanceA = getAirDistance(x, Lincoln);

  double distanceB = getAirDistance(y, Lincoln);

  if (distanceA < distanceB) {
    return -1;
  }

  else if (distanceA > distanceB) {
    return 1;
  }

  else {
    return 0;
  }
}

void generateReports(Airport *airports, int n) {

  printf("Airports (Original):\n\n");

  int i = 0;

  for(i=0; i<n; i++) {
    printf("%s\n", airportToString(&airports[i]));
  }

  ////////////////////////////////////////////////

  printf("Airports By GPS ID:\n\n");

  qsort(airports, n, sizeof(Airport), cmpByGPSId);

  i = 0;

  for(i=0; i<n; i++) {
    printf("%s\n", airportToString(&airports[i]));
  }

  ////////////////////////////////////////////////

  printf("Airports By Type:\n\n");

  qsort(airports, n, sizeof(Airport), cmpByType);

  i = 0;

  for(i=0; i<n; i++) {
    printf("%s\n", airportToString(&airports[i]));
  }

  ////////////////////////////////////////////////

  printf("Airports By Name:\n\n");

  qsort(airports, n, sizeof(Airport), cmpByName);

  i = 0;

  for(i=0; i<n; i++) {
    printf("%s\n", airportToString(&airports[i]));
  }

  ////////////////////////////////////////////////

  printf("Airports By Name - Descending:\n\n");

  qsort(airports, n, sizeof(Airport), cmpByNameDesc);

  i = 0;

  for(i=0; i<n; i++) {
    printf("%s\n", airportToString(&airports[i]));
  }

  ////////////////////////////////////////////////

  printf("Airports By Country/City:\n\n");

  qsort(airports, n, sizeof(Airport), cmpByCountryCity);

  i = 0;

  for(i=0; i<n; i++) {
    printf("%s\n", airportToString(&airports[i]));
  }

  ////////////////////////////////////////////////

  printf("Airports By Latitude:\n\n");

  qsort(airports, n, sizeof(Airport), cmpByLatitude);

  i = 0;

  for(i=0; i<n; i++) {
    printf("%s\n", airportToString(&airports[i]));
  }

  ////////////////////////////////////////////////

  printf("Airports By Longitude:\n\n");

  qsort(airports, n, sizeof(Airport), cmpByLongitude);

  i = 0;

  for(i=0; i<n; i++) {
    printf("%s\n", airportToString(&airports[i]));
  }

  ////////////////////////////////////////////////

  printf("Airports By Distance From Lincoln:\n\n");

  qsort(airports, n, sizeof(Airport), cmpByLincolnDistance);

  i = 0;

  for(i=0; i<n; i++) {
    printf("%s\n", airportToString(&airports[i]));
  }

  ////////////////////////////////////////////////

  printf("Closest Airport to Lincoln:\n\n");

  qsort(airports, n, sizeof(Airport), cmpByLincolnDistance);

  printf("%s\n", airportToString(&airports[0]));

  ////////////////////////////////////////////////

  printf("Furthest Airport from Lincoln:\n\n");

  qsort(airports, n, sizeof(Airport), cmpByLincolnDistance);

  printf("%s\n", airportToString(&airports[n-1]));

  ////////////////////////////////////////////////

  printf("Geographic West-East Median:\n\n");

  qsort(airports, n, sizeof(Airport), cmpByLongitude);

  if(n % 2 == 0) {
    printf("%s\n", airportToString(&airports[(n/2) - 1]));
  }

  else {
  printf("%s\n", airportToString(&airports[n/2]));
  }

  ////////////////////////////////////////////////

  printf("New York Airport:\n\n");

  qsort(airports, n, sizeof(Airport), cmpByCountryCity);

  i = 0;

  int trueCheck = 0;

  for (i=0;i<n;i++) {
    if ((strstr(airports[i].city, "New York") != NULL)) {
      printf("%s\n", airportToString(&airports[i]));
      trueCheck = 1;
      break;
    }
  }
  if (trueCheck != 1) {
    printf("No airport found in New York (City)\n\n");
  }

  ////////////////////////////////////////////////

  printf("Canadian Airport:\n\n");

  qsort(airports, n, sizeof(Airport), cmpByCountryCity);

  i = 0;

  trueCheck = 0;

  for (i=0;i<n;i++) {
    if ((strstr(airports[i].countryAbbrv, "CA") != NULL) && (strstr(airports[i].countryAbbrv, "US") == NULL)) {
      printf("%s\n", airportToString(&airports[i]));
      trueCheck = 1;
      break;
    }
  }

  if (trueCheck != 1) {
    printf("No Canadian airport found\n\n");
  }

  ////////////////////////////////////////////////

  printf("Large Airport:\n\n");

  qsort(airports, n, sizeof(Airport), cmpByType);

  i = 0;

  trueCheck = 0;

  for (i=0;i<n;i++) {
    if ((strcmp(airports[i].type, "large_airport") == 0)) {
      printf("%s\n", airportToString(&airports[i]));
      trueCheck = 1;
      break;
    }
  }

  if (trueCheck != 1) {
    printf("No large airport found\n");
  }

}
