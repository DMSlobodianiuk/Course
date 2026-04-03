#include "..\..\..\..\..\..\..\..\Course\Course\Sections\include\Sections\Section_16\Challenge\Checking_challenge_16\Checking_challenge_16.h"

Checking_challenge_16::Checking_challenge_16(string name, double balance)
	:Acc_challenge_16{name,balance} {
	//cout << "Checking constructor" << endl;
}

bool Checking_challenge_16::deposit(double amount){
	cout << "\nChecking deposit operation" << endl;
	cout << "balance before: " << balance << " amount: " << amount;
	balance += amount;
	cout << " balance after: " << balance << endl;
	return true;
}

bool Checking_challenge_16::withdraw(double amount) {
	if (balance - amount < 0) {
		cout << "You have not enough money to withdraw " << amount << endl;
		return false;
	}
	else {
		cout << "\nChecking withdraw" << endl;
		cout << "balance before: " << balance << " amount: " << amount;
		balance -= amount;
		cout << " balance after: " << balance << endl;
	}
}

void Checking_challenge_16::print(std::ostream& os) const {
	os << "[ Checking account's name: "<<name<<"; balance: "<<balance<<" ]";
}

Checking_challenge_16::~Checking_challenge_16() {
	cout << "Checking destructor" << endl;
}
