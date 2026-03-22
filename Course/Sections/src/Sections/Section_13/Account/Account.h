#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
//#pragma once
#include <string>
#include<iostream>

using std::cout;
using std::endl;
using std::string;

class Account {
private:
	string name;
	double balance;
public:
	//Contructors
	Account();
	Account(string name, double balance);
	Account(string name);
	Account(double balance);

	//Copy constructor
	Account(const Account& source);

	void set_balance(double bal);
	double get_balance();

	//Setter
	void set_name(string n);
	//Getter
	string get_name();
	 
	bool deposit(double amount);
	bool withdraw(double amount);

	void print_balance() { cout << "Current balance is: " << balance << endl; }
	void print_name() { cout << "Owner's name is: " << name << endl; }

	~Account();
};

#endif
