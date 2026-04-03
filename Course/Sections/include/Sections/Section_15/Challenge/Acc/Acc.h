#pragma once
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Acc {
	//friend std::ostream& operator<<(std::ostream &os, const Acc& acc);
private:
	static constexpr const char* def_name = "Unnamed Acc";
	static constexpr double def_balance = 0.0;
protected:
	string name;
	double balance;
public:

	Acc(double balance);
	Acc(string name = def_name, double balance = def_balance);

	void set_balance(double new_balance) { balance = new_balance; }
	double get_balance() { return balance; }

	void set_name(string new_name) { name = new_name; }
	string get_name() { return name; }

	bool deposit(double amount);
	bool withdraw(double amount);

	~Acc();
};
