#pragma once
#include<map>
#include <string>
#include "Account.h"

using namespace std;

class AccountDB
{
public:
	void AddAccount(Account);
	void DisplayAccounts();
	void DisplayAccount(int);
	bool FitInTheBox(string, int);
	int GetLengthOfDB();
private:
	map<string, Account> accounts;
	int length;
};

