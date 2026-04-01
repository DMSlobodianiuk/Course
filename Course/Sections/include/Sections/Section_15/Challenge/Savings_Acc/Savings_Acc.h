#pragma once
#include <iostream>
#include <string>
#include "..\Acc\Acc.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Savings_Acc :public Acc {
	friend std::ostream& operator<<(std::ostream& os, const Savings_Acc& acc);
private:
	static constexpr const char* def_name = "Unnamed Savings Acc";
	static constexpr double def_balance = 0.0;
	static constexpr double def_int_rate = 0.0;
protected:
	double int_rate;
public:
	Savings_Acc(string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
	bool deposit(double amount);

	double get_int_rate() { return int_rate; }
	void set_int_rate(double n_int_rate) { int_rate = n_int_rate; }

	~Savings_Acc();
};

