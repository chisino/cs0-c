/**
* Author: Artiom Dolghi
* Date Due: November 30, 2018
*
* This file includes the prototypes and documentation of functions for hack 14
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

//This function turns the lines from the file into an array of strings
char **getFileLines(const char *filePath);

//This function takes a string out of the array and turns it into a
//Transaction structure
Transaction * stringToStruct(char *arr, int i);

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
