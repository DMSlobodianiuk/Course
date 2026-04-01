#include "..\..\..\..\include\Sections\Section_15\Statement\Statement.h"

Statement::Statement() 
	:balance{ 0.0 }, name{"An Account"} {
	cout << "Statement constructor" << endl;
}

Statement::Statement(double balance)
	:balance{ balance } {
	cout << "Statement args constructor" << endl;
}

Statement::~Statement()
{
	cout << "Statement destructor" << endl;
}

std::ostream &operator<<(std::ostream& os, const Statement& statement) {
	os << "Statement balance: " << statement.balance;
	return os;
}

void Statement::deposit(double amount) {
	cout << "Balance before: " << balance << " , deposit: " << amount;
	balance += amount;
	cout<<" after deposit: " << balance << endl;
	//cout << "Statement deposit called with " << amount << endl;
}

void Statement::withdraw(double amount) {
	if (balance - amount >= 0) {
		cout << "Balance before: " << balance << " , withdraw: " << amount;
		balance -= amount;
		cout << " after withdraw: " << balance << endl;
	}
	else
		cout << "Insufficient funds" << endl;
	//cout << "Statement withdraw called with " << amount << endl;
}
