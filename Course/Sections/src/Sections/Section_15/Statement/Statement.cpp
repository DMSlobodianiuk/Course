#include "..\..\..\..\include\Sections\Section_15\Statement\Statement.h"

Statement::Statement() 
	:balance{ 0.0 }, name{"An Account"} {
}

Statement::~Statement()
{
}

void Statement::deposit(double amount) {
	cout << "Statement deposit called with " << amount << endl;
}

void Statement::withdraw(double amount) {
	cout << "Statement withdraw called with " << amount << endl;
}
