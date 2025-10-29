#pragma once

enum AccountTypes {
	Checking,
	Saving
};

class Account
{
public:
	Account(AccountTypes, float);
	~Account();
	AccountTypes GetType();
	void SetType(AccountTypes);
	float GetAmount();
	void SetAmount(float);
private:
	AccountTypes type;
	float amount;
};

