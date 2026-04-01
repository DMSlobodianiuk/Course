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

	//Derived d;
	Derived d {100};
}

void deriving_case_4() {
	/*Base  b{ 100 };
	Base b1{ b };
	b = b1;*/

	Derived d{ 100 };
	cout << endl;
	Derived d1{ d };
	cout << endl;
	d = d1;
	cout << endl;
} 

void deriving_case_5() {
	cout << "=========== Statement class ======================" << endl;
	Statement s1{ 1000.0 };
	cout << s1 << endl;

	s1.deposit(500.0);
	cout << s1 << endl;

	s1.withdraw(1000);
	cout << s1 << endl;

	s1.withdraw(5000.0);
	cout << s1 << endl;

	cout << "\n=========== Savings Statement class ======================" << endl;
	Savings_Statement s2{ 1000.0 , 5.0};
	cout << s2 << endl;

	s2.deposit(1000.0);
	cout << s2 << endl;

	s2.withdraw(2000);
	cout << s2 << endl;

	s2.withdraw(1000.0);
	cout << s2 << endl;

}

void section_15_challenge() {

	//Acc a1;
	//Acc a2{ "a2 name" };
	//Acc a3{ 123.45 };
	//Acc a4{"a4 name", 4444};


	//cout << a1;
	//cout << a2;
	//cout << a3;
	//cout << a4;

	cout << "============ Acc ============" << endl;

	Acc ac1{};
	Acc ac2{"Larry"};
	Acc ac3{"Moe", 2000};
	Acc ac4{"Curly",5000};

	cout << ac1;
	cout << ac2;
	cout << ac3;
	cout << ac4;

	cout << "============= Savings Acc ============" << endl;

	Savings_Acc s_ac1{ };
	Savings_Acc s_ac2{"S_Larry"};
	Savings_Acc s_ac3{ "S_Moe",333};
	Savings_Acc s_ac4{"S_Curly",5555};

	cout << s_ac1;
	cout << s_ac2;
	cout << s_ac3;
	cout << s_ac4;

	cout << "============= Checking Acc ============" << endl;

	Checking_Acc c_ac1{ };
	Checking_Acc c_ac2{ "c_Larry" };
	Checking_Acc c_ac3{ "c_Moe",333 };
	Checking_Acc c_ac4{ "c_Curly",5555 };

	cout << c_ac1;
	cout << c_ac2;
	cout << c_ac3;
	cout << c_ac4;

	cout << "============= Trust Acc ============" << endl;

	Trust_Acc t_ac1{};
	Trust_Acc t_ac2{"t_Larry",100.0};
	Trust_Acc t_ac3{"t_Moe",500.0};
	Trust_Acc t_ac4{"t_Moe",1000.0,5.0};

	cout << t_ac1;
	cout << t_ac2;
	cout << t_ac3;
	cout << t_ac4;
	t_ac4.withdraw(100);
	t_ac4.withdraw(100);
	t_ac4.withdraw(100);
	t_ac4.withdraw(100);
	t_ac4.withdraw(100);
	cout << t_ac4;

	cout << "====================================" << endl;
}
