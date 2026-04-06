#include "..\..\..\..\..\..\Course\Course\Sections\include\Sections\Section_18\section_18.h"
#include "..\..\..\..\..\..\Course\Course\Sections\include\Sections\Section_16\Challenge\section_16_challenge.h"

//void exception_case_1(double total) {
void exception_case_1() {
	double sum{ 100 };
	double average{};
	double total{};

	try {
		if (total == 0)
			//throw 0;
			throw 0.0;
			throw 'c';
		average = sum / total;
	}
	catch (char& ex) {
		cout << "char handler: can't divide by zero" << endl;
		//cout << "so let's change total value" << endl;
		//cout << "enter new total: "; cin >> ex;
		//exception_case_1(ex);
	}
	catch (int& ex) {
		cout << "int handler: can't divide by zero" << endl;
	}
	catch (double& ex) {
		cout << "double handler: can't divide by zero" << endl;
	}
	cout << "program continues" << endl;

}

void exception_case_2() {
	int kilometers{};
	int litres{};
	double kilometers_per_litres{};

	cout << "Enter the km: ";
	cin >> kilometers;
	cout << "Enter the litres: ";
	cin >> litres;

	//if (litres != 0) {
	//	kilometers_per_litres = static_cast<double> (kilometers)/ litres;
	//	cout << "Result: " << kilometers_per_litres << endl;
	//}
	//else {
	//	std::cerr << "Sorry, can't divide by zero" << endl;
	//}

	try {
		if (litres == 0)
			throw 0;
		kilometers_per_litres = static_cast<double> (kilometers)/ litres;
		cout << "Result: " << kilometers_per_litres << endl;
	}
	catch (int& ex) {
		std::cerr << "Sorry, can't divide by zero" << endl;
	}
}

double calculcate_avg(int sum, int total) {
	if (total == 0)
		throw 0;
	return static_cast<double>(sum) / total;
}

void exception_case_3() {
	double average{};
	int sum{ 101 };
	int total{};

	try {
		average = calculcate_avg(sum, total);
		cout << average << endl;
	}
	catch (int& ex) {
		cout << "You can't divide by zero" << endl;
	}
}

double calculcate_mpg(int miles, int gallons) {
	if (gallons == 0)
		throw 0;
	if (miles < 0 || gallons < 0)
		throw string{ "Negative value error" };
	return static_cast<double>(miles) / gallons;
}

void exception_case_4() {
	double miles{};
	double gallons{};
	double mpg{};

	cout << "Enter miles: ";
	cin >> miles;
	cout << "Enter gallons: ";
	cin >> gallons;

	try {
		mpg = calculcate_mpg(miles, gallons);
		cout << "Result: " << mpg << endl;
	}
	catch (int& ex) {
		std::cerr << "Tried to divide by zero" << endl;
	}
	catch (string& ex) {
		std::cerr << ex << endl;
	} 
	catch (...) {
		std::cerr << "Uknown mistake" << endl;
	}

}

void func_a();
void func_b();
void func_c();

void func_a() {
	cout << "Starting func_a" << endl;
	func_b();
	cout << "Ending func_a" << endl;
}
void func_b() {
	cout << "Starting func_b" << endl;
	try {
		func_c();
	}
	catch (double& ex) {
		cout << "Caught error in func_b" << endl;
	}
	cout << "Ending func_b" << endl;
}
void func_c() {
	cout << "Starting func_c" << endl;
	throw 100;
	cout << "Ending func_c" << endl;
}

void exception_case_5() {
	cout << "Starting main" << endl;
	try {
		func_a();
	}
	catch (string& ex) {
		cout << "Caught error in main" << endl;
	}
	catch (...) {
		cout << "Uknown issue" << endl;
	}
	cout << "Finishing main" << endl;
}

class DivideByZeroException {
};

class NegativeValueException {
};

double calc_mpg(int m, int g) {
	if (g == 0)
		throw DivideByZeroException();
	if (m < 0 || g < 0)
		throw NegativeValueException();
	return static_cast<double>(m) / g;
}

void exception_case_6() {
	double miles{};
	double gallons{};
	double mpg{};

	cout << "Enter miles: ";
	cin >> miles;
	cout << "Enter gallons: ";
	cin >> gallons;

	try {
		mpg = calc_mpg(miles, gallons);
		cout << "Result: " << mpg << endl;
	}
	catch (const DivideByZeroException& ex) {
		std::cerr << "Sorry, you invoked DivideByZeroException" << endl;
	}
	catch (const NegativeValueException& ex) {
		std::cerr << "Sorry, you invoked NegativeValueException" << endl;
	}
	catch (...) {
		std::cerr << "Uknown mistake" << endl;
	}

}

//class IllegalBalanceExceptopn {
//public:
//	IllegalBalanceExceptopn() = default;
//	~IllegalBalanceExceptopn() = default;
//};

void exception_case_7() {
	try {
		std::unique_ptr<Acc_challenge_16> moes_acc = std::make_unique<Checking_challenge_16>("Moe", -10.0);
		cout << "moes_account" << std::endl;
	 }
	catch (const IllegalBalanceExceptopn& ex) {
		//std::cerr << "You've triggered IllegalBalanceExceptopn" << endl;
		//std::cerr << ex.Message() << endl; //just a Message() method
		std::cerr << ex.what() << endl; //std::exception.what() override
	} 
	cout << "Program completed successfully" << endl;
}

void section_18_challenge() {
	try {
		std::unique_ptr<Acc_challenge_16> moes_acc = std::make_unique<Checking_challenge_16>("Moe", 10.0);
		cout << "moes_account created" << std::endl;

		moes_acc->withdraw(1000);
		cout << "moes_account was withdrawed" << std::endl;
	}
	catch (const IllegalBalanceExceptopn& ex) {
		std::cerr << ex.what() << endl; //std::exception.what() override
	}
	catch (const InsufficientFundsException& ex) {
		std::cerr << ex.what() << endl;
	}
	cout << "Program completed successfully" << endl;
}
