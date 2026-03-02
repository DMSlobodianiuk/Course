#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

void section_7_practice()
{
	vector<int> vector1;
	vector<int> vector2;

	vector1.push_back(10);
	vector1.push_back(20);

	cout << "vector1: " << vector1.at(0) << " " << vector1.at(1) << " with size: " << vector1.size() << endl;
	//cout << vector1.at(0) << endl;
	//cout << vector1.at(1) << endl;
	//cout << vector1.size() << endl;

	vector2.push_back(100);
	vector2.push_back(200);

	cout << "vector2: " << vector2.at(0) << " " << vector2.at(1) << " with size: " << vector2.size() << endl;
	/*cout << vector2.at(0) << endl;
	cout << vector2.at(1) << endl;
	cout << vector2.size() << endl;*/

	vector<vector<int>> vector_2d;
	vector_2d.push_back(vector1);
	vector_2d.push_back(vector2);

	cout << "\nvector_2d:\n";
	cout << vector_2d.at(0).at(0) <<" "<< vector_2d.at(0).at(1) << endl;
	cout << vector_2d.at(1).at(0) <<" "<< vector_2d.at(1).at(1) << endl;

	vector1.at(0) = 1000;

	cout << "vector1: " << vector1.at(0) << " " << vector1.at(1) << " with size: " << vector1.size() << endl;;

}

