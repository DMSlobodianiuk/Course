//Section 6
#include <iostream>

const double per_small_room{ 25 };
const double per_large_room{ 35 };
const double tax{ 0.06 };
const int estimate{ 30 };

void section_6_practice()
{

	std::cout << "Hello, welcome to Dmytro's Carpet Cleaning Service.\n\n";

	std::cout << "How many small rooms would you like cleaned? ";
	int quantity_of_small_rooms{ 0 };
	std::cin >> quantity_of_small_rooms;

	std::cout << "How many large rooms would you like cleaned? ";
	int quantity_of_large_rooms{ 0 };
	std::cin >> quantity_of_large_rooms;

	std::cout << "Estimate for carpet cleaning service\n";
	std::cout << "Number of small rooms: " << quantity_of_small_rooms << std::endl;
	std::cout << "Number of large rooms: " << quantity_of_large_rooms << std::endl;

	std::cout << "Price per small room: $" << per_small_room << std::endl;
	std::cout << "Price per large room: $" << per_large_room << std::endl;
	double sum{ per_small_room * quantity_of_small_rooms + per_large_room * quantity_of_large_rooms };
	std::cout << "Cost : $" << sum << std::endl;
	double sum_tax{ sum * tax };
	std::cout << "Tax: $" << sum_tax << std::endl;

	std::cout << "==================================================\n";

	double total_sum(sum + sum_tax);
	std::cout << "Total estimate: $" << total_sum << std::endl;
	std::cout << "This estimate is valid for " << estimate << " days\n";

}
