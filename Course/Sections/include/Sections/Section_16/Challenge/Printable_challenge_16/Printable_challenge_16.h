#pragma once
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class Printable {
	friend std::ostream& operator<<(std::ostream& os, const Printable& obj);
public:
	virtual void print(std::ostream& os) const = 0;
	virtual ~Printable() = default;
};

inline std::ostream& operator<<(std::ostream& os, const Printable& obj) {
	obj.print(os);
	return os;
}
