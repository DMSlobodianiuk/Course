#include "..\..\..\..\include\Sections\Section_15\Derived\Derived.h"

//Derived::Derived()
//	:doubled_value{0} {
//	cout << "Derived no-args constructor" << endl;
//}

//Контрольований виклик базового конструктора
Derived::Derived()
	:Base{},doubled_value{ 0 } {
	cout << "controlled Derived no-args constructor" << endl;
}

//Контрольований виклик перевантаженого базового конструктора
Derived::Derived(int x)
	:Base{ x }, doubled_value{ x * 2 } {
	cout << "int Derived constructor" << endl;
}

Derived::Derived(const Derived& other)
	: Base(other), doubled_value(other.doubled_value) {
	cout << "Derived copy construtctor" << endl;
}

Derived& Derived::operator=(const Derived& rhs) {
	cout << "Derived operator=" << endl;
	if (this == &rhs)
		return *this;
	Base::operator=(rhs);
	doubled_value = rhs.doubled_value;
	return *this;
}

////Without passing args to base class constructor
//Derived::Derived(int x) 
//	:doubled_value(x*2){
//	cout << "Derived (int) overloaded constructor" << endl;
//}

//With passing args to base class constructor
//Derived::Derived(int x)
//	:Base(x * 2) {
//	cout << "Derived (int) with passing args to base class constructor overloaded constructor" << endl;
//}

Derived::~Derived()
{
	cout << "Derived destructor" << endl;
}

void Derived::access_base_memeber() {
	a = 100; //Base pubic -> Derived proteted -> ok
	b = 200; //Base protected -> Derived protected -> ok

	//c = 300; //Base private -> Derivaed no access -> compiler error
	//set_c(300); //Base private -> Derived calls Base's setter -> Base's private value modified
}
