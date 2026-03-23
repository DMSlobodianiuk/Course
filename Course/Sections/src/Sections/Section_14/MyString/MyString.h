#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

class MyString {
	//Insertion operator << (cout)
	friend std::ostream& operator<<(std::ostream& os, const MyString& rhs);
	//Extraction operator >>(cin)
	friend std::istream& operator>>(std::istream& in,MyString& rhs);

	//friend bool operator == (const MyString& lhs, const MyString& rhs);
	//friend MyString operator-(const MyString& obj);
	//friend MyString operator+(const MyString& lhs,const MyString &rhs);
private:
	char* str;
public:
	MyString();  //No-args
	MyString(const char* s);  //Overloaded
	MyString(const MyString& source);  //Copy
	MyString(MyString&& source); //Move

	void display() const;
	int get_length() const;
	const char* get_str() const;

	//Copy assignment
	MyString &operator=(const MyString& rhs);
	
	//Move assignment
	MyString& operator=(MyString&& rhs);

	//Unary operator- make lowercase
	MyString operator-() const;
	
	//Binary operator== compare string
	bool operator==(const MyString& rhs) const;

	//Binary operator!= compare string
	bool operator!=(const MyString& rhs) const;

	//Binary operator < compare string
	bool operator<(const MyString& rhs) const;

	//Binary operator > compare string
	bool operator>(const MyString& rhs) const;

	//Binary operator+ concatenation
	MyString operator+(MyString& rhs) const;

	//Binary operator += concatenate
	MyString operator+=(MyString& rhs);

	//Binary operator* repeat
	MyString operator*(int &n) const;

	//Binary operator *= concatenate
	MyString operator*=(int& n);

	~MyString();
};
