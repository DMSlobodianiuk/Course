#include "..\..\..\..\..\include\Sections\Section_15\Challenge\Trust_Acc\Trust_Acc.h"

std::ostream& operator<<(std::ostream& os, const Trust_Acc& acc) {
	os << "[ Trust Acc's name: "<<acc.name<<" | Trust Acc's balance: "<<acc.balance <<" | int_rate: "<<acc.int_rate<< "]" << endl;
	return os;
}

Trust_Acc::Trust_Acc(string name, double balance, double int_rate)
	:Savings_Acc{ name,balance,int_rate }, withdraw_count{0} {
}

bool Trust_Acc::deposit(double amount) {
	if (amount >= bonus_threshold) {
		amount += bonus_amount;
	}
	return Savings_Acc::deposit(amount);
}

bool Trust_Acc::withdraw(double amount) {
	if (withdraw_count >= withdraw_limits) {
		cout << "You've reached withdrawal limit on your Trust_Acc equal to " << withdraw_limits << endl;
		return false;
	}
	else {
		if ((balance * max_withdraw_percent) < amount) {
			cout << "Your withdrawal is more than 20% of the account balance" << endl;
			return false;
		}
		else{
			withdraw_count++;
			return Savings_Acc::withdraw(amount);
		}
	}
}

Trust_Acc::~Trust_Acc() {};
