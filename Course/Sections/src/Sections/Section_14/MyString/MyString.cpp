#include "MyString.h"

//No-args constructor
MyString::MyString()
	:str{ nullptr } {
	str = new char[1];
	*str = '\0';
}

//Overloaded constructor
MyString::MyString(const char*s)
	:str{ nullptr } {
	if (s == nullptr) {
		str = new char[1];
		*str = '\0';
	}
	else {
		str = new char[std::strlen(s) + 1];
		std::strcpy(str, s);
		//std::copy(s, s + std::strlen(s) + 1, str);
	}
}

//Move constructor
MyString::MyString(MyString&& source)
	:str(source.str) {
	source.str = nullptr;
	//cout << "Move constructor used" << endl;
}

//Copy constructor
MyString::MyString(const MyString& source)
	:str{ nullptr } {
	str = new char[std::strlen(source.str) + 1];
	std::strcpy(str, source.str);
}

//Display method
void MyString::display() const {
	//cout << "My string: " << str <<" has length: "<<get_length() << endl;
	cout << str << " : " << get_length() << endl;
}

//Get length method
int MyString::get_length() const {
	return std::strlen(str);
}

//Get str method
const char *MyString::get_str() const {
	return str;
}

//Assignment operator Overloading
//rhs - right hand side
MyString& MyString::operator=(const MyString& rhs) {
	//cout << "Copy assignment" << endl;
	if (this == &rhs)
		return *this;

	delete [] str;
	str = new char[std::strlen(rhs.str) + 1];
	std::strcpy(str, rhs.str);

	return *this;
}

//Move assignment Overloading
MyString& MyString::operator=(MyString&& rhs) {
	//cout << "Move assignment" << endl;
	if (this == &rhs)
		return *this;

	delete[] str;
	str = rhs.str;

	rhs.str = nullptr;

	return *this;
}

//Unary operator- make lowercase
MyString MyString::operator-() const {
	//cout << "Member operator-" << endl;
	char* buff = new char[std::strlen(str) + 1];

	std::strcpy(buff, str);
	
	for (size_t i = 0; i < std::strlen(buff); i++)
		buff[i] = std::tolower(buff[i]);
	
	MyString temp{ buff };
	
	delete[] buff;

	return temp;
}
//FRIEND Unary operator- make lowercase
//MyString operator-(const MyString&obj){
//	cout << "Friend operator-" << endl;
//	char* buff = new char[std::strlen(obj.str) + 1];
//
//	std::strcpy(buff, obj.str);
//
//	for (size_t i = 0; i < std::strlen(buff); i++)
//		buff[i] = std::tolower(buff[i]);
//
//	MyString temp{ buff };
//
//	delete[] buff;
//
//	return temp;
//}

//Binary operator== compare string
bool MyString::operator==(const MyString& rhs) const {
 //cout<<"Member == operator"<<endl;
	if (std::strcmp(str, rhs.str) == 0)
		return true;
	else
		return false;
}
//FRIEND Binary operator== compare string
//bool operator==(const MyString &lhs,const MyString& rhs){
//	cout << "Friend == operator" << endl;
//	if (std::strcmp(lhs.str, rhs.str) == 0)
//		return true;
//	else
//		return false;
//}

//Binary operator!= compare string
bool MyString::operator!=(const MyString& rhs) const {
	//cout<<"Member == operator"<<endl;
	if (std::strcmp(str, rhs.str) == 0)
		return false;
	else
		return true;
}

//Binary operator < compare string
bool MyString::operator<(const MyString& rhs) const {
	if(std::strlen(str) < std::strlen(rhs.str))
		return true;
	else
		return false;
}

//Binary operator > compare string
bool MyString::operator>(const MyString& rhs) const {
	if (std::strlen(str) > std::strlen(rhs.str))
		return true;
	else
		return false;
}

//Binary operator+ concatenation
MyString MyString::operator+(MyString& rhs) const {
	//cout << "Member concatenation" << endl;
	size_t buff_size = std::strlen(str) + std::strlen(rhs.str) + 1;
	
	char* buff = new char[buff_size];
	
	std::strcpy(buff, str);
	
	std::strcat(buff, rhs.str);
	
	MyString temp{ buff };
	
	delete[] buff;
	
	return temp;
}
//FRIEND Binary operator+ concatenation
//MyString operator+(const MyString &lhs, const MyString& rhs){
//	cout << "Friend concatenation" << endl;
//	size_t buff_size = std::strlen(lhs.str) + std::strlen(rhs.str) + 1;
//
//	char* buff = new char[buff_size];
//
//	std::strcpy(buff, lhs.str);
//
//	std::strcat(buff, rhs.str);
//
//	MyString temp{ buff };
//
//	delete[] buff;
//
//	return temp;
//}

//Binary operator += concatenate
MyString MyString::operator+=(MyString& rhs){
	size_t buff_size = std::strlen(str) + std::strlen(rhs.str) + 1;

	char* buff = new char[buff_size];

	std::strcpy(buff, str);

	std::strcat(buff, rhs.str);

	delete[] str;

	str = buff;

	return *this;
}

//Binary operator* repeat
MyString MyString::operator*(int& n) const {

	size_t buff_size = std::strlen(str)*n + 1;

	char* buff = new char[buff_size];

	std::strcpy(buff, "");

	for (size_t i{ 0 }; i < n; i++)
		std::strcat(buff, str);

	MyString temp{ buff };

	delete[] buff;

	return temp;

};

//Binary operator *= concatenate
MyString MyString::operator*=(int& n) {
	size_t buff_size = std::strlen(str) + std::strlen(str) * n + 1;

	char* buff = new char[buff_size];

	std::strcpy(buff, str);

	for (size_t i{ 0 }; i < n; i++)
		std::strcat(buff, str);

	delete[] str;

	str = buff;

	return *this;
}


//Insertion operator << (cout)
std::ostream& operator<<(std::ostream& os, const MyString& rhs) {
	os << rhs.str;
	return os;
}
//Extraction operator >>(cin)
std::istream& operator>>(std::istream& in, MyString& rhs) {
	char* buff = new char[1000];
	in >> buff;

	rhs = MyString{ buff }; //move assignment
	delete[] buff;

	return in;
}

//Destructor
MyString::~MyString() {
	//cout << "Destructor called"<< endl;
	delete [] str;
}
