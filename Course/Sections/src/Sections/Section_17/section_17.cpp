#include "..\..\..\..\..\Course\Sections\include\Sections\Section_17\section_17.h"
#include "..\..\..\..\..\Course\Sections\include\Sections\Section_16\Challenge\section_16_challenge.h"

void smart_pointers_case_1() {
	std::unique_ptr<int> p1{ new int {100} };
	
	cout << "Memory location: " << p1 << endl;
	cout << "p1 value: " << *p1 << endl;

	*p1 = 200;
	cout << "p1 value after reassigned: " << *p1 << endl;

	cout << ".get(): " << p1.get() << endl;
	cout << ".get() *value: " << *(p1.get()) << endl;

	p1.reset();
	cout << "p1.reset()(nullptr): " <<p1<< endl;
	//cout << "p1.reset() value: " <<*p1<< endl; //error

}

void smart_pointers_case_2() {
	vector<std::unique_ptr<int>> vec;

	std::unique_ptr<int> ptr{ new int{100} };

	//vec.push_back(ptr); //error

	vec.push_back(std::move(ptr));
}

void smart_pointers_case_3() {
	std::unique_ptr<int> p1 = std::make_unique<int>(100);
}

class Test;

void smart_pointers_case_4() {
	//Test *t = new Test{ 1000 };
	//delete t;

	//std::unique_ptr<Test> t1{ new Test{100} };
	//std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);

	//std::unique_ptr<Test> t3;
	//t3 =  std::move(t1);

	//if (!t1)
	//	cout << "t1 is nullptr" << endl;
	
	//cout << endl;


	std::unique_ptr<Acc_challenge_16> a1 = std::make_unique<Checking_challenge_16>("Moe", 5000);
	cout << *a1 << endl;

	a1->deposit(500);
	cout << *a1 << endl;

	vector<std::unique_ptr<Acc_challenge_16>> accounts;
	accounts.push_back(std::make_unique<Checking_challenge_16>("James", 1000));
	accounts.push_back(std::make_unique<Savings_challenge_16>("Billy", 4000));
	accounts.push_back(std::make_unique<Trust_challenge_16>("Bobby", 5000));

	for (const auto &acc : accounts)
		cout << *acc << endl;
}

void func(std::shared_ptr<Test>p) {
	cout << "Use count: " << p.use_count() << endl;
}

void shared_pointers_case_1() {
	//std::shared_ptr<int> p1{ new int{100} };
	//cout << "Use count: " << p1.use_count() << endl;

	//std::shared_ptr<int> p2{ p1 };
	//cout << "Use count: " << p1.use_count() << endl;

	//p1.reset();
	//cout << "Use count: " << p1.use_count() << endl;
	//cout << "Use count: " << p2.use_count() << endl;

	//cout << "\n===========================================================================" << endl;
	//std::shared_ptr<Test> ptr = std::make_shared<Test>(100);
	//func(ptr);
	//cout << "Use count: " << ptr.use_count() << endl;
	//{
	//	std::shared_ptr<Test> ptr1 = ptr;
	//	cout << "Use count: " << ptr.use_count() << endl;
	//	{
	//		std::shared_ptr<Test>ptr2 = ptr;
	//		cout << "Use count: " << ptr.use_count() << endl;
	//		ptr.reset();
	//	}
	//	cout << "Use count: " << ptr.use_count() << endl;
	//}
	//cout << "Use count: " << ptr.use_count() << endl;

	cout << "\n===========================================================================" << endl;
	std::shared_ptr<Acc_challenge_16> acc1 = std::make_shared<Trust_challenge_16>("Larry", 10000);
	std::shared_ptr<Acc_challenge_16> acc2 = std::make_shared<Checking_challenge_16>("Moe", 5000);
	std::shared_ptr<Acc_challenge_16> acc3 = std::make_shared<Savings_challenge_16>("Curly", 6000);

	vector<std::shared_ptr<Acc_challenge_16>> accounts;
	accounts.push_back(acc1);
	accounts.push_back(acc2);
	accounts.push_back(acc3);

	for (const auto& acc : accounts) {
		cout << *acc << endl;
		cout << "Use count: " << acc.use_count() << endl;
	}
	cout << "\n===========================================================================" << endl;

}

class B; //forward declaration

class A {
	std::shared_ptr<B> b_ptr;
public:
	void set_B(std::shared_ptr<B>& b) {
		b_ptr = b;
	}
	A() { cout << "A Constructor" << endl; }
	~A() { cout << "A Destructor" << endl; }
};

class B {
	//std::shared_ptr<A> a_ptr; //make weak to break the strong circular reference
	std::weak_ptr<A> a_ptr; //make weak to break the strong circular reference
public:
	void set_A(std::shared_ptr<A>& a) {
		a_ptr = a;
	}
	B() { cout << "B Constructor" << endl; }
	~B() { cout << "B Destructor" << endl; }
};

void weak_pointers_case_1() {
	std::shared_ptr<A> a = std::make_shared<A>();
	std::shared_ptr<B> b = std::make_shared<B>(); 

	a->set_B(b);
	b->set_A(a);
}

void my_deleter(Test* ptr) {
	cout << "In my_deleter custom deleter" << endl;
	delete ptr;
}

//void custom_deleters_case_1() {
//
//	//std::shared_ptr<Test> ptr{ new Test{},my_deleter };
//	std::shared_ptr<Test> ptr{ new Test{}};
//	cout << "======================" << endl;
//	std::shared_ptr<Test> ptr1(new Test{ 20 },
//		[](Test* ptr1) { //lambda
//			cout << "\tUsing my lambda deleter" << endl;
//			delete ptr1;
//		});
//}

class Test {
	friend std::ostream& operator<<(std::ostream & os, const Test & test);
private:
	int data;
public:
	Test() : data{ 0 } { cout << "Test constructor (" << data << ")" << endl; }
	Test(int data) :data{ data } { cout << "Test constructor (" << data << ")" << endl; }
	int get_data() const { return data; }
	~Test() { cout << "Test destructor (" << data << ")" << endl; }
};

std::ostream& operator<<(std::ostream& os, const Test& test) {
	os << "Test with data: " << test.data<<"\n";
	return os;
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
	//std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec; //not correct
	return std::make_unique<std::vector<std::shared_ptr<Test>>>(); 	//correct
}

void fill(vector<std::shared_ptr<Test>>& vec, int num) {
	for (size_t i{ 0 }; i < num; i++)
	{
		//std::shared_ptr<Test> el = std::make_shared <Test>(i);
		vec.push_back(std::make_shared<Test>(i*10));
	}
}

void display(const vector<std::shared_ptr<Test>>& vec) {
	for (auto& el : vec)
		cout << *el;
}

void section_17_challenge() {
	std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
	vec_ptr = make();
	cout << "How many data points do you want me to enter ";
	int num;
	cin >> num;
	cout << endl;
	fill(*vec_ptr, num);
	cout << endl;
	display(*vec_ptr);
}
