#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//In the US:
//	1 dollar is 100 cents
//	1 quarter is 25 cents
//	1 dime is 10 cents
//	1 nickel is 5 cents
//	1 penny is 1 cent

void section_8_practice()
{
	int cents{ 0 };
	cout << "Enter an amount in cents : ";
	cin >> cents;

	int dollars{ 0 }, quarters{ 0 }, dimes{ 0 }, nickels{ 0 }, pennies{ 0 };

	//-----------------------------------
	dollars = cents / 100;
	cents -= dollars * 100;

	quarters = cents / 25;
	cents -= quarters * 25;

	dimes = cents / 10;
	cents -= dimes * 10;
	
	nickels = cents / 5;
	cents -= nickels * 5;
	
	pennies = cents;
	//-----------------------------------

	cout << "You can provide change for this change as follows:\ndollars: " << dollars << "\nquarters : " << quarters <<
		"\ndimes : " << dimes << "\nnickels : " << nickels << "\npennies : " << pennies << endl;

}
