#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <string> // <-- Add this include

using std::cin;
using std::cout;
using std::endl;
using std::string;

void c_style_case_1()
{
	char first_name[20]{};
	char last_name[20]{};
	char full_name[20]{};
	char temp[50]{};

	//cout << "Please, enter your first name: ";
	//cin >> first_name;
	//cout << "Please, enter your second name: ";
	//cin >> last_name;
	//
	//cout << "\n------------------------------------------" << endl;

	//cout << "Hello, " << first_name << " your first name has " << strlen(first_name) << " characters" << endl;
	//cout << "and your last, " << last_name << " has " << strlen(last_name) << " characters" << endl;
	//
	//cout << "------------------------------------------" << endl;

	//strcpy_s(full_name, first_name);
	//strcat_s(full_name, " ");
	//strcat_s(full_name, last_name);
	//cout << "Your full name is " << full_name << endl;
	//cout << "------------------------------------------" << endl;

	//cout << "Enter your full name: ";
	//cin >> full_name;
	//cout << "My full name is: " << full_name<<endl;;

	cout << "Enter your full name: ";
	cin.getline(full_name,50);
	cout << "My full name is: " << full_name << endl;;

}
void cpp_strings_case_1() {

	//string s1{ "Apple" };
	//cout << s1 << " with lenght: "<<s1.length() << endl;

	//string s2(10, 'X');
	//cout << s2 << " with lenght: " << s2.length() << endl;

	//string s3{ s1 + " that 'Apple' was copied from s1" };
	//cout << s3 << " with lenght: " << s3.length()<< endl;

	//string s0;
	//string s1{ "Apple" };
	//string s2{ "Banana" };
	//string s4{ "apple" };
	//string s5{ s1 };
	//string s6{ s1,0,3};
	//string s7(10,'X');
	//
	//cout << "\nComparation" << "\n---------------------------------------------" << endl;
	//cout << std::boolalpha;
	//cout << s1 << " == " << s5 << " :" << (s1 == s5) << endl;
	//cout << s1 << " == " << s2 << " : "  << (s1 == s2) << endl;
	//cout << s1 << " != " << s2 << " : " << (s1 != s2) << endl;
	//cout << s1 << " < " << s2 << " : " << (s1 < s2) << endl;
	//cout << s2 << " > " << s1 << " : " << (s2 > s1) << endl;
	//cout << s4 << " < " << s5 << " : " << (s4 < s5) << endl;
	//cout << s1 << " == " << "Apple" << " : " << (s1 == "Apple") << endl;

	//looping
	//cout << "\nLooping (for/range base)" << "\n--------------------------------------" << endl;

	//string s1{ "Apple" };

	//for (size_t i{ 0 }; i < s1.length(); ++i)
	//	cout << s1.at(i) << " ";
	//cout << endl;

	//for (char c : s1)
	//	cout << c << " ";
	//cout << endl;

	//substring
	//cout << "\nSubstring" << "\n--------------------------------------" << endl;
	//string s1{ "This is a test" };

	//cout << s1.substr(0, 4) << endl;  //Test
	//cout << s1.substr(5, 2) << endl;  //is 
	//cout << s1.substr(10, 4) << endl; //test

	//erasing
	//cout << "\nErasing" << "\n--------------------------------------" << endl;
	//string s1{ "This is a test" };
	//
	//s1.erase(0, 5);
	//cout << "s1 is now: " << s1 << endl;

	//getline
	//cout << "\nGetLine" << "\n--------------------------------------" << endl;
	//string full_name{};

	//cout << "Enter your full name: ";
	//std::getline(cin, full_name);

	//cout << "Your full name is: " << full_name << endl;

	//find
	//cout << "\nFind" << "\n--------------------------------------" << endl;
	string s1{ "The secret word is Boo" };
	string word{};

	cout << "Enter word to find: ";
	cin >> word;

	size_t position = s1.find(word);

	if (position != string::npos)
		cout << "Found " << word << " at position: " << position << endl;
	else
		cout << "Sorry, " << word << " not found" << endl;
}
void section_10_challenge() {

	std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	std::string key = "XYZABCDEFGHIJKLMNOPQRSTUVWxyzabcdefghijklmnopqrstuvw";

	string message{};
	cout << "Please enter the message: ";
	std::getline(cin, message);

	string crypted{};
	for (size_t i{ 0 }; i < message.length(); ++i) {
		
		if (message.at(i) == ' ')
			crypted += ' ';
		else if (ispunct(message.at(i)))
			crypted += message.at(i);
		else if (isdigit(message.at(i)))
			crypted += message.at(i);
		else
			crypted += key.at(alphabet.find(message.at(i)));
	}

	cout << "Your crypted message is: " << crypted << endl;

	string encrypted{};
	for (size_t i{ 0 }; i < crypted.length(); ++i) {
		if (crypted.at(i) == ' ')
			encrypted += ' ';
		else if (ispunct(crypted.at(i)))
			encrypted += crypted.at(i);
		else if (isdigit(crypted.at(i)))
			encrypted += crypted.at(i);
		else
			encrypted += alphabet.at(key.find(crypted.at(i)));
	}
	cout << "Your encrypted message is: " << encrypted << endl;
}
void section_10_assignment_1()
{
	//examples to save time
	//string input{"12345"};
	//string input{"ABCDEFG"};
	//string input{"C++isFun!"};
	//string input({ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" });

	string input;
	cout << "Please, enter a string to pyramid it: ";
	getline(cin, input);

	string first_output{ "" };
	string second_output{ "" };

	int up{ 0 };

	for (int i{ 0 }; i < input.length(); i++) {
		up = 0;
		first_output = "";

		for (int spaces{ (int)input.length() }; 0 < spaces - i - 1; spaces--)
			cout << " ";

		for (int j{ 0 }; j < i * 2 + 1; j++) {
			if (up <= i) {
				first_output += input.at(up);
				up += 1;
			}
		}
		
		if (i != 0) {
			second_output = "";
			for (int j{ (int)first_output.length() -1 }; 0 < j; j--)
				second_output += first_output.at(j-1);
		}

		string final_output{ first_output + second_output };

		cout << final_output;
		cout << endl;
	}
}
