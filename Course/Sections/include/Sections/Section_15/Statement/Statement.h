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
public:
	double balance;
	string name;
	
	void deposit(double amount);
	void withdraw(double amount);

	Statement();
	~Statement();
};
#endif
