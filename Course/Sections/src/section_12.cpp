#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>
#include <string>

using std::cin;
using std::cout;
using std::endl;

void pointers_case_1() {

	int num{ 10 };
	cout << "Value of nums is: " << num << endl;
	cout << "sizeof of num is: " << sizeof num << endl;
	cout << "Address of num is: " << &num << endl;

	int* p{nullptr};
	cout << "\nValue of p is:" << p<<endl;
	cout << "Address of p is: " << &p << endl;
	cout << "sizeof of p is: " << sizeof p << endl;

	int* p1{ nullptr };
	double* p2{ nullptr };
	unsigned long long* p3{ nullptr };
	std::vector<std::string>* p4{ nullptr };
	std::string* p5{ nullptr };

	cout << "\nsizeof p1 is: " << sizeof p1 << endl;
	cout << "sizeof p2 is: " << sizeof p2 << endl;
	cout << "sizeof p3 is: " << sizeof p3 << endl;
	cout << "sizeof p4 is: " << sizeof p4 << endl;
	cout << "sizeof p5 is: " << sizeof p5 << endl;
}
void pointers_case_2() {

	int score{ 100 };
	int* score_ptr{ &score };

	cout << "score value is " << score << endl;
	cout << "score_ptr value is " << score_ptr << endl;
	cout << "dereferencing of score_ptr is " << *score_ptr << endl;
	*score_ptr = 200;
	cout << "dereferencing of score_ptr after new assignment is " << *score_ptr << endl;
	cout << "score value is " << score << endl;
}
void pointers_case_3() {

	double high_temp{ 100.7 };
	double low_temp{ 37.4 };

	double* temp_ptr{ &high_temp };

	cout << temp_ptr << endl;
	cout << *temp_ptr << endl;
	temp_ptr = &low_temp;
	cout << *temp_ptr << endl;
}
void pointers_case_4() 
{
	std::string name{ "Frank" };

	std::string* string_ptr{ &name };

	cout << *string_ptr << endl;

	name = "James";

	cout << *string_ptr << endl;
}
void pointers_case_5() {

	std::vector<std::string> stooges{ "Larry","Moe","Curly" };
	std::vector<std::string>* vector_ptr{ nullptr };

	vector_ptr = &stooges;

	cout << "First stooge: " << (*vector_ptr).at(0) << endl;

	cout << "Stooges: ";
	for (auto stooge : *vector_ptr)
		cout << stooge << " ";
	cout << endl;
}
void dynanmic_memory_allocation_case_1() {
	 
	int* int_ptr{ nullptr };

	int_ptr = new int;

	cout << int_ptr << endl;

	delete int_ptr;

	cout << int_ptr << endl;

}
void dynanmic_memory_allocation_case_2() {

	size_t size{ 0 };
	double* temp_ptr{ nullptr };

	cout << "How many temps?";
	cin >> size;

	temp_ptr = new double[size];

	cout << temp_ptr << endl;

	delete [] temp_ptr;
}
void relationship_between_arrays_pointers_case_1() {

	int scores[]{ 100,95,89 };

	cout << scores << endl;
	cout << *scores << endl;

	int* score_ptr{ scores };

	cout << score_ptr << endl;
	cout << *score_ptr << endl;
}
void relationship_between_arrays_pointers_case_2() {

	int scores[]{ 100,95,89 };

	int* score_ptr{ scores };

	cout << score_ptr << endl;
	cout << score_ptr + 1 << endl;
	cout << score_ptr + 2 << endl;
	cout << "------------------------\n";
	cout << *score_ptr << endl;
	cout << *score_ptr + 1 << endl;
	cout << *score_ptr + 2 << endl;
}
void relationship_between_arrays_pointers_case_3() {

	int array_name[]{ 1,2,3,4,5 };
	int* ptr_name{ array_name };

	cout << "Subscript Notation: ";
	for (size_t i{ 0 }; i < (sizeof array_name)/4; i++)
		cout << array_name[i] << " ";

	cout << "\nOffset(pointer) Notation: ";
	for (size_t i{ 0 }; i < 5; i++)
		cout << *(array_name + i) << " ";
	cout << endl;
}
void relationship_between_arrays_pointers_case_4() {

	int scores[]{ 100,95,89 };

	cout << "Value of scores: " << scores << endl;

	int* score_ptr{ scores };
	cout << "Value of score_ptr" << score_ptr << endl;

	cout << "\nArray subscript nottation --------------------------" << endl;
	cout << scores[0] << endl;
	cout << scores[1] << endl;
	cout << scores[2] << endl;

	cout << "\nPointer subscript notation ----------------------------" << endl;
	cout << score_ptr[0] << endl;
	cout << score_ptr[1] << endl;
	cout << score_ptr[2] << endl;

	cout << "\nPointer offset notation ----------------------------" << endl;
	cout << *score_ptr << endl;
	cout << *(score_ptr + 1) << endl;
	cout << *(score_ptr + 2) << endl;

	cout << "\nArray offset notation ----------------------------" << endl;
	cout << *scores << endl;
	cout << *(scores + 1) << endl;
	cout << *(scores + 2) << endl;
}
void pointer_arithmetic_case_1() {

	std::string s1{ "Frank" };
	std::string s2{ "Frank" };

	std::string* p1{ &s1 };
	std::string* p2{ &s2 };
	std::string* p3{ &s1 };

	cout << "p1 -> s1: " << p1<<endl;
	cout << "p2 -> s2: " << p2<<endl;
	cout << "p3 -> s1: " << p3<<endl;

	cout << (*p1 == *p2) << endl;
	cout << (*p1 == *p3) << endl;
}
void pointer_arithmetic_case_2() {

	int scores[]{ 100,95,89,68,-1 };
	int* score_ptr{ scores };

	while (*score_ptr != -1) {
		cout << *score_ptr << " ";
		score_ptr++;
	}

	cout << "\n------------------------------\n";

	score_ptr = scores; 
	while (*score_ptr != -1)
		cout << *score_ptr++ << " ";

}
void swapPointers(int* ptr1, int* ptr2) {
	int ptrt = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = ptrt;
}
void pointer_arithmetic_case_3() {
	int a{ 5 };
	int b{ 10 };

	int* ptrA = &a;
	int* ptrB = &b;

	cout << "Before swap\n" << "a: " << a << " b: " << b << endl;
	swapPointers(ptrA,ptrB);
	cout << "After swap\n" << "a: " << a<<" b: " << b << endl;

}
