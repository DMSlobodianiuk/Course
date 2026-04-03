#include "..\..\..\..\Sections\include\Sections\Section_16\section_16.h"
#include "..\..\..\..\Sections\include\Sections\Section_16\Challenge\section_16_challenge.h"

class Base_Local{
public:
	virtual void say_hello() const {
		cout << "Hello - I'm a Base class object" << endl;
	}
	virtual ~Base_Local() {}
};

class Derived_Local :public Base_Local {
public:
	virtual void say_hello() const override {
		cout << "Hello - I'm a Derived class object" << endl;
	}
	virtual ~Derived_Local() {}
};

void greetings(const Base_Local& obj) {
	cout << "Greetings: ";
	obj.say_hello();
}

void polymorphism_case_1() {

	Base_Local b;
	b.say_hello();

	Derived_Local d;
	d.say_hello();
	cout << endl;
	greetings(b);
	greetings(d);

	cout << endl;
	Base_Local* ptr = new Derived_Local();
	ptr->say_hello();

	std::unique_ptr<Base_Local> ptr1 = std::make_unique<Derived_Local>();
	ptr1->say_hello();

	delete ptr; 
}

////////////////////////////////////////////////////////////

//class I_Printable {
//	friend std::ostream& operator<<(std::ostream& os, const I_Printable& obj);
//public:
//	virtual void print(std::ostream& os) const = 0;
//};

//std::ostream& operator<<(std::ostream& os, const I_Printable& obj) {
//	obj.print(os);
//	return os;
////}
//
//class Acc:public I_Printable {
//private:
//	double balance;
//	//friend std::ostream& operator<<(std::ostream& os, const Acc& acc);
//public:
//	virtual void withdraw(double amount) { cout << "In Acc::withdraw" << endl; }
//	virtual void print(std::ostream& os)const override {
//		os << "Acc display";
//	}
//	virtual ~Acc() { cout << "Acc destructor" << endl; }
//};
//
////std::ostream& operator<<(std::ostream& os, const Acc& acc) {
////	os << "Acc display";
////	return os;
////}
//
//class Savings :public Acc {
//private:
//	double balance;
//	//friend std::ostream& operator<<(std::ostream& os, const Savings& acc);
//public:
//	virtual void withdraw(double amount) { cout << "In Savings::withdraw" << endl; }
//	virtual void print(std::ostream& os)const override {
//		os << "Savings display";
//	}
//	virtual ~Savings() { cout << "Savings destructor" << endl; }
//};
//
////std::ostream& operator<<(std::ostream& os, const Savings& acc) {
////	os << "Savings display";
////	return os;
////}
//
//class Checking :public Acc {
//private:
//	double balance;
//	//friend std::ostream& operator<<(std::ostream& os, const Checking& acc);
//public:
//	virtual void withdraw(double amount) { cout << "In Checking::withdraw" << endl; }
//	virtual void print(std::ostream& os)const override {
//		os << "Checking display";
//	}
//	virtual ~Checking() { cout << "Checking destructor" << endl; }
//};
//
////std::ostream& operator<<(std::ostream& os, const Checking& acc) {
////	os << "Checking display";
////	return os;
////}
//
//class Trust :public Acc {
//private:
//	double balance;
//	//friend std::ostream& operator<<(std::ostream& os, const Trust& acc);
//public:
//	virtual void withdraw(double amount) { cout << "In Trust::withdraw" << endl; }
//	virtual void print(std::ostream& os)const override {
//		os << "Trust display";
//	}
//	virtual ~Trust() { cout << "Trust destructor" << endl; }
//};
//
////std::ostream& operator<<(std::ostream& os, const Trust& acc) {
////	os << "Trust display";
////	return os;
////}

//void polymorphism_case_2() {
//	cout << "\n === Pointers ===" << endl;
//	Acc* p1 = new Acc();
//	Acc* p2 = new Savings();
//	Acc* p3 = new Checking();
//	Acc* p4 = new Trust();
//
//	p1->withdraw(1000); //acc withdraw if virtual
//	p2->withdraw(1000); //savings withdraw if virtual
//	p3->withdraw(1000); //checking withdraw if virtual
//	p4->withdraw(1000); //trust withdraw if virtual
//
//	cout << "\n === Array ===" << endl;
//	Acc* arr[] = { p1,p2,p3,p4 };
//	for (auto i = 0; i < 4; i++)
//		arr[i]->withdraw(1000);
//
//	cout << "\n === Vector ===" << endl;
//	std::vector<Acc*> accs{ p1,p2,p3,p4 };
//	for (auto accs_ptr : accs)
//		accs_ptr->withdraw(1000);
//
//	cout << "\n === Clean up ===" << endl;
//	delete p1;
//	cout << endl;
//	delete p2;
//	cout << endl;
//	delete p3;
//	cout << endl;
//	delete p4;
//
//}

void polymorphism_case_3() {
	Base_Local* p1 = new Base_Local();
	p1->say_hello();

	Derived_Local* p2 = new Derived_Local();
	p2->say_hello();

	Base_Local* p3 = new Derived_Local();
	p3->say_hello();


	delete p1;
	delete p2;
	delete p3;
}

//void do_withdraw(Acc& acc, double amount) {
//	acc.withdraw(amount);
//}
//
//void polymorphism_case_4() {
//	Acc a;
//	Acc& ref = a;
//	ref.withdraw(1000);
//
//	Trust t;
//	Acc& ref1 = t;
//	ref1.withdraw(1000);
//
//	Acc a1;
//	Savings a2;
//	Checking a3;
//	Trust a4;
//
//	cout << endl;
//	do_withdraw(a1,1000);
//	do_withdraw(a2,1000);
//	do_withdraw(a3,1000);
//	do_withdraw(a4,1000);
//	cout << endl;
//}

class Shape {
private:
	//
public:
	virtual void draw() = 0;
	virtual void rotate() = 0;
	virtual ~Shape() {};
};

class Open_Shape :public Shape {
public:
	virtual ~Open_Shape() {}
};

class Closed_Shape :public Shape {
public:
	virtual ~Closed_Shape() {}
};

class Line : public Open_Shape {
public:
	virtual void draw() override {
		cout << "Drawing a line" << endl;
	}
	virtual void rotate() override {
		cout << "Rotating a line" << endl;
	}
};

class Circle :public Closed_Shape {
public:
	virtual void draw() override {
		cout << "Drawing a circle" << endl;
	}
	virtual void rotate() override {
		cout << "Rotating a circle" << endl;
	}
};

class Square : public Closed_Shape {
public:
	virtual void draw() override {
		cout << "Drawing a square" << endl;
	}
	virtual void rotate() override {
		cout << "Rotating a square" << endl;
	}
};

void polymorphism_case_5() {
	//Shape s; //Abstract
	//Shape* p = new Shape(); //Abstract

	/*Circle c;
	c.draw();*/

	//Shape* ptr = new Circle();
	//ptr->draw();
	//ptr->rotate();

	Shape* s1 = new Circle();
	Shape* s2 = new Line();
	Shape* s3 = new Square();

	std::vector<Shape*> vec = { s1,s2,s3 };

	for (auto figure : vec)
		figure->draw();

	cout << endl;

	for (auto figure : vec)
		figure->rotate();

	delete s1;
	delete s2;
	delete s3;
}

//void polymorphism_case_6() {
//	Acc* p1 = new Acc();
//	cout << *p1 << endl;
//
//	Acc* p2 = new Checking();
//	cout << *p2 << endl;
//
//	//Acc a;
//	//cout << a << endl;
//
//	//Checking c;
//	//cout << c << endl;
//
//	//Savings s;
//	//cout << s << endl;
//
//	//Trust t;
//	//cout << t << endl;
//
//	cout << endl;
//}

void display(const vector<Acc_challenge_16* >& accounts) {
	for (auto& acc : accounts)
		cout << *acc << endl;
}

void deposit(vector<Acc_challenge_16*>& accounts, double amount) {
	for (auto &acc : accounts)
		acc->deposit(amount);
}

void withdraw(vector<Acc_challenge_16*>& accounts, double amount) {
	for (auto &acc : accounts)
		acc->withdraw(amount);
}

void section_16_challenge() {
	
	//Acc_challenge_16 frank{ "Frank",55000 };
	//cout << frank << endl;

	Checking_challenge_16 frank{ "Frank",5000 };
	cout << frank << endl;

	cout << endl;

	Acc_challenge_16* trust = new Trust_challenge_16("James");
	cout << *trust << endl;
	
	cout << endl;

	Acc_challenge_16* p1 = new Checking_challenge_16("Larry", 10000);
	Acc_challenge_16* p2 = new Savings_challenge_16("Moe",1000);
	Acc_challenge_16* p3 = new Trust_challenge_16("Curly");

	vector<Acc_challenge_16*> accounts{ p1,p2,p3 };

	cout << endl;
	display(accounts);
	deposit(accounts,1000);
	withdraw(accounts,2000);
	cout << endl;
	display(accounts);

	cout << endl;
	delete trust;
	cout << endl;
	delete p1;
	delete p2;
	delete p3;
}
