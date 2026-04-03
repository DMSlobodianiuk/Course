#include "..\..\..\..\..\..\..\..\Course\Course\Sections\include\Sections\Section_16\Challenge\Trust_challenge_16\Trust_challenge_16.h"

Trust_challenge_16::Trust_challenge_16(string name, double balance)
	:Savings_challenge_16{ name,balance } {
	//cout << "Trust constructor" << endl;
}

bool Trust_challenge_16::deposit(double amount) {
	cout << "\nTrust deposit operation" << endl;
	cout << "balance before: " << balance << " amount: " << amount;
	balance += amount;
	cout << " balance after: " << balance << endl;
	return true;
}

bool Trust_challenge_16::withdraw(double amount) {
	if (balance - amount < 0) {
		cout << "You have not enough money to withdraw " << amount << endl;
		return false;
	}
	else {
		cout << "\nTrust withdraw" << endl;
		cout << "balance before: " << balance << " amount: " << amount;
		balance -= amount;
		cout << " balance after: " << balance << endl;
	}
}

void Trust_challenge_16::print(std::ostream& os) const {
	os << "[ Trust account's name: " << name << "; balance: " << balance << " ]";
}

Trust_challenge_16::~Trust_challenge_16() {
	cout << "Trust destructor" << endl;
}
