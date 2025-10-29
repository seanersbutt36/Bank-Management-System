#include "Account.h"

Account::Account(AccountTypes _type, float _amount) {
	type = _type;
	amount = _amount;
}

Account::~Account() {

}

AccountTypes Account::GetType() {
	return type;
}

void Account::SetType(AccountTypes value) {
	type = value;
}

float Account::GetAmount() {
	return amount;
}

void Account::SetAmount(float value) {
	amount += value;
}