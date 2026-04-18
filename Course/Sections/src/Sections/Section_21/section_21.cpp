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

	auto change_person1() { return[this](string new_name, int new_age) {name = new_name; age = new_age; };}
	auto change_person2() { return[=](string new_name, int new_age) {name = new_name; age = new_age; };}
	auto change_person3() { return[&](string new_name, int new_age) {name = new_name; age = new_age; };}
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

int global_x{ 1000 };

void statefull_lambda_test1() {
	cout << "---Test1 -------------------------------------------" << endl;

	int local_x{ 100 };

	auto l = [local_x]() {
		cout << local_x << endl;
		cout << global_x << endl;
		};
	l();
} 

void statefull_lambda_test2() {
	cout << "---Test2 -------------------------------------------" << endl;

	int x{ 100 };

	auto l = [x]() mutable { //тут створено клас з приватним полем x, 
							 //і тому всі наступні манупіляцї над l(),
							 //матимуть прямий вплив на CompilerGeneratedName.x
		x += 100;
		cout << x << endl;
		};

	l();
	cout << x << endl;

	l();
	cout << x << endl;
}

void statefull_lambda_test3() {
	cout << "---Test3 -------------------------------------------" << endl;

	int x{ 100 };

	auto l = [&x]()mutable {
		x += 100;
		cout << x << endl;
		};

	l();
	cout << x << endl;
}

void statefull_lambda_test4() {
	cout << "---Test4 -------------------------------------------" << endl;

	int x{ 100 };
	int y{ 200 };
	int z{ 300 };

	auto l = [=]() mutable {
		x += 100;
		y += 100;
		cout << x << endl;
		cout << y << endl;
		cout << z << endl;
	};

	l();

	cout << "\n";
	cout << x << endl;
	cout << y << endl;
	cout << z << endl;
}

void statefull_lambda_test5() {
	cout << "---Test5 -------------------------------------------" << endl;

	int x{ 100 };
	int y{ 200 };
	int z{ 300 };

	auto l = [&]() {
		x += 100;
		y += 100;
		z += 100;
		cout << x << endl;
		cout << y << endl;
		cout << z << endl;
		};

	l();

	cout << "\n";
	cout << x << endl;
	cout << y << endl;
	cout << z << endl;
}

void statefull_lambda_test6() {
	cout << "---Test6 -------------------------------------------" << endl;

	int x{ 100 };
	int y{ 200 };
	int z{ 300 };

	auto l = [=,&y]() mutable {
		x += 100;
		y += 100;
		z += 100;
		cout << x << endl;
		cout << y << endl;
		cout << z << endl;
		};

	l();

	cout << "\n";
	cout << x << endl;
	cout << y << endl;
	cout << z << endl;
}

void statefull_lambda_test7() {
	cout << "---Test7 -------------------------------------------" << endl;

	int x{ 100 };
	int y{ 200 };
	int z{ 300 };

	auto l = [&,x,z]() mutable {
		x += 100;
		y += 100;
		z += 100;
		cout << x << endl;
		cout << y << endl;
		cout << z << endl;
		};

	l();

	cout << "\n";
	cout << x << endl;
	cout << y << endl;
	cout << z << endl;
}

void statefull_lambda_test8() {
	cout << "---Test8 -------------------------------------------" << endl;

	Lambda_Person person("Larry", 18);
	cout << person << endl;

	//[this]
	auto change_person1 = person.change_person1();
	change_person1("Moe", 30);
	cout << person << endl;

	//[=], але лише для С++20
	auto change_person2 = person.change_person2();
	change_person2("Curly", 25);
	cout << person << endl;

	//[&]
	auto change_person3 = person.change_person3();
	change_person3("Frank", 34);
	cout << person << endl;
}

class Lambda {
private:
	int y;
public:
	Lambda(int y) : y{ y } {};

	void operator()(int x)const {
		cout << x + y << endl;
	};
};

void statefull_lambda_test9() {
	cout << "---Test9 -------------------------------------------" << endl;

	int y{ 100 };

	Lambda lambda1(y);

	auto lambda2 = [y](int x) {cout << x + y << endl; };

	lambda1(200);
	lambda2(200);
}

class People {
	std::vector<Lambda_Person> people;
	int max_people;
public:
	People(int max = 10) :max_people(max) {}
	People(const People& p) = default;

	void add(string name, int age) {
		people.emplace_back(name, age);
	}
	void set_max_people(int max) {
		max_people = max;
	}
	int get_max_people() const {
		return max_people;
	}

	std::vector<Lambda_Person> get_people(int max_age) {
		std::vector<Lambda_Person> result;
		int count{ 0 };
		std::copy_if(people.begin(),
			people.end(),
			std::back_inserter(result),
			[this, &count, max_age](const Lambda_Person& p) {return p.get_age() > max_age && ++count <= max_people; });

		return result;
	}
};

void statefull_lambda_test10() {
	cout << "---Test10 -------------------------------------------" << endl;

	People friends;
	friends.add("Larry",18 );
	friends.add("Curly", 25);
	friends.add("Moe",35 );
	friends.add("Frank",28 );
	friends.add("James",65 );

	auto result = friends.get_people(17);

	cout << endl;
	for (const auto& p : result)
		cout << p << endl;

	friends.set_max_people(3);

	result = friends.get_people(17);

	cout << endl;
	for (const auto& p : result)
		cout << p << endl;

	result = friends.get_people(50);

	cout << endl;
	for (const auto& p : result)
		cout << p << endl;
}

void lambda_case_4() {
	statefull_lambda_test1();
	statefull_lambda_test2();
	statefull_lambda_test3();
	statefull_lambda_test4();
	statefull_lambda_test5();
	statefull_lambda_test6();
	statefull_lambda_test7();
	statefull_lambda_test8();
	statefull_lambda_test9();
	statefull_lambda_test10();
}

void lambda_stl_test1() {
	cout << "---Test1 -------------------------------------------" << endl;

	std::vector<int> nums{ 10,20,30,40,50 };

	std::for_each(nums.begin(),nums.end(), [](int num) {
		cout << num << " ";
		});
	cout << endl;

	std::for_each(nums.begin(), nums.end(), [](int num) {
		cout << num * num<< " ";
		});

	cout << endl;
}

void lambda_stl_test2() {
	cout << "\n---Test2 -------------------------------------------" << endl;

	struct Point
	{
		int x;
		int y;
	};

	Point p1{ 1,2 };
	Point p2{ 4,3 };
	Point p3{ 3,5 };
	Point p4{ 3,1 };

	std::vector<Point> triangle1{ p1,p2,p3 };
	std::vector<Point> triangle2{ p2,p3,p1 };
	std::vector<Point> triangle3{ p1,p2,p4 };

	if (std::is_permutation(triangle1.begin(), triangle1.end(), triangle2.begin(), [](Point lhs, Point rhs) {
		return lhs.x == rhs.x && lhs.y == rhs.y;
		})
		)
		cout << "Triange1 and Triangle2 are equivalent!" << endl;
	else
		cout << "Triange1 and Triangle2 are not equivalent!" << endl;

	if (std::is_permutation(triangle1.begin(), triangle1.end(), triangle3.begin(), [](Point lhs, Point rhs) {
		return lhs.x == rhs.x && lhs.y == rhs.y;
		})
		)
		cout << "Triange1 and Triangle3 are equivalent!" << endl;
	else
		cout << "Triange1 and Triangle3 are not equivalent!" << endl;
}

void lambda_stl_test3() {
	cout << "\n---Test3 -------------------------------------------" << endl;

	std::vector<int> test_scores{ 93,88,75,68,65 };
	int bonus_points{ 5 };

	std::transform(test_scores.begin(), test_scores.end(), test_scores.begin(), [bonus_points](int score) {
		return score += bonus_points;
		});

	for (int score : test_scores)
		cout << score << " ";
	cout << endl;
}

void lambda_stl_test4() {
	cout << "\n---Test4 -------------------------------------------" << endl;

	std::vector<int> nums{ 1,2,3,4,5 };

	for (int num : nums)
		cout << num << " ";

	cout << endl;

	nums.erase(std::remove_if(nums.begin(), nums.end(), [](int num) {
		return num % 2 == 0;
		}),
		nums.end());

	for (int num : nums)
		cout << num << " ";

	cout << endl;

	nums.erase(std::remove_if(nums.begin(), nums.end(), [](int num) {
		return num % 2 != 0;
		}),
		nums.end());

	for (int num : nums)
		cout << num << " ";

	cout << endl;
}

void lambda_stl_test5() {
	cout << "\n---Test5 -------------------------------------------" << endl;

	Lambda_Person person1("Larry", 18);
	Lambda_Person person2("Moe", 30);
	Lambda_Person person3("Curly", 25);

	std::vector<Lambda_Person> people{ person1,person2,person3 };

	std::sort(people.begin(), people.end(), [](Lambda_Person lhs, Lambda_Person rhs) {
		return lhs.get_name() < rhs.get_name();
		});

	for (auto person : people)
		cout << person << endl;

	cout << endl;

	std::sort(people.begin(), people.end(), [](Lambda_Person lhs, Lambda_Person rhs) {
		return lhs.get_age() > rhs.get_age();
		});

	for (auto person : people)
		cout << person << endl;
}

bool in_between(const std::vector<int>& nums, int start_value, int end_value) {
	bool result{ false };

	result = std::all_of(nums.begin(), nums.end(), [start_value, end_value](int value) {
		return value >= start_value && value <= end_value;
		});
	return result;
}

void lambda_stl_test6() {
	cout << "\n---Test6 -------------------------------------------" << endl;

	cout << std::boolalpha;

	std::vector<int> nums(10);
	std::iota(nums.begin(), nums.end(), 1);

	for (int num : nums)
		cout << num << " ";

	cout << endl;

	cout << in_between(nums, 50,60 ) << endl;
	cout << in_between(nums, 1,10 ) << endl;
	cout << in_between(nums, 5,7 ) << endl;
	cout << in_between(nums, 0,11 ) << endl;
}

class Password_Validator1 {
private:
	char restricted_symbol{ '$' };
public:
	bool is_valid(string password) {
		return std::all_of(password.begin(), password.end(), [this](char character) {
			return character != restricted_symbol;
			});
	}
};

class Password_Validator2 {
private:
	std::vector<char> restricted_symbols{ '!','$','+'};
public:
	bool is_valid(string password) {
		return std::all_of(password.begin(), password.end(), [this](char character) {
			return std::none_of(restricted_symbols.begin(), restricted_symbols.end(), [character](char symbol) {
				return character == symbol; }); });
	}
};

void lambda_stl_test7() {
	cout << "\n---Test7 -------------------------------------------" << endl;

	string password{ "holywood1$" };
	Password_Validator1 pv1;
	Password_Validator2 pv2;

	if (pv1.is_valid(password))
		cout << "The password " << password << " is valid!" << endl;
	else
		cout << "The password " << password << " is not valid!" << endl;

	password = "hollywood1";
	if (pv1.is_valid(password))
		cout << "The password " << password << " is valid!" << endl;
	else
		cout << "The password " << password << " is not valid!" << endl;

	cout << endl;

	password = "C++Rocks!";
	if (pv2.is_valid(password))
		cout << "The password " << password << " is valid!" << endl;
	else
		cout << "The password " << password << " is not valid!" << endl;

	password = "CPlusPlusRocks!";
	if (pv2.is_valid(password))
		cout << "The password " << password << " is valid!" << endl;
	else
		cout << "The password " << password << " is not valid!" << endl;

	password = "CPlusPlusRocks";
	if (pv2.is_valid(password))
		cout << "The password " << password << " is valid!" << endl;
	else
		cout << "The password " << password << " is not valid!" << endl;
}

void lambda_case_5() {
	lambda_stl_test1();
	lambda_stl_test2();
	lambda_stl_test3();
	lambda_stl_test4();
	lambda_stl_test5();
	lambda_stl_test6();
	lambda_stl_test7();
}
