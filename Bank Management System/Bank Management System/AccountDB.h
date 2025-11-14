#pragma once
#include <map>
#include <string>
#include "Account.h"

using namespace std;

class AccountDB
{
public:
	void AddAccount(Account);
	void DisplayAccounts();
	void DisplayAccount(int);
	Account GetAccount(int);
	bool FitInTheBox(string, int);
	size_t GetLengthOfDB();
private:
	map<string, Account> accounts;
};
