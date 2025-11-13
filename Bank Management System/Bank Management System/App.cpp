#include <iomanip>
#include "App.h"
#include "Account.h"

App::App() {
	newCurrency = 0;
	int _inputInt = 0;
	index = 0;

	while (_inputInt != 5) {
		cout << "1.  Create an account" << endl
			<< "2.  Read an account" << endl
			<< "3.  Update an account" << endl
			<< "4.  Delete an account" << endl
			<< "5.  Quit" << endl;
		cout << "Input Here: ";

		// Check if the input is an integer.
		if (cin >> _inputInt) {
			cout << endl;
			InputSystem(_inputInt);
		}
		else {
			cout << "Please select with the integer assigned." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << endl;
		cout << "=======================" << endl << endl;
	}
}

App::~App() {

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
	for (int i = 0; i < accDB.GetLengthOfDB(); i++) {
		cout << left << setw(2) << i << ") ";
		accDB.DisplayAccount(i);
	}
}

void App::DeleteAccount() {
	cout << "Deleting an account..." << endl;
}

void App::ModifyType() {
	int _inputInt = 0;
	bool selected = false; // Determine to stop the while loop

	// Dipslay the user's options.
	cout << "1.  Checking" << endl
		 << "2.  Saving" << endl;

	// SUGGESTION: Add an opt out option.
	// Keep looping until the users input one of the option.
	while (selected == false) {
		cout << "Input Here: ";
		//cin >> _inputInt;

		// Check if the input is an integer.
		if (cin >> _inputInt) {
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
		else {
			cout << "Please select with the integer assigned." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
	bool selected = false; // Determine to stop the while loop

	while (selected == false) {
		cout << "Input Here: $";
		// Check if the input is an float.
		if (cin >> newCurrency) {
			// Check if the input is greater than or equal to 0.
			if (newCurrency >= 0) {
				selected = true;
			}
			else {
				newCurrency = 0;
			}
		}
		else {
			cout << "Please input a number." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}