/**
* Author: Artiom Dolghi
* Date Due: November 30, 2018
*
* This program will use the functions from hack 14 to create a report
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "transaction.h"

int main(int argc, char **argv) {

	FILE *f = fopen(argv[1], "r");

	int numLines = findNumLines(argv[1]);

	char **result = getFileLines(argv[1]);

	Transaction *transactions = malloc(sizeof(Transaction) * numLines);

	int i = 0;
	int j = 1;

	for (i=0;i<numLines;i++) {
		transactions[i] = *(stringToStruct(result[j], j));
		j++;
	}

	printf("Totals\n");
	printf("=========================================\n");

	printf("Type\t\tCount\t\tTotal\n");
	printf("=========================================\n");

	int paymentCounter = 0;
	int transferCounter = 0;
	int withdrawCounter = 0;
	int debitCounter = 0;
	int depositCounter = 0;

	double payAmountCount = 0.0;
	double transfAmountCount = 0.0;
	double withdrawAmountCount = 0.0;
	double debitAmountCount = 0.0;
	double depositAmountCount = 0.0;

	int countCounter = 0;
	double totalCounter = 0.0;

	i = 0;
	for (i=0;i<numLines;i++) {
		if (transactions[i].type == PAYMENT) {
			paymentCounter++;
			payAmountCount += transactions[i].amountTransaction;
		}
		else if (transactions[i].type == TRANSFER) {
			transferCounter++;
			transfAmountCount += transactions[i].amountTransaction;
		}
		else if (transactions[i].type == WITHDRAWAL) {
			withdrawCounter++;
			withdrawAmountCount += transactions[i].amountTransaction;
		}
		else if (transactions[i].type == DEBIT) {
			debitCounter++;
			debitAmountCount += transactions[i].amountTransaction;
		}
		else if (transactions[i].type == DEPOSIT) {
			depositCounter++;
			depositAmountCount += transactions[i].amountTransaction;
		}
		countCounter++;
		totalCounter += transactions[i].amountTransaction;
	}

	printf("Payment\t\t%d\t$\t%.2f\n", paymentCounter, payAmountCount);
	printf("Transfer\t%d\t$\t%.2f\n", transferCounter, transfAmountCount);
	printf("Withdraw\t%d\t$\t%.2f\n", withdrawCounter, withdrawAmountCount);
	printf("Debit\t\t%d\t$\t%.2f\n", debitCounter, debitAmountCount);
	printf("Deposit\t\t%d\t$\t%.2f\n", depositCounter, depositAmountCount);

	printf("=========================================\n");

	printf("Total\t\t%d\t$\t%.2f\n", countCounter, totalCounter);


	fclose(f);

  return 0;
}
