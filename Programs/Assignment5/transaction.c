/**
* Author: Artiom Dolghi
* Date Due: December 7, 2018
*
* This file includes the function definitions for assignment 5
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "transaction.h"

int findNumLines(const char *filePath) {

  FILE *f = fopen(filePath, "r");

  char buffer[100];

  fgets(buffer, 100, f);

  int numLines = atoi(buffer);

  fclose(f);

  return numLines;
}

Transaction * tokenize(const char *filePath) {

  FILE *f = fopen(filePath, "r");

  char buffer[10000];

  int numLines = findNumLines(filePath);

  Transaction *transactions = (Transaction *)malloc(sizeof(Transaction) * numLines);

  transactionType typeResult;

  fgets(buffer, 10000, f);

  int i = 0;

  while (i < numLines) {

    fgets(buffer, 10000, f);
    char * uuidToken = strtok(buffer, ",");
    char * typeToken = strtok(NULL, ",");
    char * amountToken = strtok(NULL, ",");
    char * accNumToken = strtok(NULL, ",");
    char * balanceBeforeToken = strtok(NULL, ",");
    char * balanceAfterToken = strtok(NULL, ",");
    char * transferNumToken = strtok(NULL, ",");

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

    transactions[i] = *(createTransaction(uuidToken,
                                        typeResult,
                                        atof(amountToken),
                                        accNumToken,
                                        atof(balanceBeforeToken),
                                        atof(balanceAfterToken),
                                        transferNumToken));
    i++;
  }

  fclose(f);

  return transactions;
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

int cmpByAccountTransferAmount(const void* a, const void* b) {
  const Transaction *x = (const Transaction *) a;
  const Transaction *y = (const Transaction *) b;

  int result = strcmp(x->customerAccountNumber, y->customerAccountNumber);
  if (result == 0) {
    result = strcmp(x->transferAccountNumber, y->transferAccountNumber);
    if (result == 0) {
    return cmpDouble( &(x->amountTransaction), &(y->amountTransaction) );
  } else {
    return result;
  }
} else {
  return result;
  }
}
