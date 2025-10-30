#pragma once
#include <iostream>

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
	int inputInt;
	string inputStr;
	float inputFlt;
	string newName;
	float newCurrency;
	string selectingTypes[2] = {
		"Checking",
		"Saving"
	};
	int index;
};

