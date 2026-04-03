#pragma once
#include "..\Acc_challenge_16\Acc_challenge_16.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Savings_challenge_16 :public Acc_challenge_16 {
private:
	static constexpr const char* def_name = "Savings def name";
	static constexpr double def_balance = 0.0;
public:
	Savings_challenge_16(string name = def_name, double balance = def_balance);

	virtual bool deposit(double amount) override;
	virtual bool withdraw(double amount) override;

	virtual void print(std::ostream& os) const override;

	~Savings_challenge_16();
};
