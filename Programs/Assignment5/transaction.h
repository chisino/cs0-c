/**
* Author: Artiom Dolghi
* Date Due: December 7, 2018
*
* This file includes the prototypes and documentation of functions for assignment 5
*/

//This enumerated type defines each type of transaction
typedef enum {
  PAYMENT,
  TRANSFER,
  WITHDRAWAL,
  DEBIT,
  DEPOSIT,
} transactionType;

//This structure defines all parts of the transaction
typedef struct {
  char* UUID;
  transactionType type;
  double amountTransaction;
  char* customerAccountNumber;
  double customerAccountBalanceBefore;
  double customerAccountBalanceAfter;
  char* transferAccountNumber;
} Transaction;

//This function finds the number of lines in a file
int findNumLines(const char *filePath);

//This function takes tokenizes the file
Transaction * tokenize(const char *filePath);

//This function initializes a transaction
void initTransaction(Transaction* transaction,
				             char* UUID,
				             transactionType type,
                     double amountTransaction,
                     char* customerAccountNumber,
                     double customerAccountBalanceBefore,
		                 double customerAccountBalanceAfter,
				             char* transferAccountNumber);

//This function creates a transaction
Transaction* createTransaction(char* UUID,
                     				   transactionType type,
                               double amountTransaction,
                               char* customerAccountNumber,
                               double customerAccountBalanceBefore,
                     					 double customerAccountBalanceAfter,
                     					 char* transferAccountNumber);

//This function is a general comparator for doubles
int cmpDouble(const void *a, const void *b);

//This function is a comparator for the customerAccountNumber,
//transferAccountNumber, and amountTransaction
int cmpByAccountTransferAmount(const void* a, const void* b);
