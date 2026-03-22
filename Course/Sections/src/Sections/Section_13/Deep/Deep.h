#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Deep {
private:
	int* data;
public:
	void set_data_value(int d) { *data = d; }
	int get_data_value() { return *data; }

	//Constructor 
	Deep(int d);
	
	//Copy Constructor
	Deep(const Deep& source);
	
	//Destructor
	~Deep();
};
