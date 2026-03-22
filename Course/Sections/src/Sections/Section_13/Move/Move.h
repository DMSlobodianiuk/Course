#pragma once
#include <iostream>

using std::cout;
using std::endl;

class Move {
private:
	int* data;
public:
	void set_data_value(int d) { *data = d; }
	int get_data_value() { return *data; };
	
	//Constructor
	Move(int d);

	//Copy Constructor
	Move(const Move& source);

	//Move Constructor
	Move(Move&& source) noexcept;

	//Destructor
	~Move();
};
