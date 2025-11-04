#pragma once
#include<map>
#include <string>
#include "Account.h"

using namespace std;

class AccountDB
{
public:
	AccountDB();
	void AddAccount(Account);
	void DisplayAccounts();
	bool FitInTheBox(string, int);
private:
	map<string, Account> accounts;
};

