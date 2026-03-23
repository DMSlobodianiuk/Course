#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include "MyString/MyString.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void operator_overloading_case_1() {
	MyString empty;
	MyString larry{"Larry"};
	MyString stooge{larry};

	empty.display();
	larry.display();
	stooge.display();
}

//bool operator==(const MyString& lhs, const MyString& rhs) {
//	cout << "Non-member  == overload" << endl;
//	if (std::strcmp(lhs.get_str(), rhs.get_str()) == 0)
//		return true;
//	else
//		return false;
//}

//MyString operator+(MyString &lhs, MyString& rhs)  {
//	cout << "Non-Member concatenation" << endl;
//	size_t buff_size = std::strlen(lhs.get_str()) + std::strlen(rhs.get_str()) + 1;
//
//	char* buff = new char[buff_size];
//
//	std::strcpy(buff, lhs.get_str());
//
//	std::strcat(buff, rhs.get_str());
//
//	MyString temp{ buff };
//
//	delete[] buff;
//
//	return temp;
//}

void operator_overloading_case_2() {
	cout << std::boolalpha;
	//MyString a{ "Hello" };
	//MyString b;
	//---------------------------------------------------
	//Copy assignment
	//a = a;
	//
	//b = a;
	//
	//b = "This is a test";
	//
	//Move assignment
	//a = MyString{ "Joe" };
	//a = "Frank";
	//---------------------------------------------------
	//MyString a{ "Hello" };
	//a = MyString{ "Holla" };
	//a = "Bonjour";
	//
	//MyString b;
	//
	//a.display();
	////lower case
	//b = -a;
	//b.display();
	//---------------------------------------------------
	// == operator
	//MyString a("hi");
	//MyString b("hola");
	//MyString c("hi");

	//cout << (a == b) << endl;
	//cout << (b == c) << endl;
	//cout << (a == c) << endl;
	//---------------------------------------------------
	////binary + operator
	//MyString a{ "a" };
	//MyString b{ "b" };
	//MyString c{ "c" };
	//MyString d;

	////Member
	//d = a + b + c;
	//d = d + a;

	////Non-Member
	//d = a + b;

	//d = d + c;

	//d.display();
	//---------------------------------------------------
	//insertion <<
	//extraction >>

	MyString larry{ "Larry" };
	MyString moe{ "Moe" };
	MyString curly;

	cout << "Enter the third stooge's first name: ";
	cin >> curly;

	cout << "The three stooges are " << larry << ", " << moe << " and " << curly << endl;

	cout << "\nEnter the threestooges names separated by a space: ";
	cin >> larry >> moe >> curly;

	cout << "The three stooges are " << larry << ", " << moe << " and " << curly << endl;

}

void section_14_challenge() {
	MyString a;
	MyString b;
	MyString c;

	cout << std::boolalpha;

	//unary minus
	a = "AAAAAAAaAAAAAA";
	cout << "------------------------------------\n";
	cout << "unary minus" << endl;
	a.display();
	a = -a;
	a.display();

	//return true if the two string are equal
	a = "abc";
	b = "abc";
	c = "bcaacb";
	cout << "------------------------------------\n";
	cout << "return true if the two string are equal" << endl;
	cout << "a: " << a << " | b: " << b << endl;
	cout << (a == b) << endl;

	//return true if the two string are not equal
	cout << "------------------------------------\n";
	cout << "return true if the two string are not equal" << endl;
	cout << "a: " << a << " | c: " << c << endl;
	cout << (a != c) << endl;

	//return true if the lhs string is lexically less than the rhs string
	cout << "------------------------------------\n";
	cout << "return true if the lhs string is lexically less than the rhs string" << endl;
	cout << "a: " << a << " | c: " << c << endl;
	cout << (a < c) << endl;

	//return true if the lhs string is lexically greater than the rhs string
	cout << "------------------------------------\n";
	cout << "return true if the lhs string is lexically greater than the rhs string" << endl;
	cout << "a: " << a << " | c: " << c << endl;
	cout << (a > c) << endl;

	//concatenation
	cout << "------------------------------------\n";
	cout << "concatenation" << endl;
	cout << "a: " << a << " | c: " << c << endl;
	cout << (a + c) << endl;

	//concatenate the rhs string to the lhs string and store the result in the lhs object
	cout << "------------------------------------\n";
	cout << "concatenate the rhs string to the lhs string and store the result in the lhs object" << endl;
	cout << "a: " << a << " | c: " << c << endl;
	a += c;
	cout << a << endl;

	//repeat - results in a string that is copied n times;
	int times{ 3 };
	cout << "------------------------------------\n";
	cout << "repeat - results in a string that is copied n times" << endl;
	cout << "a: " << a <<" | b:"<<b << " | times: " << times << endl;
	a = b * times;
	cout << a << endl;

	//repeat - results in a string that is copied n times;
	times = 4;
	a = b;
	cout << "------------------------------------\n";
	cout << "repeat - results in a string that is copied n times" << endl;
	cout << "a: " << a << " | b:" << b << " | times: " << times << endl;
	a *= times;
	cout << a << endl;


}
