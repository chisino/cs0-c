/**
* Author: Artiom Dolghi
* Date Due: August 31, 2018
*
* This program will tell customers of a phone company about their data usage:
* If they are over their average usage, under or equal to, or have already
* gone over their whole GB limit for the month
*/
#include<stdlib.h>
#include<stdio.h>


int main(int argc, char **argv) {


double gbInPlan = atof(argv[1]);
int currentDay = atol(argv[2]);
double totalGbUsed = atof(argv[3]);

int daysRemaining = (30 - currentDay);
double dailyUsage = (totalGbUsed / currentDay);
double noMoreThan = (gbInPlan - (currentDay * dailyUsage)) / daysRemaining;
double generalAverageUse = (gbInPlan / 30);
double exceedUse = ((dailyUsage * 30) - gbInPlan);
double useUpTo = ((gbInPlan) - (dailyUsage * currentDay)) / daysRemaining;


if ((dailyUsage * currentDay) > (generalAverageUse * 30)) {
  printf("%d days used, %d days remaining\nAverage daily use: %.6f GB/day\n\nYou have already met your limit for this month.\n", currentDay, daysRemaining, dailyUsage);
}

else if (dailyUsage > generalAverageUse) {
  printf("%d days used, %d days remaining\nAverage daily use: %.6f GB/day\n\nYou are EXCEEDING your average daily use (%.2f GB/day).\nContinuing this high usage, you'll exceed your data plan by %.6f GB.\n\nTo stay below your data plan, use no more than %.6f GB/day.\n", currentDay, daysRemaining, dailyUsage, generalAverageUse, exceedUse, noMoreThan);
}

else if (dailyUsage <= generalAverageUse) {
  printf("%d days used, %d days remaining\nAverage daily use: %.6f GB/day\n\nYou are at or below your average daily use (%.2f GB/day).\nYou can use up to %.6f GB/Day and stay below your data plan limit", currentDay, daysRemaining, dailyUsage, generalAverageUse, useUpTo);
}


return 0;

}
