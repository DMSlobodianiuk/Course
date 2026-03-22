#include "Shallow.h"

Shallow::Shallow(int d) {
	data = new int;
	*data = d;
}

Shallow::Shallow(const Shallow& source)
	:data{ source.data } {
	cout << "Copy constructor - shallow copy" << endl;
}

Shallow::~Shallow() {
	delete data;
	cout << "Destructor freeing data" << endl;
}
