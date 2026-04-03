#pragma once
#include "..\Savings_challenge_16\Savings_challenge_16.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Trust_challenge_16 :public Savings_challenge_16 {
private:
	static constexpr const char* def_name = "Trusted def name";
	static constexpr double def_balance = 0.0;
public:
	Trust_challenge_16(string name = def_name, double balance = def_balance);

	virtual bool deposit(double amount) override;
	virtual bool withdraw(double amount) override;

	virtual void print(std::ostream& os) const override;

	~Trust_challenge_16();
};
