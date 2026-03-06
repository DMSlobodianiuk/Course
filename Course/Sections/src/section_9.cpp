#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

void letter_grade_selection() {

	char letter_grade{};

	cout << "Enter the letter grade you expect on the exam: ";
	cin >> letter_grade;

	switch (letter_grade) {
		case 'a':
		case 'A': 
			cout << "You need a 90 or above" << endl;
			break;
		case 'b':
		case 'B':
			cout << "You need 80-89 for a B, got study!" << endl;
			break;
		case 'c':
		case 'C':
			cout << "You need 70-79 for an average grade" << endl;
			break;
		case 'd':
		case 'D':
			cout << "You need strive for a better grade. All you need is 60-69" << endl;
			break;
		case 'f':
		case 'F': {

			cout << "Are you sure about "<<letter_grade <<" (Y/N)?" << endl;
			char confirm{};
			cin >> confirm;
			if (confirm == 'y' || confirm == 'Y')
				cout << "OK, I guess you didn't study.." << endl;
			else if (confirm == 'n' || confirm == 'N')
				cout << "Good - go study" << endl;
			else
				cout << "Invalid answer" << endl;
			break;
		}
		default:
			cout << "Sorry, not a valid grade" << endl;
	}
}

void enum_direction_example() {
	enum Direction {
		left,right,up,down
	};

	Direction heading{ left };
	//Direction heading{ right };
	//Direction heading{ up };
	//Direction heading{ down };

	switch (heading) {
	case left:
		cout << "left" << endl;
		break;
	case right:
		cout << "right" << endl;
		break;
	case up:
		cout << "up" << endl;
		break;
	case down:
		cout << "down" << endl;
		break;
	default:
		cout << "Direction is not selected";
	}
}

void conditional_operator_case_1() {
	
	int num{};

	cout << "Enter a number: "<<std::boolalpha;
	cin >> num;

	//bool is_even{ true };

	//is_even = (num % 2 == 0) ? true : false;

	//cout << "Does " << num << " is even: " << is_even << endl;

	cout << num << " is " << ((num % 2 == 0 )? "even" : "odd") << endl;
}

void conditional_operator_case_2() {

	int num1{}, num2{};
	cout << "Enter two integers separated by a space: ";
	cin >> num1 >> num2;

	//cout << ((num1 > num2) ? "num1 is bigger than num2" : "num1 is smaller than num2") << endl;
	cout << ((num1 != num2) ? ((num1 > num2) ? "num1 is bigger than num2" : "num1 is smaller than num2") : "they are equal") << endl;

}

void for_loop_case_1() {

	/*for (int i{ 1 }; i <= 10; i += i + 10%i)
		cout << i << " ";*/
	
	//for (int i{ 1 }, j{ 17 }; i <= 10; i++, j++) {
	//	cout << i << " * " << j << " = " << i * j << endl;
	//}
	
	/*for (int i{ 10 }; i < 100; i++) {
		for (int j{ 0 }; j < 10; j++) {
			cout << i << " ";
			i++;
		}
		i--;
		cout << endl;
	}*/

	/*cout << "Multiple of 3:"<<std::boolalpha;
	for (int i{ 100 }; i < 500; i++) {
		for (int j{ 0 }; j < 10; j++) {
			cout <<"| " << i << " " << ((i % 3 == 0) ? true: false) << "|";
		}
		cout << endl;
	}*/

	//std::vector<int> nums{ 1,2,3,4,5,6 };
	//for (int i{ 0 }; i < nums.size(); i++) {
	//	cout << nums.at(i)<< " " ;
	//	//cout << nums[i] <<" ";
	//	(i == nums.size() - 1) ? cout << "\n" : cout << "";
	//}

	int sum{ 0 };
	for (int i{ 1 }; i <= 15; i++)
		(i % 2 != 0) ? sum += i : 0;
		
}

void range_base_for_loop_case_1() {

	std::vector<double> temps{ 87.2, 77.1, 80.0, 72.5 };

	double average_temp{};
	double running_sum{};

	for (auto temp : temps)
		running_sum += temp;

	average_temp = running_sum / temps.size();

	cout << "Sum: " << running_sum << "\nSize: " << temps.size() << "\nAverage: " << average_temp << endl;
}

void range_base_for_loop_case_2() {

	double running_sum{};
	double average_temp{};
	int size{ 0 };

	for (auto temp : { 60.2, 80.1, 90.0, 78.2 }) {
		running_sum += temp;
		size += 1;
	}

	average_temp = running_sum / size;

	cout << "Sum: " << running_sum << "\nSize: " << size << "\nAverage: " << average_temp << endl;
}

void range_base_for_loop_case_3() {
	for (auto c : "Frank")
		cout << c << " ";
}

void range_base_for_loop_case_4() {
	
	std::vector<int> vec{ 1,3,5,15,16,17,18,19,20,21,25,26,27,30,50,55,56,58,100,200,300,400,500,600,700 };

	int count{ 0 };
	for (auto el : vec)
		((el % 3 == 0) || (el % 5 == 0)) ? (count += 1) : 0;
}

void while_loop_case_1() {

	int num{};
	cout << "Enter number larger than 100: "; cin >> num;

	while (num <= 100) {
		cout << "You should enter larger than 100 not " << num << ". Try again: ";
		cin >> num;
	}
}

void while_loop_case_2() {

	bool done{ false };
	int number{ 0 };

	while (!done) {
		cout << "Enter value between 1 and 5: ";
		cin >> number;

		if (number < 1 || number > 5)
			cout << "Out of range, try again.\n";
		else {
			cout << "Thanks";
			done = true;
		}
	}
}

void do_while_loop_case_1() {

	char selection{};

	do {
		double width{}, height{};
		cout << "Please, enter width and height, separated by space: ";
		cin >> width >> height;

		double area{ width * height };
		cout << "The area is " << area << endl;

		cout << "Calculate another? (Y/N): ";
		cin >> selection;

	} while (selection == 'Y' || selection == 'y');
	cout << "Thanks" << endl;
}

void do_while_loop_case_2() {

	char selection{};

	do {

		cout << "\n----------------\n";
		cout << "1. Do this\n2. Do that\n3. Do something else\nQ: Quit\n";

		cout << "\nEnter your selection: "; cin >> selection;
		
		cout << "You chose: " << selection;
		switch (selection) {
			case '1':
				cout << " - Do this\n";
				break;
			case '2':
				cout << " - Do that\n";
				break;
			case '3':
				cout << " - Do something else\n";
				break;
			case 'q':
			case 'Q':
				cout << " Quit\n";
				break;
			default:
				cout << " Uknown option - try again...\n";
		}

	} while (selection != 'Q' && selection != 'q');
	cout << "\nThanks" << endl;
}

void nested_loops_case_1(){

	//for (int i{ 1 }; i < 10; i++) {
	//	for (int j{ 1 }; j < 10; j++) {
	//		cout << i * j << " ";
	//	}
	//	cout << endl;
	//}

	std::vector<std::vector<int>> vector_2d
	{
		{1,2,3},
		{10,20,30,40},
		{100,200,300,400,500}
	};

	for (auto vec : vector_2d) {
		for (auto val : vec) {
			cout << val << " ";
		}
		cout << endl;
	}
}

void nested_loops_case_2() {
	for (int i{ 1 }; i <= 9; i++) {
		cout << "\nThe multiplication of " << i << " on j" << endl;
		for (int j{ 1 }; j <= 9; j++) {
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}
}

void nested_loops_case_3() {

	int n{ 0 };
	cout << "How many data items do you have? "; cin >> n;

	std::vector<int> vec;


	for (int i{ 0 }; i < n; i++) {
		int data_item{};
		cout << "Enter data item " << i+1 << ": "; 
		cin >> data_item;
		vec.push_back(data_item);
	}

	cout << "\nDisplaying Histogram" << endl;
	for (int i{ 0 }; i < n; i++){
		for (int j{ 0 }; j < vec.at(i); j++) {
			cout << "-";
		}
		cout << endl;
	}
}

void section_9_challenge() {
	
	char selection{};

	int max_of_list{};
	int min_of_list{};
	
	int number{};
	double sum{ 0.0 };
	double mean{ 0.0 };

	std::vector<int> vec;
	//vector.clear

	do {
		cout << "\n-------------------------------------------------------------------------------------------------";
		cout << "\nP - Print numbers\nA - Add a number\nM - Display mean of the numbers\nS - Display the smallest number"
			"\nL - Display the largest number\nQ - Quit" << endl;
		cout << "\nEnter your choice: ";
		cin >> selection;

		switch (selection) {
			case 'p':
			case 'P':
				cout << "Print numbers was selected" << endl;
				if (0 < vec.size()) {
					for (auto el : vec)
						cout << el << " ";
					cout << endl;
				}
				else
					cout << "[] - this list is empty" << endl;
				break;
			case 'a':
			case 'A':
				cout << "Add a number was selected" << endl;
				cout << "Please, enter a number: "; cin >> number;
				cout << number << " was added" << endl;
				vec.push_back(number);
				(number > max_of_list) ? max_of_list = number : 0;
				(number < min_of_list) ? min_of_list = number : 0;
				break;
			case 'm':
			case 'M':
				cout << "Display the mean of the numbers was selected" << endl;

				for (auto el : vec)
					sum += el;
				mean = sum / vec.size();
				cout << "The mean value of array is " << mean << endl;
				break;
			case 's':
			case 'S':
				cout << "Display the smallest number was selected" << endl;
				cout << "The smallest number is " << min_of_list << endl;
				break;
			case 'l':
			case 'L':
				cout << "Display the largest number was selected" << endl;
				cout << "The largest number is " << max_of_list << endl;
				break;
			case 'q':
			case 'Q':
				cout << "Quit was selected" << endl;
				cout << "Quiting..." << endl;
				break;
			default:
				cout << "Wrong option was selected, try again" << endl;
				continue;
		}
	} while (selection != 'Q' && selection != 'q');
}
