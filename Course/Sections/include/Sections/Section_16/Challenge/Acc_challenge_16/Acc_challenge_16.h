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

class IllegalBalanceExceptopn :public std::exception{
public:
	IllegalBalanceExceptopn() = default;
	string Message() const { return "You've triggered IllegalBalanceExceptopn.Message() method"; }
	virtual const char* what() const noexcept { return "Illegal Balance Exception"; }
	~IllegalBalanceExceptopn() = default;
};

class InsufficientFundsException : public std::exception {
public:
	InsufficientFundsException() = default;
	virtual const char* what() const noexcept { return "Insufficient Funds Exception"; }
	~InsufficientFundsException() = default;
};
