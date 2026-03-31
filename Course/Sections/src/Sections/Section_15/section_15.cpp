#include "..\..\..\include\Sections\Section_15\section_15.h"

void deriving_case_1() {
	
	//Use the Statement class
	cout << "\n=========Statement===============================" << endl;
	Statement acc{};
	acc.deposit(2000.0);
	acc.withdraw(500.0);

	cout << endl ;

	Statement* p_acc{ nullptr };
	p_acc = new Statement();
	p_acc->deposit(1000.0);
	p_acc->withdraw(500.0);
	delete p_acc;

	//Use the Savings Statement class
	cout << "\n=========Savings Statement===============================" << endl;
	Savings_Statement sav_acc{};
	sav_acc.deposit(2000.0);
	sav_acc.withdraw(500.0); 

	cout << endl;

	Savings_Statement* p_sav_acc{ nullptr };
	p_sav_acc = new Savings_Statement();
	p_sav_acc->deposit(1000.0);
	p_sav_acc->withdraw(500.0);
	delete p_sav_acc;

	cout << "\n=======================================================" << endl;
}

void deriving_case_2() {

	cout << "===Base member access from base objects==============" << endl;

	Base base;
	base.a = 100; //public - ok
	//base.b = 200; //protected - compiler error
	//base.c = 300; //private - compiler error
	base.display();

	cout << "===Base member access from derived objects==============" << endl;

	Derived d;
	d.a = 100; //Base pubic -> Derived public -> ok
	//d.b = 200; //Base protected -> Derived protected -> compiler error
	//d.c = 300; //Base private -> Derivaed no access -> compiler error
	d.set_c(300); //Base private -> Derived calls Base's setter -> Base's private value modified

	d.display();
}

void deriving_case_3() {
	//Base b;
	//Base b{ 100 };

	Derived d;
	//Derived d {100};
	
}
