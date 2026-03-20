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

void double_data(int* int_ptr) {
	*int_ptr *= 2;
}
void pass_pointers_to_functions_case_1() {
	int value{ 10 };
	int* int_ptr{ nullptr };

	cout << "Value: " << value << endl;
	double_data(&value);
	cout << "Value: " << value << endl;

	cout << "\n---------------------------------\n";
	int_ptr = &value;
	double_data(int_ptr);
	cout << "Value: " << value << endl;

}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void pass_pointers_to_functions_case_2() {
	int x{ 100 }, y{ 200 };
	cout << "Before swap:\n";
	cout << "x: " << x << " y: " << y << endl;

	swap(&x, &y);

	cout << "\nAfter swap:\n";
	cout << "x: " << x << " y: " << y << endl;

}

int* largest_int(int* int_ptr1, int* int_ptr2) {
	if (*int_ptr1 > *int_ptr2)
		return int_ptr1;
	else
		return int_ptr2;
}
void returning_pointers_case_1() {
	int a{ 100 };
	int b{ 200 };

	int* largest_ptr{ nullptr };
	largest_ptr = largest_int(&a, &b);
	cout << *largest_ptr << endl;
}

int* create_array(size_t size, int init_value = 0) {
	int* new_storage{ nullptr };

	new_storage = new int[size];
	for (size_t i{ 0 }; i < size; i++)
		*(new_storage + 1) = init_value;
	return new_storage;
}
void returning_pointers_case_2() {

	int* my_array;

	my_array = create_array(100, 20);

	delete[] my_array;
}

void reverse_array(int* arr, int size) {
	int t{ 0 };

	for (size_t i{ 0 }; i < size / 2; i++) {
		t = *(arr + i);
		*(arr + i) = *(arr + size - i - 1);
		*(arr + size - i - 1) = t;
	}
}
void section_12_exercise_33() {

	int arr[] = { 1, 2, 3, 4, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	for (auto el : arr)
		cout << el << " ";
	cout << "size: " << size << "\n---------------------------\n";

	reverse_array(arr, size);
	for (auto el : arr)
		cout << el << " ";
	cout << "size: " << size << "\n---------------------------\n";
}

std::string reverse_string(const std::string& str) {
	std::string reversed;

	for (size_t i{ 0 }; i < str.length(); i++){
		reversed += str.at(str.length() - i - 1);
	}

	return reversed;
}
void section_12_exercise_34() {
	std::string input = "Hello, World!";
	cout << "String before: " << input << endl;
	std::string reversed = reverse_string(input);
	cout << "String after: " << reversed << endl;
}
 