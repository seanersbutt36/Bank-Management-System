#pragma once
#include<map>
#include "Account.h"

class AccountDB
{
public:
	void AddAccount();
private:
	std::map<std::string, Account> dictionary;
};

