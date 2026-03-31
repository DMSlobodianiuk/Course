#include "..\..\..\..\include\Sections\Section_15\Savings_Statement\Savings_Statement.h"

Savings_Statement::Savings_Statement() 
	:int_rate{3.0} {
}

Savings_Statement::~Savings_Statement()
{
}

void Savings_Statement::deposit(double amount) {
	cout << "Savings Statement deposit called with " << amount << endl;
}

void Savings_Statement::withdraw(double amount) {
	cout << "Savings Statement withdraw called with " << amount << endl;
}
 