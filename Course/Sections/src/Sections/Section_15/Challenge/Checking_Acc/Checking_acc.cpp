#include "..\..\..\..\..\include\Sections\Section_15\Challenge\Checking_Acc\Checking_Acc.h"

std::ostream& operator<<(std::ostream& os, const Checking_Acc& acc) {
	os<<"[Checking Acc's name:"<<acc.name<<"| Checking Acc's balance: "<<acc.balance <<"| with fee: "<<acc.fee << " ]" << endl;
	return os;
}

Checking_Acc::Checking_Acc(string name,double balance)
	:Acc{name,balance} {
}

void Checking_Acc::deposit(double amount) {
	amount += fee;
	Acc::withdraw(amount);
}

Checking_Acc::~Checking_Acc() {}

