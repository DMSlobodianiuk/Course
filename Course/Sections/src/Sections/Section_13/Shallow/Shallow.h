#pragma once
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Shallow {
private:
	int* data;
public:
	void set_data_value(int d) { *data = d; }
	int get_data_value() { return *data; }

	//Constructor
	Shallow(int d);

	//Copy Constructor
	Shallow(const Shallow& source);

	//Destructor
	~Shallow();
};
