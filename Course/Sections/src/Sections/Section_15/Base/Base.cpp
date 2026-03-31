#include "..\..\..\..\include\Sections\Section_15\Base\Base.h"

Base::Base() 
	:value{0} {
	cout << "Base no-args constructor" << endl;
}

Base::Base(int x)
	:value{x} {
	cout << "Base(int) overloaded constructor" << endl;
}

Base::~Base()
{
	cout << "Base destructor" << endl;
}

void Base::set_c(int new_c) {
	c = new_c; 
}
