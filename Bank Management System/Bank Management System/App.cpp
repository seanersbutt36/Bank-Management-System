#include "App.h"
#include "Account.h"

App::App() {
	inputStr = "";
	inputFlt = 0.0f;
	index = 0;

	while (inputInt != 5) {
		cout << "1.  Create an account" << endl
			<< "2.  Read an account" << endl
			<< "3.  Update an account" << endl
			<< "4.  Delete an account" << endl
			<< "5.  Quit" << endl;
		cout << "Input Here: ";
		cin >> inputInt;
		cout << endl;
		InputSystem(inputInt);
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
	ModifyType();
	ModifyName();
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
	cout << "What type of account are you creating?" << endl
		<< "1.  Checking" << endl
		<< "2.  Saving" << endl;
	cout << "Input Here: ";
	cin >> inputInt;

	while (inputInt < 1 && inputInt > 2) {
		if (inputInt == 1) {
			index = 0;
		}
		else if (inputInt == 2) {
			index = 1;
		}
		else {
			cout << "Please pick one of the options." << endl;
		}
	}
}

void App::ModifyName() {
	cin.ignore();
	cout << "Enter a name for the account:" << endl;
	cout << "Input Here: ";
	getline(cin, inputStr);
	newName = inputStr;
}

void App::ModifyCurrency() {
	cout << "Enter an amount you'd like to deposit:" << endl;
	cout << "Input Here: ";
	cin >> inputFlt;
	newCurrency = inputFlt;
}