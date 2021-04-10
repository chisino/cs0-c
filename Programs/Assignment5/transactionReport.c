/**
* Author: Artiom Dolghi
* Date Due: December 7, 2018
*
* This program will use the functions from assignment 5 to create reports
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "transaction.h"

int main(int argc, char **argv) {

	FILE *f = fopen(argv[1], "r");

	int numLines = findNumLines(argv[1]);

	Transaction *transactions = tokenize(argv[1]);

	//Part 0: printing out totals report
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

	int i = 0;
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
	printf("Transfer\t\t%d\t$\t%.2f\n", transferCounter, transfAmountCount);
	printf("Withdraw\t\t%d\t$\t%.2f\n", withdrawCounter, withdrawAmountCount);
	printf("Debit\t\t%d\t$\t%.2f\n", debitCounter, debitAmountCount);
	printf("Deposit\t\t%d\t$\t%.2f\n", depositCounter, depositAmountCount);

	printf("=========================================\n");

	printf("Total\t\t%d\t$\t%.2f\n\n", countCounter, totalCounter);

	//Part 1: Balance Validation Report

	printf("=========================\n");
	printf("Balance Validation Report\n");
	printf("=========================\n");

	i = 0;
	int invalidCounter = 0;
	double tolerance = 0.0;
	for (i=0;i<numLines;i++) {

		if (transactions[i].type == PAYMENT)
	{
				tolerance = transactions[i].customerAccountBalanceBefore - transactions[i].customerAccountBalanceAfter;
				if ( fabs(tolerance - transactions[i].amountTransaction) > .001 ) {
				printf("Invalid Transaction, off by $%.2f\n", (transactions[i].amountTransaction) - (transactions[i].customerAccountBalanceBefore - transactions[i].customerAccountBalanceAfter));
				printf("	%s: %s -> %s\n", transactions[i].UUID, transactions[i].customerAccountNumber, transactions[i].transferAccountNumber);
				printf("	(Payment) $ %.2f ($%.2f -> $%.2f)\n", transactions[i].amountTransaction, transactions[i].customerAccountBalanceBefore, transactions[i].customerAccountBalanceAfter);
				invalidCounter++;
		}
	}
	else if (transactions[i].type == TRANSFER)
	{
			tolerance = transactions[i].customerAccountBalanceBefore - transactions[i].customerAccountBalanceAfter;
			if ( fabs(tolerance - transactions[i].amountTransaction) > .001 ) {
			printf("Invalid Transaction, off by $%.2f\n", (transactions[i].amountTransaction) - (transactions[i].customerAccountBalanceBefore - transactions[i].customerAccountBalanceAfter));
			printf("	%s: %s -> %s\n", transactions[i].UUID, transactions[i].customerAccountNumber, transactions[i].transferAccountNumber);
			printf("	(Transfer) $ %.2f ($%.2f -> $%.2f)\n", transactions[i].amountTransaction, transactions[i].customerAccountBalanceBefore, transactions[i].customerAccountBalanceAfter);
			invalidCounter++;
		}
	}
	else if (transactions[i].type == WITHDRAWAL)
	{
			tolerance = transactions[i].customerAccountBalanceBefore - transactions[i].customerAccountBalanceAfter;
			if ( fabs(tolerance - transactions[i].amountTransaction) > .001 ) {
			printf("Invalid Transaction, off by $%.2f\n", (transactions[i].amountTransaction) - (transactions[i].customerAccountBalanceBefore - transactions[i].customerAccountBalanceAfter));
			printf("	%s: %s -> %s\n", transactions[i].UUID, transactions[i].customerAccountNumber, transactions[i].transferAccountNumber);
			printf("	(Withdraw) $ %.2f ($%.2f -> $%.2f)\n", transactions[i].amountTransaction, transactions[i].customerAccountBalanceBefore, transactions[i].customerAccountBalanceAfter);
			invalidCounter++;
		}
	}
	else if (transactions[i].type == DEBIT)
	{
			tolerance = transactions[i].customerAccountBalanceBefore - transactions[i].customerAccountBalanceAfter;
			if ( fabs(tolerance - transactions[i].amountTransaction) > .001 ) {
			printf("Invalid Transaction, off by $%.2f\n", (transactions[i].amountTransaction) - (transactions[i].customerAccountBalanceBefore - transactions[i].customerAccountBalanceAfter));
			printf("	%s: %s -> %s\n", transactions[i].UUID, transactions[i].customerAccountNumber, transactions[i].transferAccountNumber);
			printf("	(Debit) $ %.2f ($%.2f -> $%.2f)\n", transactions[i].amountTransaction, transactions[i].customerAccountBalanceBefore, transactions[i].customerAccountBalanceAfter);
			invalidCounter++;
		}
	}
		else if (transactions[i].type == DEPOSIT)
		{
			tolerance = transactions[i].customerAccountBalanceAfter - transactions[i].customerAccountBalanceBefore;
			if ( fabs(tolerance - transactions[i].amountTransaction) > .001 ) {
			printf("Invalid Transaction, off by $%.2f\n", (transactions[i].customerAccountBalanceBefore + transactions[i].amountTransaction) - transactions[i].customerAccountBalanceAfter);
			printf("	%s: %s -> %s\n", transactions[i].UUID, transactions[i].customerAccountNumber, transactions[i].transferAccountNumber);
			printf("	(Deposit) $ %.2f ($%.2f -> $%.2f)\n", transactions[i].amountTransaction, transactions[i].customerAccountBalanceBefore, transactions[i].customerAccountBalanceAfter);
			invalidCounter++;
			}
		}
	}
	printf("Number of invalid balances found: %d\n\n", invalidCounter);


	//Part 2: Deposit Limit Report

	printf("====================\n");
	printf("Deposit Limit Report\n");
	printf("====================\n");

	i = 0;
	int exceeding10Counter = 0;
	int approachingCounter = 0;
	for (i=0;i<numLines;i++) {
		if (transactions[i].type == DEPOSIT) {
			if (transactions[i].amountTransaction > 10000.0) {
			exceeding10Counter++;
		}
			else if (transactions[i].amountTransaction > 9900.0 || transactions[i].amountTransaction <= 9999.99) {
			approachingCounter++;
			}
		}
	}
	printf("Deposits exceeding 10k: %d\n", exceeding10Counter);
	printf("Deposits approaching 10k: %d\n\n", approachingCounter);


	//Part 3: Repeated Transaction Report

	printf("===========================\n");
	printf("Repeated Transaction Report\n");
	printf("===========================\n");
	printf("Repeated Transactions:\n");

	//sorting the transactions by account num, transfer account num, and amount
	qsort(transactions,numLines,sizeof(Transaction),cmpByAccountTransferAmount);

	i = 0;
	int repeatCounter = 0;
	for (i=0;i<numLines - 1;i++) {
		while ( fabs(transactions[i].amountTransaction - transactions[i+1].amountTransaction) < .001 ) {

			if (transactions[i].type == PAYMENT) {
			printf("	%s: %s -> %s\n", transactions[i].UUID, transactions[i].customerAccountNumber, transactions[i].transferAccountNumber);
			printf("	(Payment) $ %.2f ($%.2f -> $%.2f)\n", transactions[i].amountTransaction, transactions[i].customerAccountBalanceBefore, transactions[i].customerAccountBalanceAfter);

			//printing i+1
			printf("	%s: %s -> %s\n", transactions[i+1].UUID, transactions[i+1].customerAccountNumber, transactions[i+1].transferAccountNumber);
			printf("	(Payment) $ %.2f ($%.2f -> $%.2f)\n", transactions[i+1].amountTransaction, transactions[i+1].customerAccountBalanceBefore, transactions[i+1].customerAccountBalanceAfter);
			repeatCounter+= 2;
		}
			else if (transactions[i].type == TRANSFER) {
			printf("	%s: %s -> %s\n", transactions[i].UUID, transactions[i].customerAccountNumber, transactions[i].transferAccountNumber);
			printf("	(Transfer) $ %.2f ($%.2f -> $%.2f)\n", transactions[i].amountTransaction, transactions[i].customerAccountBalanceBefore, transactions[i].customerAccountBalanceAfter);

			//printing i+1
			printf("	%s: %s -> %s\n", transactions[i+1].UUID, transactions[i+1].customerAccountNumber, transactions[i+1].transferAccountNumber);
			printf("	(Transfer) $ %.2f ($%.2f -> $%.2f)\n", transactions[i+1].amountTransaction, transactions[i+1].customerAccountBalanceBefore, transactions[i+1].customerAccountBalanceAfter);
			repeatCounter+= 2;
		}
			else if (transactions[i].type == WITHDRAWAL) {
			printf("	%s: %s -> %s\n", transactions[i].UUID, transactions[i].customerAccountNumber, transactions[i].transferAccountNumber);
			printf("	(Withdraw) $ %.2f ($%.2f -> $%.2f)\n", transactions[i].amountTransaction, transactions[i].customerAccountBalanceBefore, transactions[i].customerAccountBalanceAfter);

			//printing i+1
			printf("	%s: %s -> %s\n", transactions[i+1].UUID, transactions[i+1].customerAccountNumber, transactions[i+1].transferAccountNumber);
			printf("	(Withdraw) $ %.2f ($%.2f -> $%.2f)\n", transactions[i+1].amountTransaction, transactions[i+1].customerAccountBalanceBefore, transactions[i+1].customerAccountBalanceAfter);
			repeatCounter+= 2;
		}
			else if (transactions[i].type == DEBIT) {
			printf("	%s: %s -> %s\n", transactions[i].UUID, transactions[i].customerAccountNumber, transactions[i].transferAccountNumber);
			printf("	(Debit) $ %.2f ($%.2f -> $%.2f)\n", transactions[i].amountTransaction, transactions[i].customerAccountBalanceBefore, transactions[i].customerAccountBalanceAfter);

			//printing i+1
			printf("	%s: %s -> %s\n", transactions[i+1].UUID, transactions[i+1].customerAccountNumber, transactions[i+1].transferAccountNumber);
			printf("	(Debit) $ %.2f ($%.2f -> $%.2f)\n", transactions[i+1].amountTransaction, transactions[i+1].customerAccountBalanceBefore, transactions[i+1].customerAccountBalanceAfter);
			repeatCounter+= 2;
		}
			else if (transactions[i].type == DEPOSIT) {
			printf("	%s: %s -> %s\n", transactions[i].UUID, transactions[i].customerAccountNumber, transactions[i].transferAccountNumber);
			printf("	(Deposit) $ %.2f ($%.2f -> $%.2f)\n", transactions[i].amountTransaction, transactions[i].customerAccountBalanceBefore, transactions[i].customerAccountBalanceAfter);

			//printing i+1
			printf("	%s: %s -> %s\n", transactions[i+1].UUID, transactions[i+1].customerAccountNumber, transactions[i+1].transferAccountNumber);
			printf("	(Deposit) $ %.2f ($%.2f -> $%.2f)\n", transactions[i+1].amountTransaction, transactions[i+1].customerAccountBalanceBefore, transactions[i+1].customerAccountBalanceAfter);
			repeatCounter+= 2;
		}
		i++;
	}
}
	printf("Total repeated transactions flagged: %d\n", repeatCounter);



	//freeing the transactions at the end of the program
	i = 0;
	for (i=0;i<numLines;i++) {
		free(transactions[i].UUID);
		free(transactions[i].customerAccountNumber);
		free(transactions[i].transferAccountNumber);
	}
	free(transactions);

	fclose(f);

  return 0;
}
