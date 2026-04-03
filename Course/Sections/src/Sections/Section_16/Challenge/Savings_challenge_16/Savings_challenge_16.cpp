#include "..\..\..\..\..\..\Sections\include\Sections\Section_16\Challenge\Savings_challenge_16\Savings_challenge_16.h"

Savings_challenge_16::Savings_challenge_16(string name, double balance)
	:Acc_challenge_16{name,balance} {
	//cout << "Savings constructor" << endl;
}

bool Savings_challenge_16::deposit(double amount) {
	cout << "\nSavings deposit operation" << endl;
	cout << "balance before: " << balance << " amount: " << amount;
	balance += amount;
	cout << " balance after: " << balance << endl;
	return true;
}

bool Savings_challenge_16::withdraw(double amount) {
	if (balance - amount < 0) {
		cout << "You have not enough money to withdraw " << amount << endl;
		return false;
	}
	else {
		cout << "\nSavings withdraw" << endl;
		cout << "balance before: " << balance << " amount: " << amount;
		balance -= amount;
		cout << " balance after: " << balance << endl;
	}
}

void Savings_challenge_16::print(std::ostream& os) const {
	os << "[ Savings account's name: " << name << "; balance: " << balance << " ]";
}

Savings_challenge_16::~Savings_challenge_16() {
	cout << "Savings destructor" << endl;
}

