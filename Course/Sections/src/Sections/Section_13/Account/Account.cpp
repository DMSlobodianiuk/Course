#include "Account.h"

//--------------------------------------------------------------
//assignment
//Account::Account() {}
//
//Account::Account(string name, double balance) {
//	this->name = name;
//	this->balance = balance;
//}
//
//Account::Account(string name) {
//	this->name = name;
//}
//
//Account::Account(double balance) {
//	this->balance = balance;
//}
//--------------------------------------------------------------
//--------------------------------------------------------------
//initialization
//Account::Account()
//	:name{ "None" }, balance{0.0} {
//}
//
//Account::Account(string name_val, double balance_val)
//	:name{ name_val }, balance{ balance_val } {
//}
//
//Account::Account(string name_val)
//	:name{ name_val } {
//}
//
//Account::Account(double balance_val)
//	:balance{ balance_val } {
//}
//--------------------------------------------------------------
//--------------------------------------------------------------
//delegating
Account::Account(string name_val, double balance_val)
	:name{ name_val }, balance{ balance_val } {
	cout << name << "'s account was created" << endl;
}

Account::Account(string name_val)
	:Account{ name_val, 0.0} {
}

Account::Account(double balance_val)
	:Account{ "",balance_val } {
}

Account::Account()
	:Account{ "",0.0 } {
}
//--------------------------------------------------------------
//--------------------------------------------------------------
//default constructor parameters
//Account::Account(string name_val = "None", double balance_val = 0.0)
//	:name{ name_val }, balance{ balance_val } {
//}
//--------------------------------------------------------------

Account::Account(const Account& source)
	:name{ source.name },
	balance{ source.balance } {
}

void Account::set_balance(double bal) {
	balance = bal;
}

double  Account::get_balance() {
	return balance;
}

void Account::set_name(string n) {
	name = n;
}

string Account::get_name() {
	return name;
}

bool Account::deposit(double ammount) {
	balance += ammount;
	return true;
}

bool Account::withdraw(double ammount) {
	if (balance - ammount >= 0) {
		balance -= ammount;
		return true;
	} else {
		return false;
	}
}

Account::~Account() { cout << name << "'s account was destroyed" << endl; }
