#include "AccountDB.h"
#include <iomanip>

AccountDB::AccountDB() {

}

void AccountDB::AddAccount(Account acc) {
	accounts[acc.GetName()] = acc;
}

void AccountDB::DisplayAccounts() {
		for (auto& pair : accounts) {
			// Check if the account name can fit in the box.
			if (FitInTheBox(pair.first, 15)) {
				cout << pair.first << " | ";
			}
			else
			{
				string shortenName = pair.first;
				shortenName.erase(15, shortenName.length() - 15);
				//shortenName.erase(12, shortenName.length() - 12);
				cout << shortenName << "... | ";
			}
			cout << pair.second.GetType() << setw(13) << " | $";
			cout << fixed << setprecision(2) << pair.second.GetCurrency()  << " |" << endl;
		}
}

bool AccountDB::FitInTheBox(string name, int max) {
	int count = 0;

	for(char c : name)
	{
		count++;
	}

	if (count <= max) {
		return true;
	}
	return false;
}