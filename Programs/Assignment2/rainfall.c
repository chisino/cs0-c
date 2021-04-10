/**
* Author: Artiom Dolghi
* Date Due: September 28, 2018
*
* This program will solve the "Rainfall Problem"
*/
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char **argv) {

int rainPerDay = 0;
double averageRain = 0;
double counter = 0;
double totalRain = 0;
double finalRain = 0;


int i = 0;
while (i <= 99999) {
  printf("Enter the amount of rainfall on the particular day: \n");
  scanf("%d", &rainPerDay);

  if (counter == 0 && rainPerDay == 99999 ) {
    printf("No Input Entered\n");
    return 0;
  }

  if (rainPerDay < 0) {
    rainPerDay = 0;
    counter = counter - 1;
  }

  counter++;
  i++;

  totalRain = totalRain + rainPerDay;
  averageRain = totalRain / (counter - 1);

  if (rainPerDay == 99999) {
    finalRain = averageRain - (99999 / (counter - 1));
    printf("Average rainfall: %.2f\n", finalRain);
    return 0;
  }

}



return 0;

}
