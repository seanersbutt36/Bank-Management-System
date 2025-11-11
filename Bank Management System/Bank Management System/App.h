#pragma once
#include <iostream>
#include <iomanip>
#include "AccountDB.h"

using namespace std;

class App
{
public:
	App();
	void InputSystem(int);
	void CreateAccount();
	void ReadAccount();
	void UpdateAccount();
	void DeleteAccount();
	void ModifyType();
	void ModifyName();
	void ModifyCurrency();
private:
	AccountDB accDB;
	string newName;
	float newCurrency;
	string selectingTypes[2] = {
		"Checking",
		"Saving"
	};
	int index;
};

