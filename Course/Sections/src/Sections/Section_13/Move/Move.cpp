#include "Move.h"

Move::Move(int d) {
	data = new int;
	*data = d;
	cout << "Contructor for: " << d << endl;
}

Move::Move(const Move& source) 
	:Move{*source.data} {
	cout << "Copy constructor - deep copy for: " << *data << endl;
}

Move::Move(Move&& source) noexcept
	: data{source.data} {
	source.data = nullptr;
	cout << "Move constructor - moving resource: " << *data << endl;
}

Move::~Move() {
	if (data != nullptr) {
		cout << "Destructor freeing data for: " << *data << endl;
	} else{
		cout << "Destructor freeing data for nullptr" << endl;
	}
	delete data;
}
