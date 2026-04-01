#include "..\..\..\..\..\include\Sections\Section_15\Challenge\Savings_Acc\Savings_Acc.h"

std::ostream& operator<<(std::ostream& os, const Savings_Acc& acc) {
	os << "[ Savings Acc's name: " << acc.name << "| Savings Acc's balance: " << acc.balance << " ]" << endl;
	return os;
}

Savings_Acc::Savings_Acc(string name, double balance, double int_rate)
	:Acc{ name,balance }, int_rate{ int_rate } {
}

bool Savings_Acc::deposit(double amount) {
	amount += amount * (int_rate / 100);
	return Acc::deposit(amount);
}

Savings_Acc::~Savings_Acc(){}
