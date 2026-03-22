#include "Deep.h"

Deep::Deep(int d) {
	data = new int;
	*data = d;
}

Deep::Deep(const Deep& source) {
	data = new int;
	*data = *source.data;
	cout << "Copy constructor - deep copy " << endl;
}

Deep::~Deep() {
	delete data;
	cout << "Destructor freeing data" << endl;
}
