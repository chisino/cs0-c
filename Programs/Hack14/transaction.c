/**
* Author: Artiom Dolghi
* Date Due: November 30, 2018
*
* This file includes the function definitions for hack 14
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "transaction.h"

int findNumLines(const char *filePath) {

  FILE *f = fopen(filePath, "r");

  char buffer[100];

  char *s = fgets(buffer,100, f);

  int numLines = atoi(s);

  fclose(f);

  return numLines;
}

char **getFileLines(const char *filePath) {
	int numLines = findNumLines(filePath);

	FILE *f = fopen(filePath, "r");
	char **arr = (char**)malloc(sizeof(char*) * numLines);

  int i = 0;
	for(i=0;i<=numLines; i++){
		arr[i] = (char*)malloc(sizeof(char)*10000);
	}
	char buffer[10000];
	char *line = fgets(buffer, 10000, f);
	i=0;
		while (line != NULL) {
			int n = strlen(buffer);
			if (buffer[n-1] == '\n') {
				buffer[n-1] = '\0';
			}
			 strcpy(arr[i], buffer);
			line = fgets(buffer, 10000, f);
			i++;
		}

	fclose(f);
	return arr;
}

  Transaction * stringToStruct(char *arr, int i) {

  char * uuidToken = strtok(&arr[i], ",");
  char * typeToken = strtok(NULL, ",");
  char * amountToken = strtok(NULL, ",");
  char * accNumToken = strtok(NULL, ",");
  char * balanceBeforeToken = strtok(NULL, ",");
  char * balanceAfterToken = strtok(NULL, ",");
  char * transferNumToken = strtok(NULL, ",");

  transactionType typeResult;

  if (strcmp(typeToken, "PAYMENT") == 0) {
    typeResult = PAYMENT;
  }
  else if (strcmp(typeToken, "TRANSFER") == 0) {
    typeResult = TRANSFER;
  }
  else if (strcmp(typeToken, "WITHDRAWAL") == 0) {
    typeResult = WITHDRAWAL;
  }
  else if (strcmp(typeToken, "DEBIT") == 0) {
    typeResult = DEBIT;
  }
  else {
    typeResult = DEPOSIT;
  }

  Transaction *result = createTransaction(uuidToken,
                           typeResult,
                           atof(amountToken),
                           accNumToken,
                           atof(balanceBeforeToken),
                           atof(balanceAfterToken),
                           transferNumToken);

  return result;
}

void initTransaction(Transaction* transaction,
				             char* UUID,
				             transactionType type,
                     double amountTransaction,
                     char* customerAccountNumber,
                     double customerAccountBalanceBefore,
		                 double customerAccountBalanceAfter,
				             char* transferAccountNumber)
{
	//reallocating memory
	transaction->UUID = (char *)malloc(sizeof(char) * (strlen(UUID) + 1));
	strcpy(transaction->UUID, UUID);

	transaction->customerAccountNumber = (char *)malloc(sizeof(char) * (strlen(customerAccountNumber) + 1));
	strcpy(transaction->customerAccountNumber, customerAccountNumber);

	transaction->transferAccountNumber = (char *)malloc(sizeof(char) * (strlen(transferAccountNumber) + 1));
	strcpy(transaction->transferAccountNumber, transferAccountNumber);

  transaction->amountTransaction = amountTransaction;
	transaction->customerAccountBalanceBefore = customerAccountBalanceBefore;
	transaction->customerAccountBalanceAfter = customerAccountBalanceAfter;
	transaction->type = type;

	return;
}

Transaction* createTransaction(char* UUID,
				                       transactionType type,
                               double amountTransaction,
                               char* customerAccountNumber,
                               double customerAccountBalanceBefore,
					                     double customerAccountBalanceAfter,
					                     char* transferAccountNumber)
{
  //dynamically allocating the new structure
  Transaction *transaction = (Transaction *)malloc(sizeof(Transaction) + 1);


  //calling initTransaction function so there is less repeated code
  initTransaction(transaction,
                  UUID,
				          type,
			            amountTransaction,
		              customerAccountNumber,
                  customerAccountBalanceBefore,
                  customerAccountBalanceAfter,
	                transferAccountNumber);

  return transaction;
}
