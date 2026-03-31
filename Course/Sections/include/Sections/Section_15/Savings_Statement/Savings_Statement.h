//#pragma once
#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "..\Statement\Statement.h"
#include <iostream>

class Savings_Statement : public Statement
{
public:
	double int_rate;


	Savings_Statement();
	~Savings_Statement();

	void deposit(double amount);
	void withdraw(double amount);
};
#endif 
