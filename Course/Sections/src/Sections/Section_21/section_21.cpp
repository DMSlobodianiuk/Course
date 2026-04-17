#include "..\..\..\include\Sections\Section_21\section_21.h"

// Class for funtion objects
struct Square_Functor {
	void operator()(int x) {
		cout << x * x << " ";
	}
};

template<typename T>
struct  Displayer {
	void operator() (const T& data) {
		cout << data << " ";
	}
};

class Multiplier {
private:
	int num{};
public:
	Multiplier(int n) :num{ n } {}
	int operator()(int n)const {
		return n * num;
	}
};

void lambda_case_1() {
	cout << "\nTest 1 ==================================" << endl;

	Square_Functor square;
	square(4); //square.operator()(4)

	Displayer<int> d1;
	Displayer<string> d2;

	d1(100);
	d2("Frank");

	cout << "\nTest 2 ==================================" << endl;

	std::vector<int> vec1{ 1,2,3,4,5 };
	std::vector<string> vec2{ "Larry","Moe","Curly" };

	std::for_each(vec1.begin(), vec1.end(), square);
	cout << endl;

	std::for_each(vec1.begin(), vec1.end(), Displayer<int>());
	cout << endl;

	std::for_each(vec1.begin(), vec1.end(), d1);
	cout << endl;

	std::for_each(vec2.begin(), vec2.end(), Displayer<string>());
	cout << endl;

	std::for_each(vec2.begin(), vec2.end(), d2);
	cout << endl;

	cout << "\nTest 3 ==================================" << endl;

	std::for_each(vec1.begin(), vec1.end(), [](int x) {cout << x * x << " "; });
	cout << endl;

	std::for_each(vec1.begin(), vec1.end(), [](int x) {cout << x * 10 << " "; });
	cout << endl;

	std::for_each(vec1.begin(), vec1.end(), [](int x) {cout << x  << " "; });
	cout << endl;

	std::for_each(vec2.begin(), vec2.end(), [](string s) {cout << s << " "; });
	cout << endl;

	cout << "\nTest 4 ==================================" << endl;

	Multiplier mult(100);
	vec1 = { 1,2,3,4 };

	std::transform(vec1.begin(), vec1.end(), vec1.begin(),mult);
	std::for_each(vec1.begin(), vec1.end(), d1);
	cout << endl;

	vec1 = { 1,2,3,4 };
	std::transform(vec1.begin(), vec1.end(),vec1.begin(), [](int x) {return x * 100; });
	std::for_each(vec1.begin(), vec1.end(), [](int x) {cout << x << " "; });
	cout << endl;
}

void lambda_case_2() {
	[]() {cout << "Hi" << endl; }();

	[](int x) {cout << x << endl; }(1);
	[](int x) {cout << x << endl; }(2);
	[](int x) {cout << x << endl; }(3);

	[](int x, int y) {cout << x + y << endl; }(1,2);
	[](int x, int y) {cout << x + y << endl; }(-7,5);
	[](int x, int y) {cout << x + y << endl; }(12,21);

	auto l = []() {cout << "Hi lambda" << endl;; };
	l();

	auto l1 = [](int x) {cout << x << endl ; };
	l1(10);
	l1(100);

	auto l2 = [](int x, int y) ->int {return x + y; };
	auto l3 = [](int x, int y){return x + y; };
	cout << l2(2, 3) << endl;
	cout << l3(10, 23) << endl;
}

class Lambda_Person {
	friend std::ostream& operator<<(std::ostream& os, const Lambda_Person& rhs);
private:
	string name;
	int age;
public:
	Lambda_Person(string name, int age) : name{ name }, age{ age } {};
	Lambda_Person(const Lambda_Person& p) :name{ p.name }, age{ p.age } {};
	~Lambda_Person() = default;

	string get_name() const { return name; }
	void set_name(string name) { this->name = name; }
	int get_age() const { return age; }
	void set_age(int age) { this->age = age; }
};

std::ostream &operator<<(std::ostream& os, const Lambda_Person& rhs) {
	os << "[ Person: " << rhs.name << " : " << rhs.age << " ]";
	return os;
}

void stateless_lambda_test1() {
	cout << "---Test1 -------------------------------------------" << endl;

	[]() {cout << "Hi" << endl; } ();

	[](int x) {cout << x << endl; }(100);

	[](int x, int y) {cout << x + y << endl; }(100, 200);
}

void stateless_lambda_test2() {
	cout << "---Test2 -------------------------------------------" << endl;

	auto l1 = []() {cout << "Hi" << endl; };
	l1();

	int num1{100};
	int num2{100};

	auto l2 = [](int x, int y) {cout << x + y << endl; };
	l2(10, 20);
	l2(num1, num2);

	auto l3 = [](int& x, int y) {
		cout << "x: " << x << " y: " << y << endl;
		x = 1000;
		y = 2000;
		};

	l3(num1, num2);
	cout << "num1: " << num1 << " num2: " << num2 << endl;
}

void stateless_lambda_test3() {
	cout << "---Test3 -------------------------------------------" << endl;

	Lambda_Person stooge{ "Larry",18 };
	cout << stooge << endl;

	auto l4 = [](Lambda_Person p) {
		cout << p << endl;
		};
	l4(stooge);

	auto l5 = [](const Lambda_Person& p) {
		cout << p << endl;
		};
	l5(stooge);

	auto l6 = [](Lambda_Person& p) {
		p.set_name("Frank");
		p.set_age(25);
		cout << p << endl;
		};
	l6(stooge);
	
	cout << stooge << endl;
}

void filter_vector(const std::vector<int>& vec, std::function<bool(int)> func) {
	cout << " [ ";
	for (int i : vec) {
		if (func(i))
			cout << i << " ";
	}
	cout << "]" << endl;
}

void stateless_lambda_test4() {
	cout << "---Test4 -------------------------------------------" << endl;

	std::vector<int> nums{ 10,20,30,40,50,60,70,80,90,100 };

	filter_vector(nums, [](int x) {return x > 50; });

	filter_vector(nums, [](int x) {return x <= 30; });
	
	filter_vector(nums, [](int x) {return x >= 30 && x<=60; });
}

auto make_lambda() {
	return []() {cout << "This is a lambda was made using the make_lambda function" << endl; };
}

void stateless_lambda_test5() {
	cout << "---Test5 -------------------------------------------" << endl;

	auto l5 = make_lambda();

	l5();
}

void stateless_lambda_test6() {
	cout << "---Test6 -------------------------------------------" << endl;

	auto l6 = [](auto x, auto y) {
		cout << "x: " << x << " y: " << y << endl;
		};

	l6(10,20 );
	l6(100.3,200 );
	l6(12.5,15.54 );

	l6(Lambda_Person("Larrr", 18), Lambda_Person("Curly", 22));
}

void stateless_lambda_test7() {
	cout << "---Test7 -------------------------------------------" << endl;

	std::vector<Lambda_Person> stooges{
		{"Larry",18},
		{"Moe",30},
		{"Curly",25}
	};

	//sort by name
	//std::sort(begin(stooges), end(stooges), [](const Lambda_Person& p1, const Lambda_Person& p2){
	std::sort(stooges.begin(), stooges.end(), [](const Lambda_Person& p1, const Lambda_Person& p2){
		return p1.get_name() < p2.get_name();
	});

	std::for_each(begin(stooges), end(stooges), [](const Lambda_Person& p) {
		cout << p << endl;
	});

	cout << endl;

	//sort by age
	std::sort(stooges.begin(), stooges.end(), [](const Lambda_Person& p1, const Lambda_Person& p2) {
	//std::sort(begin(stooges), end(stooges), [](const Lambda_Person& p1, const Lambda_Person& p2) {
		return p1.get_age() < p2.get_age();
	});

	std::for_each(begin(stooges), end(stooges), [](const Lambda_Person& p) {
		cout << p << endl;
	});

}

//Stateless lambda expressions
//[] - empty capture lists
void lambda_case_3() {
	stateless_lambda_test1();
	stateless_lambda_test2();
	stateless_lambda_test3();
	stateless_lambda_test4();
	stateless_lambda_test5();
	stateless_lambda_test6();
	stateless_lambda_test7();
}
