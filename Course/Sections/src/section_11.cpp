#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <string>
#include <cmath>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

void cmath_case_1()
{
	double num{ };
	cout << "Enter a number(double): ";
	cin >> num;

	cout << "The sqrt of " << num << " is: " << sqrt(num) << endl;
	cout << "The cubed root of " << num << " is: " << cbrt(num) << endl;

	cout << "The sine of " << num << " is: " << sin(num) << endl;
	cout << "The cosine of " << num << " is: " << cos(num) << endl;

	cout << "The ceil of " << num << " is: " << ceil(num) << endl;
	cout << "The floor of " << num << " is: " << floor(num) << endl;
	cout << "The round of " << num << " is: " << round(num) << endl;

	double power{};
	cout << "\nEnter a power to raise " << num << " to: ";
	cin >> power;
	cout << num << " raised to the " << power << " power is:" << pow(num, power) << endl;

}
void cstlib_case_1() 
{
	int random_number{};
	size_t count{ 10 };
	int min{ 1 };
	int max{ 6 };

	cout << "RAND_MAX on my system is: " << RAND_MAX << endl;
	srand(time(nullptr)); //allows to generate random values each run

	for (size_t i{ 1 }; i <= count; ++i) {
		random_number = rand() % max + min;
		cout << random_number << " ";
	}
	cout << endl;

}

double calc_cost(double base_cost = 100.0, double tax_rate = 0.06, double shipping = 3.50) {
	return base_cost += (base_cost * tax_rate) + shipping;
}
void greeting(std::string name, std::string prefix = "Mr.", std::string suffix = "") {
	cout<<"Hello " <<prefix + " " + name + " " + suffix<<endl;
}

void default_case_1() {

	double cost{ 0 };

	cost = calc_cost(100.0, 0.08, 4.25);

	cout << std::fixed << std::setprecision(2);
	cout << "Cost is: " << cost << endl;

	cost = calc_cost(100.0, 0.08);
	cout << "Cost is: " << cost << endl;
	
	cost = calc_cost(200.0);
	cout << "Cost is: " << cost << endl;

	cost = calc_cost();
	cout << "Cost is: " << cost << endl;
}
void default_case_2() {
	greeting("Peter", "Mr.", "M.D");
	greeting("James", "Mr.");
	greeting("Frank");
}

void print(int);
void print(double);
void print(std::string);
void print(char);

void print(int num) {
	cout << "Int type was printed: " << num << endl;
}
void print(double num) {
	cout << "Double type was printed: " << num << endl;
}
void print(std::string s) {
	cout << "String type was printed: " << s << endl;
}
void print(char c) {
	cout << "Char type was printed: " << c << endl;
}

void overloading_case_1() {
	print(1);
	print(2.71);
	print("My String");
	print("Char type");
	
}

void print_array(const int[], size_t);
void set_array(int[], size_t, int=0);

void print_array(const int arr[], size_t size) {
	for (size_t i{ 0 }; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
void set_array(int arr[], size_t size, int value) {
	for (size_t i{ 0 }; i < size; ++i)
		arr[i] = value;
}

void passing_arrays_case_1() {
	int my_scores[]{ 100,99,98,75,51 };

	print_array(my_scores,5);

	set_array(my_scores, 5);
	print_array(my_scores, 5);
	
	set_array(my_scores, 5, 6);
	print_array(my_scores, 5);
}


void pass_by_ref_1(int&);
void pass_by_ref_2(std::string&);

void pass_by_ref_1(int& n) {
	n = n * n;
}
void pass_by_ref_2(std::string& s) {
	s = "value after";
}

void pass_by_reference_case_1() {

	int n{ 25 };
	cout << "Value before: " << n << endl;
	pass_by_ref_1(n);
	cout << "Value after: " << n<< endl;

	cout << "---------------------------\n";

	std::string s{ "(string before)" };
	cout << "Value before: " << s << endl;
	pass_by_ref_2(s);
	cout << "Value after: " << s<< endl;
}
