/*Skills:
  File handling
  classes
  structs.

Features: 
  Create
  read
  update
  delete (CRUD) accounts; transaction history.

Why it’s good: Demonstrates data persistence and OOP.*/

/*
   1) Prompt the user to either create, read, 
      update, or delete accounts;
	  transaction history
  2a) Create will ask the user to put in some
      information and the program will generate
	  the user's banking information.
  2b) Read will prompt the selected account
      information.
  2c) Update will allow the user to update one
      of the accounts information
  2d) Delete will destroy the selected account.

  Ask whether the user has a bank account
*/

#include "App.h"

int main() {
    // Run the bank management program
    App();
	return 0;
}