#pragma once
#include <iostream>
#include <string>
#include "..\Savings_Acc\Savings_Acc.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Trust_Acc : public Savings_Acc {
	friend std::ostream& operator<<(std::ostream& os, const Trust_Acc& acc);
private:
	static constexpr const char* def_name = "Unnamed Trust Acc";
	static constexpr double def_balance = 0.0;
	static constexpr double def_int_rate = 0.0;
	static constexpr int withdraw_limits = 3;
	static constexpr double bonus_amount = 50.0;
	static constexpr double bonus_threshold = 5000.0;
	static constexpr double max_withdraw_percent = 0.2;

protected:
	int withdraw_count = 0;
public:
	Trust_Acc(string name = def_name, double balance = def_balance, double int_rate = def_int_rate);

	bool deposit(double amount);
	bool withdraw(double amount);

	~Trust_Acc();
};
