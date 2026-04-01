#include "..\..\..\..\..\include\Sections\Section_15\Challenge\Acc\Acc.h"

std::ostream& operator<<(std::ostream& os, const Acc& acc) {
	os << "[ Acc's name: " << acc.name << "| Acc's balance: " << acc.balance <<" ]" << endl;
	return os;
}

Acc::Acc(double balance)
	:name{ "acc name" }, balance{ balance } {
}

Acc::Acc(string name, double balance)
	:name{ name }, balance{balance} {
}

bool Acc::deposit(double amount) {
	if (amount > 0) {
		balance += amount;
		cout << "Deposit: " << amount << " on " << name << endl;
	}
	else {
		cout << "You cannot deposit non positive amount: " << amount << endl;
		return false;
	}
	return true;
}

bool Acc::withdraw(double amount) {
	if (balance - amount < 0) {
		cout << "You cannot withdraw more than you have" << endl;
		return false;
	} else{
		balance -= amount;
		cout << "Withdraw: " << amount << " from " << name << endl;
		return true;
	}
}

Acc::~Acc() {
}
