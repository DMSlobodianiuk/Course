#pragma once
#include <iostream>

using std::cout;
using std::endl;

class Base {
private:
	int value;
	int c{ 0 };
protected:
	int b{ 0 };
public:
	Base();
	Base(int x);
	~Base();

	void set_c(int new_c);

	int a{ 0 };
	void display() { cout << a<< ", " << b << ", " << c << endl; }

};
