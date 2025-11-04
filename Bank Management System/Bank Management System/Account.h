#pragma once
#include <iostream>
#include <string>

using namespace std;

enum AccountTypes {
	Checking,
	Saving
};

class Account
{
public:
	Account();
	Account(string _type, string _name, float);
	~Account();
	string GetType();
	void SetType(AccountTypes);
	string GetName();
	void SetName(string);
	float GetCurrency();
	void SetCurrency(float);
private:
	AccountTypes type;
	string name;
	float currency;
};

