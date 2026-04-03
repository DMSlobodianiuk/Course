#pragma once
#include "..\Printable_challenge_16\Printable_challenge_16.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Acc_challenge_16 : public Printable{
private:
	static constexpr const char* def_name = "Acc def name";
	static constexpr double def_balance = 0.0;
protected:
	string name;
	double balance;
public:
	Acc_challenge_16(string name = def_name,double balance = def_balance);

	virtual bool deposit(double amount) = 0;
	virtual bool withdraw(double amount) = 0;

	~Acc_challenge_16();
};
