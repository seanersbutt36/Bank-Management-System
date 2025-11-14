#include "AccountDB.h"
#include <iomanip>


void AccountDB::AddAccount(Account acc) {
	accounts[acc.GetName()] = acc;
}

void AccountDB::DisplayAccounts() {
		for (auto& pair : accounts) {
			// Check if the account name can fit in the box.
			if (FitInTheBox(pair.first, 15)) {
				cout << left << setw(18) << pair.first << " | ";
			}
			else
			{
				string shortenName = pair.first;
				shortenName.erase(15, shortenName.length() - 15);
				//shortenName.erase(12, shortenName.length() - 12);
				cout << shortenName << "... | ";
			}
			cout << left << setw(8) << pair.second.GetType() << " | $";
			cout << left << setw(13) << fixed << setprecision(2) << pair.second.GetCurrency() << " |" << endl;
		}
}

void AccountDB::DisplayAccount(int _index) {
	int counter = 0;

	for (auto& pair : accounts) {
		if (counter == _index) {
			// Check if the account name can fit in the box.
			if (FitInTheBox(pair.first, 15)) {
				cout << left << setw(18) << pair.first << " | ";
			}
			else
			{
				string shortenName = pair.first;
				shortenName.erase(15, shortenName.length() - 15);
				//shortenName.erase(12, shortenName.length() - 12);
				cout << shortenName << "... | ";
			}
			cout << left << setw(8) << pair.second.GetType() << " | $";
			cout << left << setw(13) << fixed << setprecision(2) << pair.second.GetCurrency() << " |" << endl;
			break;
		}
		else {
			counter++;
		}
	}
}

/*Account AccountDB::GetAccount(int _index) {
	int counter = 0;

	for (auto& pair : accounts) {
		if (counter == _index) {
			cout << "1.  " << pair.first << endl;
			cout << left << setw(8) << pair.second.GetType() << " | $";
			cout << left << setw(13) << fixed << setprecision(2) << pair.second.GetCurrency() << " |" << endl;
			break;
		}
		else {
			counter++;
		}
	}
}*/

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

size_t AccountDB::GetLengthOfDB() {
	return accounts.size();;
}