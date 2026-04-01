//#pragma once
#ifndef _STATEMENT_H_
#define _STATEMENT_H_
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Statement {
	friend std::ostream& operator<<(std::ostream& os, const Statement& statement);
protected:
	double balance;
	string name;

public:
	Statement();
	Statement(double balance);

	void deposit(double amount);
	void withdraw(double amount);

	void redefined_deposit(double amount) { balance += amount; }


	~Statement();
};
#endif
