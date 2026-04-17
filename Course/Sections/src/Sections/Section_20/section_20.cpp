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

class Person_Class {
	friend std::ostream& operator<<(std::ostream& os, const Person_Class& p);
	string name;
	int age;
public:
	//Person_Class() = default;
	Person_Class() :name{ "Unknown" }, age{ 0 } {};
	Person_Class(string name, int age)
		:name{ name }, age{ age } {}
	bool operator<(const Person_Class& rhs) const {
		return this->age < rhs.age;
	}
	bool operator==(const Person_Class& rhs)const {
		return (this->name == rhs.name && this->age == rhs.age);
	}
	string get_name() const { return name; }
};

std::ostream& operator<<(std::ostream& os, const Person_Class &p) {
	os << p.name << ": " << p.age;
	return os;
}

void find_test() {
	cout << "\n===========================================" << endl;

	vector<int> vec{ 1,2,3,4,5 };

	auto loc = std::find(begin(vec), end(vec), 7);

	if (loc != end(vec))
		cout << "Found the number: " << *loc << endl;
	else
		cout << "Couldn't find the number" << endl;

	std::list<Person_Class> players{
		{"Larry",18},
		{"Moe",20},
		{"Curly",21}
	};

	auto loc1 = std::find(players.begin(), players.end(), Person_Class{ "1Moe",20 });
	if (loc1 != players.end())
		cout << "Found " << loc1->get_name() << endl;
	else
		//cout << (*loc1).get_name() << " not found" << endl;
		//cout << loc1->get_name() << " not found" << endl;
		cout << "Not found" << endl;
}

void count_test() {
	cout << "\n=============================================" << endl;

	vector<int> vec{ 1,2,3,4,5,1,2,1 };

	int num = std::count(vec.begin(), vec.end(), -7);
	cout << num << " occurrences found" << endl;
}

void count_if_test() {
	cout << "\n=============================================" << endl;

	vector<int> vec{ 1,2,3,4,5,1,2,1,100,1,1,1,7 };

	int num = std::count_if(vec.begin(), vec.end(), [](int x) {return x % 2 == 0; });
	cout <<" " << num << " even numbers found" << endl;

	num = std::count_if(vec.begin(), vec.end(), [](int x) {return x % 2 != 0; });
	cout << " " << num << " odd numbers found" << endl;

	num = std::count_if(vec.begin(), vec.end(), [](int x) {return x >= 5; });
	cout << " " << num << " elemens in vec are >= 5" << endl;
}

void replace_test() {
	cout << "\n=============================================" << endl;

	vector<int> vec{ 1,2,3,4,5,1,2,1,100,1,1,1,7 };

	for (auto i : vec) {
		cout << i << " ";
	}
	cout << endl;

	std::replace(vec.begin(), vec.end(), 1 ,100);
	for (auto i : vec) {
		cout << i << " ";
	}
	cout << endl;
}

void all_of_test() {
	cout << "\n=============================================" << endl;

	vector<int> vec{ 1,2,3,4,5,1,2,1,0,1,1,1,7 };

	if (std::all_of(vec.begin(), vec.end(), [](int x) {return x > 10;}))
		cout << "All the elements are > 10" << endl;
	else
		cout << "Not all of the elements are > 10" << endl;

	if (std::all_of(vec.begin(), vec.end(), [](int x) {return x < 20; }))
		cout << "All the elements are < 20" << endl;
	else
		cout << "Not all of the elements are < 20" << endl;
}

void string_transform_test() {
	cout << "\n=============================================" << endl;

	string str1{ "This is a test" };
	cout << "Before transform: " << str1 << endl;
	std::transform(str1.begin(), str1.end(),str1.begin(), ::toupper);
	cout << "After transform: " << str1 << endl;

}

void stl_case_8() {
	//cout << "\n=============================================" << endl;

	//vector<int> vec{ 1,2,3,4,5,1,2,1,100,1,1,1,7 };
	//find_test();
	//count_test();
	//count_if_test();
	//replace_test();
	//all_of_test();
	string_transform_test();
}

void array_display(const std::array<int, 5>& arr) {
	cout << "[ ";
	for (auto const& i : arr) {
		cout << i << " ";
	}
	cout << "]" << endl;
}

void array_test1() {
	cout << "\nTest1 ===========================================" << endl;
	std::array<int, 5> arr1{1, 2, 3, 4, 5};
	std::array<int, 5> arr2;

	array_display(arr1);
	array_display(arr2);

	arr2 = { 10,20,30,40,5 };

	array_display(arr1);
	array_display(arr2);
	
	cout << "Size of arr1 is: " << arr1.size() << endl;
	cout << "Size of arr2 is: " << arr2.size() << endl;

	arr1[0] = 1000;
	arr1.at(1) = 2000;
	array_display(arr1);

	cout << "Front of arr2: " << arr2.front() << endl;
	cout << "Back of arr2: " << arr2.back() << endl;
}

void array_test2() {
	cout << "\nTest2 ===========================================" << endl;

	std::array<int, 5> arr1{ 1, 2, 3, 4, 5 };
	std::array<int, 5> arr2{ 10, 20, 30, 40, 50 };

	array_display(arr1);
	array_display(arr2);

	arr1.fill(0);
	
	array_display(arr1);
	array_display(arr2);

	arr1.swap(arr2);

	array_display(arr1);
	array_display(arr2);
}

void array_test3() {
	cout << "\nTest3 ===========================================" << endl;
	
	std::array<int, 5> arr1{ 1, 2, 3, 4, 5 };

	int* ptr = arr1.data();
	cout << ptr << endl;
	*ptr = 100000;

	array_display(arr1);
}

void array_test4() {
	cout << "\nTest4 ===========================================" << endl;
	
	std::array<int, 5> arr1{ 2, 1, 4, 5, 3 };

	array_display(arr1);

	std::sort(arr1.begin(), arr1.end());
	array_display(arr1);
}

void array_test5() {
	cout << "\nTest5 ===========================================" << endl;

	std::array<int, 5> arr1{ 2, 1, 4, 5, 3 };

	std::array<int, 5>::iterator min_num = std::min_element(arr1.begin(), arr1.end());
	auto max_num = std::max_element(arr1.begin(), arr1.end());
	cout << "min: " << *min_num << " , max: " << *max_num << endl;
}

void array_test6() {
	cout << "\nTest6 ===========================================" << endl;

	std::array<int, 5> arr1{ 2, 1, 4, 4, 3 };

	auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());
	if (adjacent != arr1.end())
		cout << "Adjacent element found with value: " << *adjacent << endl;
	else
		cout << "No adjacent elements found" << endl;
}

void array_test7() {
	cout << "\nTest7 ===========================================" << endl;

	std::array<int, 5> arr1{ 1,2,3,4,5 };

	int sum = std::accumulate(arr1.begin(), arr1.end(), 0);
	cout << "Sum of the elements in arr1 is: " << sum << endl;
}

void array_test8() {
	cout << "\nTest8 ===========================================" << endl;

	std::array<int, 10> arr1{ 1,2,3,1,2,3,3,3,3,3 };

	int count = std::count(arr1.begin(), arr1.end(), 3);
	cout << "Found 3: " << count << " times" << endl;
}

void array_test9() {
	cout << "\nTest9 ===========================================" << endl;

	std::array<int, 10> arr1{ 1,2,3,50,60,70,80,200,300,400 };

	int count = std::count_if(arr1.begin(), arr1.end(),
		[](int x) {return x > 10 && x < 200; });
	cout << "Found " << count << " matches" << endl;
}

void stl_case_9() {
	array_test1();
	array_test2();
	array_test3();
	array_test4();
	array_test5();
	array_test6();
	array_test7();
	array_test8();
	array_test9();
}

//void vector_display(const std::vector<int>& arr) {
//	cout << "[ ";
//	for (auto const& i : arr) {
//		cout << i << " ";
//	}
//	cout << "]" << endl;
//}

void lambda_vector_display(const vector<int>& vec) {
	cout << "[ ";
	std::for_each(vec.begin(), vec.end(),
		[](int x) {cout << x << " "; });
	cout << "]" << endl;
}

template<typename T>
void vector_display(const std::vector<T>& vec) {
	cout << "[ ";
	for (const auto& elem : vec)
		cout << elem << " ";
	cout << "]" << endl;
}

void vector_test1() {
	cout << "\nTest1 ===========================================" << endl;

	vector<int> vec{ 1,2,3,4,5 };
	vector_display(vec);

	vec = { 2,4,5,6 };
	lambda_vector_display(vec);

	vector<int> vec1(10, 100);
	vector_display(vec1);
}

void vector_test2() {
	cout << "\nTest2 ===========================================" << endl;

	vector<int> vec{ 1,2,3,4,5 };

	vector_display(vec);
	cout << "\nvec size: " << vec.size() << endl;
	cout << "vec max size: " << vec.max_size() << endl;
	cout << "vec capacity: " << vec.capacity() << endl;
	
	vec.push_back(6);
	vector_display(vec);
	cout << "\nvec size: " << vec.size() << endl;
	cout << "vec max size: " << vec.max_size() << endl;
	cout << "vec capacity: " << vec.capacity() << endl;

	vec.shrink_to_fit();
	vector_display(vec);
	cout << "\nvec size: " << vec.size() << endl;
	cout << "vec max size: " << vec.max_size() << endl;
	cout << "vec capacity: " << vec.capacity() << endl;

	vec.reserve(100);
	vector_display(vec);
	cout << "\nvec size: " << vec.size() << endl;
	cout << "vec max size: " << vec.max_size() << endl;
	cout << "vec capacity: " << vec.capacity() << endl;

}

void vector_test3() {
	cout << "\nTest3 ===========================================" << endl;

	vector<int> vec{ 1,2,3,4,5 };
	vector_display(vec);

	vec[0] = 100;
	vec.at(1) = 100;

	display(vec);
}

void vector_test4() {
	cout << "\nTest4 ===========================================" << endl;

	vector<Person_Class> stooges;

	Person_Class p1{ "Larry",18 };
	vector_display(stooges);
	
	stooges.push_back(p1);
	vector_display(stooges);

	stooges.push_back(Person_Class{ "Moe",25 });
	vector_display(stooges);

	stooges.emplace_back("Curly", 30);
	vector_display(stooges);
}

void vector_test5() {
	cout << "\nTest5 ===========================================" << endl;

	vector<Person_Class> stooges{
		{"Larry",8},
		{"Moe",12},
		{"Curly",5}
	};

	vector_display(stooges);
	cout << "\nFront: " << stooges.front() << endl;
	cout << "Back: " << stooges.back() << endl;

	stooges.pop_back();
	vector_display(stooges);
}

void vector_test6() {
	cout << "\nTest6 ===========================================" << endl;

	vector<int> vec{ 1,2,3,4,5 };
	vector_display(vec);
	
	vec.clear();
	vector_display(vec);

	vec = { 1,2,3,4,5,6,7,8,9,10 };
	vector_display(vec);
	vec.erase(vec.begin(), vec.begin() + 2);
	vector_display(vec);
	
	vec = { 1,2,3,4,5,6,7,8,9,10 };
	auto it = vec.begin();
	while (it != vec.end()) {
		if (*it % 2 == 0)
			it = vec.erase(it);
			//vec.erase(it);
		else
			it++;
	}
	vector_display(vec);
}

void vector_test7() {
	cout << "\nTest7 ===========================================" << endl;

	vector<int> vec1{ 1,2,3,4,5 };
	vector<int> vec2{ 10,20,30,40,50 };

	vector_display(vec1);
	vector_display(vec2);
	cout << endl;

	vec2.swap(vec1);
	vector_display(vec1);
	vector_display(vec2);
}

void vector_test8() {
	cout << "\nTest8 ===========================================" << endl;

	vector<int> vec1{ 1,21,3,40,12 };

	vector_display(vec1);
	std::sort(vec1.begin(), vec1.end());
	vector_display(vec1);
}

void vector_test9() {
	cout << "\nTest9 ===========================================" << endl;

	vector<int> vec1{ 1,2,3,4,5 };
	vector<int> vec2{ 10,20 };

	vector_display(vec1);
	vector_display(vec2);
	cout << endl;

	std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
	vector_display(vec1);
	vector_display(vec2);
	cout << endl;

	//Copy_if the element is even
	vec1 = { 1,2,3,4,5,6,7,8,9,10 };
	vec2 = { 10,20 };
	vector_display(vec1);
	vector_display(vec2);
	cout << endl;

	std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2),
		[](int x) {return x % 2 == 0; });
	vector_display(vec1);
	vector_display(vec2);
}

void vector_test10() {
	cout << "\nTest10 ===========================================" << endl;

	vector<int> vec1{1,2,3,4,5};
	vector<int> vec2{10,20,30,40,50};
	vector<int> vec3;

	std::transform(vec1.begin(), vec1.end(), vec2.begin(),
		std::back_inserter(vec3),
		[](int x, int y) {return x * y; });
	vector_display(vec3);
}

void vector_test11() {
	cout << "\nTest11 ===========================================" << endl;

	vector<int> vec1{1,2,3,4,5,6,7,8,9,10};
	vector<int> vec2{100,200,300,400};

	vector_display(vec1);
	vector_display(vec2);
	cout << endl;

	auto it = std::find(vec1.begin(), vec1.end(), 5);
	if (it != vec1.end()) {
		cout << "inserting..." << endl;
		vec1.insert(it, vec2.begin(), vec2.end());
	}
	else {
		cout << "Sorry, 5 not found" << endl;
	}
	vector_display(vec1);
}

void stl_case_10() {
	//std::vector<int> vec;
	//cout << vec.max_size();

	vector_test1();
	vector_test2();
	vector_test3();
	vector_test4();
	vector_test5();
	vector_test6();
	vector_test7();
	vector_test8();
	vector_test9();
	vector_test10();
	vector_test11();
}

template<typename T>
void deque_display(const std::deque<T>& d) {
	cout << " [ ";
	for (const auto& elem : d)
		cout << elem << " ";
	cout << "]" << endl;
}

void deque_test1() {
	cout << "\nTest 1 =======================================================" << endl;

	std::deque<int> d{ 1,2,3,4,5 };
	deque_display(d);

	d = { 2,4,5,6 };
	deque_display(d);

	std::deque<int> d1(10, 100);
	deque_display(d1);
	
	d[0] = 100;
	d.at(1) = 200;
	deque_display(d);
}

void deque_test2() {
	cout << "\nTest 2 =======================================================" << endl;
	
	std::deque<int> d{ 0,0,0 };
	deque_display(d);

	d.push_back(10);
	d.push_back(20);
	deque_display(d);

	d.push_front(100);
	d.push_front(200);
	deque_display(d);

	cout << "Front: " << d.front() << endl;
	cout << "Back : " << d.back() << endl;
	cout << "Size : " << d.size() << endl;

	d.pop_back();
	d.pop_front();
	deque_display(d);
}

void deque_test3() {
	cout << "\nTest 3 =======================================================" << endl;

	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	std::deque<int> d;

	for (const auto& elem : vec) {
		if (elem % 2 == 0)
			d.push_back(elem);
		else
			d.push_front(elem);
	}
	deque_display(d);
}

void deque_test4() {
	cout << "\nTest 4 =======================================================" << endl;

	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	std::deque<int> d;
	
	for (const auto& elem : vec) {
		d.push_front(elem);
	}
	deque_display(d);

	d.clear();

	for (const auto& elem : vec) {
		d.push_back(elem);
	}

	deque_display(d);
}

void deque_test5() {
	cout << "\nTest 5 =======================================================" << endl;

	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	std::deque<int> d;

	std::copy(vec.begin(), vec.end(), std::front_inserter(d));
	deque_display(d);

	d.clear();
	
	std::copy(vec.begin(), vec.end(), std::back_inserter(d));
	deque_display(d);
}

void stl_case_11() {
	
	deque_test1();
	deque_test2();
	deque_test3();
	deque_test4();
	deque_test5();
}

bool is_palindrome(const std::string& s) {

	std::deque<char> forward;
	std::deque<char> backward;

	for (auto& c : s) {
		if (std::isalpha(c)) {
			forward.push_back(toupper(c));
			backward.push_front(toupper(c));
		}
	}
	
	if (forward == backward)
		return true;
	else
		return false;
}

bool is_palindrome_proposed(const std::string& s) {
	std::deque<char> d;

	for (char c : s)
		if (std::isalpha(c))
			d.push_back(std::toupper(c));

	char c1{};
	char c2{};

	while (d.size() > 1) {
		c1 = d.front();
		c2 = d.back();
		d.pop_front();
		d.pop_back();
		if (c1 != c2)
			return false;
	}
	return true;
}

void section_20_challenge_1(){

	std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
		"avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
		"A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };

	cout << std::boolalpha;
	cout << std::setw(8) << std::left << "Result" << std::setw(8) << "String" << endl;
	for (const auto& s : test_strings) {
		cout << std::setw(8) << std::left<< is_palindrome(s) << s << endl;
	}
	cout << endl;

	cout << std::setw(8) << std::left << "Result" << std::setw(8) << "String" << endl;
	for (const auto& s : test_strings) {
		cout << std::setw(8) << std::left << is_palindrome_proposed(s) << s << endl;
	}
}

template<typename T>
void list_display(const std::list<T>& l) {
	cout << " [";
	for (const auto& elem : l)
		cout << elem << " ";
	cout << "]" << endl;
}

void list_test1() {
	cout << "\nTest 1 =======================================================" << endl;

	std::list<int> l1{ 1,2,3,4,5 };
	list_display(l1);

	std::list<string> l2;
	l2.push_back("Back");
	l2.push_front("Front");
	list_display(l2);

	std::list<int> l3;
	l3 = { 1,2,3,4,5,6,7,8,9,10 };
	list_display(l3);

	std::list<int> l4(10, 100);
	list_display(l4);
}

void list_test2() {
	cout << "\nTest 2 =======================================================" << endl;

	std::list<int> l{ 1,2,3,4,5,6,7,8,9,10 };
	list_display(l);
	cout << "Size: " << l.size() << endl;
	cout << "Front: " << l.front() << endl;
	cout << "Back: " << l.back() << endl;

	l.clear();
	list_display(l);
	cout << "Size: " << l.size() << endl;
}

void list_test3() {
	cout << "\nTest 3 =======================================================" << endl;

	std::list<int> l{ 1,2,3,4,5,6,7,8,9,10 };
	list_display(l);

	l.resize(5);
	list_display(l);

	l.resize(10);
	list_display(l);

	std::list<Person_Class> persons;
	persons.resize(5);
	list_display(persons);
}

void list_test4() {
	cout << "\nTest 4 =======================================================" << endl;

	std::list<int> l{ 1,2,3,4,5,6,7,8,9,10 };
	list_display(l);

	auto it = std::find(l.begin(), l.end(), 5);
	if (it != l.end()) {
		l.insert(it, 100);
	}
	list_display(l);

	std::list<int> l2{ 1000,2000,3000 };
	l.insert(it, l2.begin(), l2.end());
	list_display(l);

	std::advance(it, -4);	//point to the 100
	cout << *it << endl;

	l.erase(it);
	list_display(l); 
}

void list_test5() {
	cout << "\nTest 5 =======================================================" << endl;

	std::list<Person_Class> stooges{
		{"Larry",15},
		{"Moe",25},
		{"Curly",17}
	};

	list_display(stooges);
	string name;
	int age{};
	cout << "\nEnter the name of the next stooge: ";
	getline(cin, name);
	cout << "Enter their ages: ";
	cin >> age;

	stooges.emplace_back(name, age);
	list_display(stooges);

	//Insert Frank before Moe
	auto it = std::find(stooges.begin(), stooges.end(), Person_Class{ "Moe",25 });
	if (it != stooges.end())
		stooges.emplace(it, "Frank", 18);
	list_display(stooges);
}

void list_test6() {
	cout << "\nTest 6 =======================================================" << endl;

	std::list<Person_Class> stooges{
		{"Larry",15},
		{"Moe",25},
		{"Curly",17}
	};

	list_display(stooges);
	stooges.sort();
	list_display(stooges);
}

void stl_case_12() {
	list_test1();
	list_test2();
	list_test3();
	list_test4();
	list_test5();
	list_test6();
}

class Song {
	friend std::ostream& operator<<(std::ostream& os, const Song& s);
private:
	string name;
	string artist;
	int raiting;
public:
	Song() : name{ "No name" }, artist{ "No arstist" }, raiting{ 0 } {};
	Song(string name,string artist,int raiting) 
		: name{ name }, artist{ artist }, raiting{ raiting } {};

	string get_name() { return name; }
	string get_artist() { return artist; }
	int get_raiting() { return raiting; }

	bool operator<(const Song& rhs) const {
		return this->name < rhs.name;
	}
	bool operator==(const Song& rhs)const {
		return this->name == rhs.name;
	}
};

std::ostream& operator<<(std::ostream& os, const Song& s) {
	os << std::setw(20) << std::left << s.name
		<< std::setw(30) << std::left << s.artist
		<< std::setw(2) << std::left << s.raiting;
	return os;
}

void display_menu() {
	cout << "\nF - Play First Song" << endl;
	cout << "N - Play Next Song" << endl;
	cout << "P - Play Previous Song" << endl;
	cout << "A - Add and play a new Song at current location" << endl;
	cout << "L - List the current playlist" << endl;
	cout << "=============================================================" << endl;
	cout << "Enter a selection(Q to quit): ";
}

void play_current_song(const Song& song) {
	cout << "Playing:" << endl;
	cout << song << endl;
}

void playlist_display(const std::list<Song>& playlist, const Song& current_song) {
	for (auto &song : playlist) {
		cout << song << endl;
	}
	cout << "Current song:" << endl;
	cout << current_song << endl;
}

void section_20_challenge_2() {
	bool controller{ true };
	char selector{};

	string name;
	string artist;
	int raiting;

	std::list<Song> playlist{
		{"God's Plan","Drake",5},
		{"Never Be The Same","Camila Cabello",5},
		{"Pray For Me","The Weekend and K.Lamar",4},
		{"The Middle","Zedd, Maren Morris & Grey",5},
		{"Wait","Maroone 5",4},
		{"Whatever It Takes","Imagine Dragons",3}
	};

	std::list<Song>::iterator current_song = playlist.begin();

	cout << "=============================================================";
	do {
		display_menu();
		cin >> selector;

		switch (selector) {
			case 'F':
			case 'f':{
				cout << "Playing First Song" << endl;
				play_current_song(playlist.front());
				break;
			}
			case 'N':
			case 'n': {
				cout << "Playing Next Song" << endl;
				current_song++;
				if (current_song == playlist.end()) {
					cout << "Wrapping to start of playlist" << endl;
					current_song = playlist.begin();
				}
				play_current_song(*current_song);
				break;
			}
			case 'P':
			case 'p': {
				cout << "Playing Previous Song" << endl;
				if (current_song == playlist.begin()) {
					cout << "Wrapping to end of playlist" << endl;
					current_song = playlist.end();
				}
				current_song--;
				play_current_song(*current_song);
				break;
			}
			case 'A':
			case 'a': {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Adding and playing new song" << endl;
				cout << "Enter song name: "; getline(cin, name);
				cout << "Enter song artist: "; getline(cin,artist);
				cout << "Enter your raiting: "; cin >> raiting;
				playlist.insert(current_song, Song{ name,artist,raiting });
				current_song--;
				play_current_song(*current_song);

				//playlist.emplace_front(name, artist, raiting);
				//current_song = playlist.begin();
				//play_current_song(*current_song);

				break;
			}
			case 'L':
			case 'l': {
				cout << endl;
				playlist_display(playlist, *current_song);
				break;
			}
			case 'Q':
			case 'q': {
				controller = false;
				break;
				break;
			}
			default:{
				cout << "Please, enter valid option: ";
				cin >> selector;
				break;
			}
		}
	} while (controller);
	cout << "Thanks for listenign!" << endl;
}

template <typename T>
void set_display(const std::set<T>& s) {
	cout << " [";
	for (const auto& elem : s) {
		cout << elem << " ";
	}
	cout << "]" << endl;
}

void set_test1() {
	cout << "\nTest 1 =======================================================" << endl;

	std::set<int> s1{ 1,4,3,5,2 };
	set_display(s1);

	s1 = { 1,2,3,1,1,2,2,3,3,4,5 };
	set_display(s1);

	s1.insert(0);
	s1.insert(10);

	set_display(s1);

	if (s1.count(10))
		cout << "10 is in the set" << endl;
	else
		cout << "10 is NOT in the set" << endl;

	auto it = s1.find(5);
	if (it != s1.end())
		cout << "Found: " << *it << endl;

	s1.clear();

	set_display(s1);

}

void set_test2() {
	cout << "\nTest 2 =======================================================" << endl;

	std::set<Person_Class> stooges{
		{"Larry",1},
		{"Moe",2},
		{"Curly",3}
	};
	set_display(stooges);

	stooges.emplace("James", 50);
	set_display(stooges);

	stooges.emplace("Frank", 50);
	set_display(stooges);

	auto it = stooges.find(Person_Class{ "Moe",2 });
	if (it != stooges.end())
		stooges.erase(it);

	set_display(stooges);

	it = stooges.find(Person_Class("XXXX", 50));

	if (it != stooges.end())
		stooges.erase(it);
	set_display(stooges);

}

void set_test3() {
	cout << "\nTest 3 =======================================================" << endl;

	std::set<string> s{ "A","B","C" };
	set_display(s);

	auto result = s.insert("D");
	set_display(s);

	cout << std::boolalpha;
	cout << "first: " << *(result.first) << endl;
	cout << "second: " << result.second << endl;

	cout << endl;

	result = s.insert("A");
	set_display(s);

	cout << "first: " << *(result.first) << endl;
	cout << "second: " << result.second << endl;
}

void stl_case_13() {
	set_test1();
	set_test2();
	set_test3();
}
 
template<typename T1, typename T2>
void map_display(const std::map<T1, T2>& l) {
	cout << " [ ";
	for (const auto& elem : l)
		cout << elem.first << ":" << elem.second << " ";
	cout << "]" << endl;
}

void maps_display(const std::map<string, std::set<int>>& m) {
	cout << "[ ";
	for (const auto& elem : m) {
		cout << elem.first << ": [ ";
		for (const auto& set_elem : elem.second)
			cout << set_elem << " ";
		cout << "] ";
	}
	cout << "]" << endl;
}

void map_test1() {
	cout << "\nTest 1 =======================================================" << endl;

	std::map<string,int> m{
		{"Larry",3},
		{"Moe",1},
		{"Curly",2}
	};

	map_display(m);

	m.insert(std::pair<string, int>("Anna", 10));
	map_display(m);

	m.insert(std::make_pair("Joe", 5));
	map_display(m);

	m["Frank"] = 18;
	map_display(m);

	m["Frank"] += 10;
	map_display(m);

	m.erase("Frank"); 
	map_display(m);

	cout << "Count for Joe: " << m.count("Joe") << endl;
	cout << "Count for Frank: " << m.count("Frank") << endl;

	auto it = m.find("Larry");
	if (it != m.end())
		cout << "Found: " << it->first << ":" << it->second << endl;

	m.clear();

	map_display(m);
}
 
void map_test2() {
	cout << "\nTest 2 =======================================================" << endl;

	std::map<string, std::set<int>> grades{
		{"Larry",{100,90}},
		{"Moe",{94}},
		{"Curly",{80,90,100}}
	};

	maps_display(grades);

	grades["Larry"].insert(95);

	maps_display(grades);

	auto it = grades.find("Moe");
	if (it != grades.end()) {
		it->second.insert(1000);
	}

	maps_display(grades);
}

void stl_case_14() {
	map_test1();
	map_test2();
}

template<typename T1, typename T2>
void map_display_word_count(const std::map<T1, T2>& l) {
	cout << std::setw(15) << std::left << "Word";
	cout << std::setw(10) << std::left << "Count" << endl;
	cout << std::setw(25) << std::setfill('=') << "" << endl;
	cout << std::setfill(' ');
	for (const auto& elem : l)
		cout << std::setw(15) << std::left << elem.first
		<< std::setw(10) << std::left << elem.second
		<< endl;;
}

string clean_string(const string& s) {
	string result;
	for (char c : s) {
		if (c == '.' || c == ',' || c == ';' || c == ':')
			continue;
		else
			result += c;
	}
	return result;
}

void section_20_challenge_3_part_1() {
	std::ifstream in_file;
	std::ofstream out_file;
	string line;
	string word;

	std::map<string, int> word_count;

	in_file.open("../Course/Sections/src/Sections/Section_20/words.txt");

	if (!in_file)
		std::cerr << "Problem opening input file" << endl;

	cout << std::boolalpha;
	while (std::getline(in_file, line)) {
		std::stringstream ss(line);
		while (ss >> word) {
			word = clean_string(word);
			word_count[word]++;      // increment the count for the word in the map
		}
	}

	map_display_word_count(word_count);

	in_file.close();
}

void maps_display_word_occurances(const std::map<string, std::set<int>>& m) {
	cout << std::setw(15) << std::left << "Word";
	cout << std::setw(10) << std::left << "Occurences" << endl;
	cout << std::setw(25) << std::setfill('=') << "" << endl;
	cout << std::setfill(' ');
	for (const auto& elem : m) {
		cout << std::setw(15) << std::left << elem.first;
		cout << "[ ";
		for (const auto& set_elem : elem.second)
			cout << set_elem << " ";
		cout << "] ";
		cout << endl;
	}
	cout << endl;
}

void section_20_challenge_3_part_2() {
	std::ifstream in_file;
	std::ofstream out_file;
	string line;
	string word;
	int line_count{1};

	std::map<string, std::set<int>> word_occurances;

	in_file.open("../Course/Sections/src/Sections/Section_20/words.txt");

	if (!in_file)
		std::cerr << "Problem opening input file" << endl;

	cout << std::boolalpha;
	while (std::getline(in_file, line)) {
		
		std::stringstream ss(line);
		while (ss >> word) {
			word = clean_string(word);
			word_occurances[word].insert(line_count);      // increment the count for the word in the map
		}
		++line_count;
	}

	maps_display_word_occurances(word_occurances);

	in_file.close();
}

template<typename T>
void stack_display(std::stack<T> s) {
	cout << " [ ";
	while (!s.empty()) {
		T elem = s.top();
		s.pop();
		cout << elem << " ";
	}
	cout << "]" << endl;
}

void stl_case_15() {
	std::stack<int> s;
	std::stack<int,std::vector<int>> s1;
	std::stack<int,std::list<int>> s2;
	std::stack<int,std::deque<int>> s3;

	for (int i : {1, 2, 3, 4, 5})
		s.push(i);
	stack_display(s);

	s.push(100);
	stack_display(s);

	s.pop();
	s.pop();
	stack_display(s);

	while (!s.empty())
		s.pop();
	stack_display(s);

	cout << "Size: " << s.size() << endl;
	
	s.push(10);
	stack_display(s);
	
	s.top() = 100;
	stack_display(s);
}

template<typename T>
void queue_display(std::queue<T> q) {
	cout << " [ ";
	while (!q.empty()) {
		T elem = q.front();
		q.pop();
		cout << elem << " ";
	}
	cout << "]" << endl;
}

void stl_case_16() {
	
	std::queue<int> q;
	for (int i : {1, 2, 3, 4, 5})
		q.push(i);
	queue_display(q);
	cout << "Front: " << q.front() << endl;
	cout << "Back: " << q.back() << endl;

	q.push(100);
	queue_display(q);

	q.pop();
	q.pop();
	queue_display(q);

	while (!q.empty())
		q.pop();
	queue_display(q);

	cout << "Size: " << q.size() << endl;

	q.push(10);
	q.push(100);
	q.push(1000);
	queue_display(q);

	cout << "Front: " << q.front() << endl;
	cout << "Back: " << q.back() << endl;

	q.front() = 5;
	q.back() = 5000;

	queue_display(q);
	cout << "Front: " << q.front() << endl;
	cout << "Back: " << q.back() << endl;
}

bool is_palindrome_stack(const std::string& s) {

	std::stack<char> forward;
	std::stack<char> backward;

	for (auto& c : s) {
		if (std::isalpha(c)) {
			forward.push(toupper(c));
		}
	}

	string temp_s = s;
	std::reverse(temp_s.begin(), temp_s.end());

	for (auto& c : temp_s) {
		if (std::isalpha(c)) {
			backward.push(toupper(c));
		}
	}

	if (forward == backward)
		return true;
	else
		return false;
}

bool is_palindrome_stack_queue_proposed(const std::string& s) {
	
	std::stack<char> stk;
	std::queue<char> q;

	for(char c:s)
		if (std::isalpha(c)) {
			c = std::toupper(c);
			q.push(c);
			stk.push(c);
		}

	char c1{};
	char c2{};

	while (!q.empty()) {
		c1 = q.front();
		q.pop();
		c2 = stk.top();
		stk.pop();
		if (c1 != c2)
			return false;
	}

	return true;
}

bool is_palindrome_queue(const std::string& s) {
	std::queue<char> forward;
	std::queue<char> backward;

	for (auto& c : s) {
		if (std::isalpha(c)) {
			forward.push(toupper(c));
		}
	}

	string temp_s = s;
	std::reverse(temp_s.begin(), temp_s.end());

	for (auto& c : temp_s) {
		if (std::isalpha(c)) {
			backward.push(toupper(c));
		}
	}

	if (forward == backward)
		return true;
	else
		return false;
}

void section_20_challenge_4() {
	
	std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
		"avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
		"A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };

	cout << std::boolalpha;
	cout << "is_palindrome_stack" << endl;
	cout << std::setw(8) << std::left << "Result" << std::setw(8) << "String" << endl;
	for (const auto& s : test_strings) {
		cout << std::setw(8) << std::left << is_palindrome_stack(s) << s << endl;
	}
	cout << endl;

	cout << "is_palindrome_queue" << endl;
	cout << std::setw(8) << std::left << "Result" << std::setw(8) << "String" << endl;
	for (const auto& s : test_strings) {
		cout << std::setw(8) << std::left << is_palindrome_queue(s) << s << endl;
	}
	cout << endl;

	cout << "is_palindrome_stack_queue_proposed" << endl;
	cout << std::setw(8) << std::left << "Result" << std::setw(8) << "String" << endl;
	for (const auto& s : test_strings) {
		cout << std::setw(8) << std::left << is_palindrome_stack_queue_proposed(s) << s << endl;
	}
}

template<typename T>
void priority_queue_display(std::priority_queue<T> pq) {
	cout << "[ ";
	while (!pq.empty()) {
		T elem = pq.top();
		pq.pop();
		cout << elem << " ";
	}
	cout << "]" << endl;
}

void priority_queue_test1() {
	cout << "\nTest 1 =======================================================" << endl;

	std::priority_queue<int> pq;
	for (int i : {3, 5, 7, 12, 23, 12, 4, 100, 0, 3, 5, 7})
		pq.push(i);

	cout << "Size: " << pq.size() << endl;
	cout << "Top: " << pq.top() << endl;

	priority_queue_display(pq);
	pq.pop();
	priority_queue_display(pq);
}

void priority_queue_test2() {
	cout << "\nTest 2 =======================================================" << endl;

	std::priority_queue<Person_Class> pq;
	pq.push(Person_Class{ "A",10 });
	pq.push(Person_Class{ "B",100 });
	pq.push(Person_Class{ "C", 14});
	pq.push(Person_Class{ "D",18 });
	pq.push(Person_Class{ "E",7 });
	pq.push(Person_Class{ "F",27 });

	priority_queue_display(pq);
}

void stl_case_17() {
	priority_queue_test1();
	priority_queue_test2();
}
