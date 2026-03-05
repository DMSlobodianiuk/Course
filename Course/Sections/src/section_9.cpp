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
