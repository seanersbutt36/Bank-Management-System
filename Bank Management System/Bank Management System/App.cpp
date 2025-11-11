#include "App.h"
#include "Account.h"

App::App() {
	int _inputInt = 0;
	index = 0;

	while (_inputInt != 5) {
		cout << "1.  Create an account" << endl
			<< "2.  Read an account" << endl
			<< "3.  Update an account" << endl
			<< "4.  Delete an account" << endl
			<< "5.  Quit" << endl;
		cout << "Input Here: ";
		cin >> _inputInt;
		cout << endl;
		InputSystem(_inputInt);
		cout << endl;
		cout << "=======================" << endl << endl;
	}
}

void App::InputSystem(int _input) {
	switch (_input) {
	case 1:
		CreateAccount();
		break;
	case 2:
		ReadAccount();
		break;
	case 3:
		UpdateAccount();
		break;
	case 4:
		DeleteAccount();
		break;
	case 5:
		cout << "Goodbye" << endl;
		break;
	default:
		cout << "Please choose another option." << endl;
		break;
	}
}

void App::CreateAccount() {
	bool nextStep = false;
	
	cout << endl;
	cout << "What type of account are you creating?" << endl;
	ModifyType();
	cout << "Enter a name for the account:" << endl;
	ModifyName();
	cout << "Enter an amount you'd like to deposit:" << endl;
	ModifyCurrency();

	Account acc(selectingTypes[index], newName, newCurrency);
	accDB.AddAccount(acc);
}

void App::ReadAccount() {
	cout << endl;
	accDB.DisplayAccounts();
}

void App::UpdateAccount() {

	cout << "Updating an account..." << endl;
}

void App::DeleteAccount() {
	cout << "Deleting an account..." << endl;
}

void App::ModifyType() {
	int _inputInt = 0;
	bool selected = false; // Determine if the user has selected one of the options.

	// Dipslay the user's options.
	cout << "1.  Checking" << endl
		 << "2.  Saving" << endl;

	// SUGGESTION: Add an opt out option.
	// Keep looping until the users input one of the option.
	while (selected == false) {
		cout << "Input Here: ";
		cin >> _inputInt;
		if (_inputInt == 1) {
			index = 0;	// Selected checking account
			selected = true;
		}
		else if (_inputInt == 2) {
			index = 1;	// Selected saving account
			selected = true;
		}
		else {
			cout << "Please pick one of the options." << endl;
		}
	}
}

void App::ModifyName() {
	// Clear the buffer.
	cin.ignore();
	cout << "Input Here: ";
	getline(cin, newName);
}

void App::ModifyCurrency() {
	cout << "Input Here: $";
	cin >> newCurrency;
}