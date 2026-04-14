#include "..\..\..\..\..\..\Course\Course\Sections\include\Sections\Section_20\section_20.h"
#define MAX(a,b) ((a>b)?a:b)
#define SQUARE(a) a*a

void stl_case_1() {
	vector<int> v{ 1,5,3 };

	cout << "\n-------------------------------------------\n";
	for (auto elem : v)
		cout << elem << " ";

	cout << "\n-------------------------------------------\n";

	std::sort(v.begin(), v.end());

	for (auto elem : v)
		cout << elem << " ";

	cout << "\n-------------------------------------------\n";

	std::reverse(v.begin(), v.end());

	for (auto elem : v)
		cout << elem << " ";

	cout << "\n-------------------------------------------\n";
	int sum{};
	sum = std::accumulate(v.begin(),v.end(),0);
	cout << sum;

	cout << "\n-------------------------------------------\n";
}

void stl_case_2() {
	cout << MAX(10, 20) << endl;
	cout << MAX(2.4, 3.5) << endl;
	cout << MAX('A', 'C') << endl;
	cout << MAX('A', 70) << endl;

	cout << SQUARE(4) << endl;
	cout << SQUARE(5) << endl;
}

template <typename T>
T max(T a, T b){
	return ((a > b) ? a : b);
}

template <typename T>
T min(T a, T b) {
	return ((a < b) ? a : b);
}

//template <typename T1,typename T2>
//void max(T1 a, T2 b) {
//	cout << (a > b) ? a << " " << b : b << " " << a << endl;
//}

template <typename T1,typename T2>
void func(T1 a, T2 b) {
	cout << a << " " << b << endl;
}

struct Person {
	string name;
	int age;
	bool operator<(const Person& rhs) const {
		return this->age < rhs.age;
	}
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
	os << p.name << " " << p.age;
	return os;
}

template <typename T>
void my_swap(T & a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

void stl_case_3() {
	int a{ 10 };
	int b{ 20 };
	
	double c{ 5.5 };
	double d{ 2.5 };

	int x{ 100 };
	int y{ 200 };

	string s1{ "s1 string" };
	string s2{ "s2 string" };

	cout << "=========================================\n";
	cout << "x before: " << x << " y before: " << y << endl;
	my_swap(x, y);
	cout << "x after: " << x << " y before: " << y << endl;

	cout << "s1 before: " << s1 << " s2 before: " << s2 << endl;
	my_swap(s1, s2);
	cout << "s1 after: " << s1 << " s2 before: " << s2 << endl;
	cout << "=========================================\n";
	cout << max<int>(a, b) << endl;
	cout << max(a, b) << endl;

	cout << max<double>(c, d) << endl;
	cout << max(c, d) << endl;

	cout << min<int>(2, 3) << endl;
	cout << min(2, 3) << endl;
	cout << min(12.5, 9.2) << endl;
	cout << "=========================================\n";

	func<int, int>(10, 20);
	func(10, 20);
	func<char, double>('A', 12.4);
	func('A', 12.4);
	func(1000, "Testing");
	func(2000, string{ "Testing" });
	cout << "=========================================\n";

	Person p1{ "Curly",10 };
	Person p2{ "Moe",30 };

	Person p3 = min(p1, p2);
	cout << p3.name << " is yonger" << endl;
	func(p1, p2);
	cout << "=========================================\n";
}

template <typename T>
class Item {
private:
	string name;
	T value;
public:
	Item(string name, T value)
		: name{ name }, value{ value }
	{}
	string get_name() const { return name; }
	T get_value() const { return value; }
};

template <typename T1,typename T2>
struct My_Pair {
	T1 first;
	T2 second;
};

void stl_case_4() {

	//Item<int> item1{ "Larry",1 };
	//Item<double> item2{ "House",1000.0 };
	//Item<string> item3{ "Larry","Boss"};
	//
	//std::vector<Item<int>> vec_item; 
	// 
	/////////////////////////////////////
	//
	//My_Pair <string, int> p1{ "Frank",100 };
	//My_Pair <int, double> p2{124,13.6};
	//
	//vector<My_Pair<int, double>> vec_p;
	//
	/////////////////////////////////////
	//
	//std::pair<string, int> p1{ "Frank",100 };
	//
	//cout << p1.first << " " << p1.second << endl;


	Item<int> item1{ "Frank",100 };
	cout << item1.get_name() << " " << item1.get_value() << endl;

	Item<string> item2{ "Frank","Professor"};
	cout << item2.get_name() << " " << item2.get_value() << endl;

	Item<Item<string>> item3{ "Frank",{"C++","Projessor"}};
	cout << item3.get_name() << " "
		<< item3.get_value().get_name()<<" "
		<<item3.get_value().get_value()<< endl;

	cout << "\n===================================================\n";
	std::vector<Item<double>> vec{};
	vec.push_back(Item<double>("Larry",100.0 ));
	vec.push_back(Item<double>("Moe",200.0 ));
	vec.push_back(Item<double>("Curly",300.0 ));

	for (const auto& item : vec) {
		cout << item.get_name() << " " << item.get_value() << endl;
	}

	cout << "\n===================================================\n";
	My_Pair <string, int> p1{ "Frank",100 };
	My_Pair <int, double> p2{124,13.6};

	cout << p1.first << " " << p1.second << endl;
	cout << p2.first << " " << p2.second << endl;

	cout << "\n===================================================\n";

}

template<typename T, int N>
class Array {
	int size{ N };
	T values[N];

	friend std::ostream& operator<<(std::ostream& os, const Array<T,N>& arr) {
		os << "[";
		for (const auto& val : arr.values)
			os << val << " ";
		os << "]" << endl;
		return os;
	}
public:
	Array() = default;
	Array(T init_val) {
		for (auto& item : values)
			item = init_val;
	}
	void fill(T val) {
		for (auto& item : values)
			item = val;
	}
	int get_size()const {
		return size;
	}
	//overloaded subscript operator for easy use
	T& operator[](int index) {
		return values[index];
	}
};

void stl_case_5() {
	cout << "===================================================\n";
	Array<int,5> nums;
	cout << "The size of nums is: " << nums.get_size() << endl;
	cout << nums << endl;
	cout << "===================================================\n";
	nums.fill(0);
	cout << "The size of nums is: " << nums.get_size() << endl;
	cout << nums << endl;
	cout << "===================================================\n";
	nums.fill(10);
	cout << nums << endl;
	cout << "===================================================\n";
	nums[0] = 1000;
	nums[3] = 2000;
	cout << nums << endl;
	cout << "===================================================\n";

	Array<double,100> nums2{ 1 };
	cout << "The size of nums is: " << nums2.get_size() << endl;
	cout << nums2 << endl;
	cout << "===================================================\n";

	Array<string, 10> strings{ "Frank" };
	cout << "The size of string is: " << strings.get_size() << endl;
	cout << strings << endl;
	strings[0] = string{ "Larry" };
	cout << strings << endl;
	strings.fill("X");
	cout << strings << endl;
	cout << "===================================================\n";

}

void stl_case_6() {
	vector<int> vec{ 1,2,3 };
	//vector<int>::iterator it = vec.begin();
	auto it = vec.begin();

	while (it != vec.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	for(auto it1 = vec.begin(); it1 != vec.end(); it1++) {
		cout << *it1 << " ";
	}

	vector<int>::reverse_iterator rev_it = vec.rbegin();

	while (rev_it != vec.rend()) {
		cout << *rev_it << " ";
		++rev_it;
	}

}

void display(const vector<int>& vec) {
	cout << "[ ";
	for (auto const& i : vec) {
		cout << i << " ";
	}
	cout << "]" << endl;
}

void test1() {
	cout << "\n================================================================" << endl;
	vector<int> nums1{ 1,2,3,4,5 };
	auto it = nums1.begin();
	cout << *it << endl;  //1

	it++;				  //2
	cout << *it << endl;

	it += 2;			  //4
	cout << *it << endl;
		
	it -= 2;			  //2
	cout << *it << endl;

	it = nums1.end() - 1;  //5
	cout << *it << endl;
}

void test2() {
	cout << "\n================================================================" << endl;
	vector<int> nums1{ 1,2,3,4,5 };
	vector<int>::iterator it = nums1.begin();

	while (it != nums1.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;

	it = nums1.begin();
	while (it != nums1.end()) {
		*it = 0;
		it++;
	}
	display(nums1);

}

void test3() {
	cout << "\n================================================================" << endl;
	vector<int> nums1{ 1,2,3,4,5 };
	
	vector<int>::const_iterator it1 = nums1.begin();
	//auto it1 = nums1.cbegin();

	while (it1 != nums1.end()) {
		cout << *it1 << " ";
		it1++;
	}

	while (it1 != nums1.end()) {
		//*it1 = 0; //Compiler error - read only
		it1++;
	}
}

void test4() {
	cout << "================================================================" << endl;
	vector<int> vec{ 1,2,3,4,5 };
	auto it1 = vec.rbegin();
	while (it1 != vec.rend()) {
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;

	//const reverse over a list
	cout << "\n================================================================" << endl;
	std::list<string> name{ "Larry","Moe","Curly" };
	auto it2 = name.crbegin();

	cout << *it2 << endl;
	it2++;
	cout << *it2 << endl;

	//iterator over a map
	cout << "\n================================================================" << endl;
	std::map<string, string> favorites{
		{"Frank","C++"},
		{"Bill","Java"},
		{"James","Haskel"}
	};
	auto it3 = favorites.begin();
	while (it3 != favorites.end()) {
		cout << it3->first << " : " << it3->second << endl;
		it3++;
	}
	cout << "\n================================================================" << endl;
}

void test5() {
	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	auto start = vec.begin() + 2;
	auto finish = vec.end() - 3;

	while (start != finish) {
		cout << *start << " ";
		start++;
	}
}

void stl_case_7() {

	//test1();
	//test2();
	//test3();
	//test4();
	test5();
}
