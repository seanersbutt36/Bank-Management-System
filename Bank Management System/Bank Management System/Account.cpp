#include "Account.h"

Account::Account() {
	type = Checking;
	name = "Default";
	currency = 0.0f;
}

Account::Account(string _type, string _name, float _currency) {
	if (_type == "Checking") {
		type = Checking;
	}
	else if (_type == "Saving") {
		type = Saving;
	}
	else {
		cout << "Error: Account undefined! Defaulted to checking!" << endl;
		type = Checking;
	}
	name = _name;
	currency = _currency;
}

Account::~Account() {

}

string Account::GetType() {
	if (type == Checking)
		return "Checking";
	else if (type == Saving)
		return "Saving";
	
	return "Error";
}

void Account::SetType(AccountTypes value) {
	type = value;
}

std::string Account::GetName() {
	return name;
}

void Account::SetName(string value) {
	name = value;
}

float Account::GetCurrency() {
	return currency;
}

void Account::SetCurrency(float value) {
	currency += value;
}