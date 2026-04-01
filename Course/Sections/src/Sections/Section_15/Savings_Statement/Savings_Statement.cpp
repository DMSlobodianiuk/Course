#include "..\..\..\..\include\Sections\Section_15\Savings_Statement\Savings_Statement.h"

//Savings_Statement::Savings_Statement() 
//	:int_rate{3.0} {
//}

Savings_Statement::Savings_Statement()
	:Savings_Statement{ 0.0,0.0 } {

}

Savings_Statement::Savings_Statement(double balance, double int_rate)
	:Statement{ balance }, int_rate{ int_rate } {

}

Savings_Statement::~Savings_Statement()
{
}

std::ostream& operator<<(std::ostream& os, const Savings_Statement& savings_statement) {
	os << "Savings_Statement balance: " << savings_statement.balance<<" Interest rate: "<<savings_statement.int_rate;
	return os;
}

void Savings_Statement::deposit(double amount) {
	cout << "Savings Statement's deposit" << endl;
	amount += amount * int_rate / 100;
	Statement::deposit(amount);
	//cout << "Savings Statement deposit called with " << amount << endl;
}

void Savings_Statement::withdraw(double amount) {
	cout << "Savings Statement's withdraw" << endl;
	amount += amount * int_rate / 100;
	Statement::withdraw(amount);
	//cout << "Savings Statement withdraw called with " << amount << endl;
}
 
void Savings_Statement::redefined_deposit(double amount) {
	amount *= 2;
	Statement::deposit(amount);
}
