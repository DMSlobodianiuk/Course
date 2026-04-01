#pragma once
#include <iostream>
#include <string>
#include "..\Acc\Acc.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Checking_Acc :public Acc {
	friend std::ostream& operator<<(std::ostream& os, const Checking_Acc& c_acc);
private:
	static constexpr const char* def_name = "Unnamed Checking Acc";
	static constexpr double def_balance = 0.0;
	static constexpr const double fee = 1.50;
protected:
public:
	Checking_Acc(string name = def_name, double balance = def_balance);

	void deposit(double amount);

	~Checking_Acc();
};

