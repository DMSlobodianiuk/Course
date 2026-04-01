//#pragma once
#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "..\Statement\Statement.h"
#include <iostream>

class Savings_Statement : public Statement
{
	friend std::ostream& operator<<(std::ostream& os, const Savings_Statement& savings_statement);
protected:
	double int_rate;
public:
	Savings_Statement();
	Savings_Statement(double balance, double int_rate);

	void deposit(double amount);
	void withdraw(double amount);

	void redefined_deposit(double amount);

	~Savings_Statement();
};
#endif 
