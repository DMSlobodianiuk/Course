#pragma once
#include "..\Base\Base.h"

class Derived :public Base {
private:
	int doubled_value;
protected:

public:
	Derived();
	Derived(int x);
	Derived(const Derived& other);

	Derived& operator=(const Derived& rhs);

	~Derived();

	void access_base_memeber();
};
