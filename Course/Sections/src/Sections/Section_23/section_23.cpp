#include "..\..\..\..\..\..\Course\Course\Sections\include\Sections\Section_23\section_23.h"

// 0 1 2 3, автоматично компілятором
enum Direction { North, South, East, West };

std::string direction_to_string(Direction direction) {
	std::string result;
	switch (direction) {
	case North:
		result = "North";
		break;
	case South:
		result = "South";
		break;
	case East:
		result = "East";
		break;
	case West:
		result = "West";
		break;
	default:
		result = "Unknown direction";
		break;
	}
	return result;
}

void unscoped_enum_test1() {
	cout << "\n--- Test1 ----------------------------------------" << endl;

	Direction direction{ North };

	cout << "Direction " << direction<< endl;
	cout << direction_to_string(direction) << endl << endl;

	direction = West;
	cout << "Direction " << direction << endl;
	cout << direction_to_string(direction) << endl << endl;

	direction = Direction(100);
	cout << "Direction " << direction << endl;
	cout << direction_to_string(direction) << endl << endl;

	direction = Direction(3);
	cout << "Direction " << direction << endl;
	cout << direction_to_string(direction) << endl << endl;

	direction = Direction(4);
	cout << "Direction " << direction << endl;
	cout << direction_to_string(direction) << endl << endl;

	direction = Direction(5);
	cout << "Direction " << direction << endl;
	cout << direction_to_string(direction) << endl << endl;

	direction = static_cast<Direction>(100);
	cout << "Direction " << direction << endl;
	cout << direction_to_string(direction) << endl;
}

//0 1 2 3
enum Grocery_Item {Milk,Bread, Apple, Orange};

std::ostream& operator<<(std::ostream& os, Grocery_Item grocery_item) {
	switch (grocery_item) {
	case Milk:
		os << "Milk";
		break;
	case Bread:
		os << "Bread";
		break;
	case Apple:
		os << "Apple";
		break;
	case Orange:
		os << "Orange";
		break;
	default:
		os << "Invalid item";
	}
	return os;
}

bool is_valid_grocery_item(Grocery_Item grocery_item) {
	switch (grocery_item) {
		case Milk:
		case Bread:
		case Apple:
		case Orange:
			return true;
		default:
			return false;
	}
}

void display_grocery_list(const std::vector<Grocery_Item>& grocery_list)
{
	cout << "Grocery List" << endl;
	cout << "==================================================" << endl;

	int invalid_item_count{ 0 };
	int valid_item_count{ 0 };
	for (Grocery_Item grocery_item : grocery_list) {
		cout << grocery_item << endl;

		if (is_valid_grocery_item(grocery_item))
			valid_item_count++;
		else
			invalid_item_count++;
	}

	cout << "==================================================" << endl;
	cout << "Valid items: " << valid_item_count << endl;
	cout << "Invalid items: " << invalid_item_count << endl;
	cout << "Total items: " << valid_item_count + invalid_item_count << endl;
}

void unscoped_enum_test2() {
	cout << "\n--- Test2 ----------------------------------------" << endl;

	Grocery_Item Potato;
	Grocery_Item Carrot;

	std::vector<Grocery_Item> shopping_list{ Apple,Apple,Milk,Orange};

	shopping_list.push_back(Potato);	//invalid
	shopping_list.push_back(Milk);		//valid
	shopping_list.push_back(Carrot);	//invalid

	int Helicopter{ 1000 };

	shopping_list.push_back(Grocery_Item(Helicopter));	//invalid
	shopping_list.push_back(Grocery_Item(0));			//Milk
	shopping_list.push_back(Grocery_Item(2));			//Bread

	display_grocery_list(shopping_list);
}

enum State {Engine_Failure, Inclement_Weather,Nominal, Unknown};
enum Sequence {Abort,Hold,Launch};

std::istream& operator>>(std::istream& is, State& state) {
	std::underlying_type_t<State> user_input;
	is >> user_input;

	switch (user_input) {
		case Engine_Failure:
		case Inclement_Weather:
		case Nominal:
		case Unknown:
			state = State(user_input);
			break;
		default:
			cout << "User input is not a valid launc state." << endl;
			state = Unknown;
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const Sequence& sequence) {
	switch (sequence) {
		case Abort:
			os << "Abort";
			break;
		case Hold:
			os << "Hold";
			break;
		case Launch:
			os << "Launch";
			break;
	}
	return os;
}

void initiate(Sequence sequence){
	cout<<"Initiate "<<sequence<<" sequence!"<<endl;
}

void unscoped_enum_test3() {
	cout << "\n--- Test3 ----------------------------------------" << endl;

	State state;
	cout << "Launch state: ";
	cin >> state;

	switch (state) {
		case Engine_Failure:
		case Unknown:
			initiate(Abort);
			break;
		case Inclement_Weather:
			initiate(Hold);
			break;
		case Nominal:
			initiate(Launch);
			break;
	}
}

void enum_case_1() {
	//unscoped_enum_test1();
	//unscoped_enum_test2();
	unscoped_enum_test3();
}

enum class Shop_List {Milk = 350,Bread=250,Apple = 132,Orange = 100};

std::ostream& operator<<(std::ostream& os, Shop_List shop_list) {
	std::underlying_type_t<Shop_List> value = std::underlying_type_t<Shop_List>(shop_list);
	switch (shop_list) {
	case Shop_List::Milk:
		os << "Milk";
		break;
	case Shop_List::Bread:
		os << "Bread";
		break;
	case Shop_List::Apple:
		os << "Apple";
		break;
	case Shop_List::Orange:
		os << "Orange";
		break;
	default:
		os << "Invalid item";
	}
	os << " : " << value;
	return os;
}

bool is_valid_shop_list_item(Shop_List shop_list) {
	switch (shop_list) {
	case Shop_List::Milk:
	case Shop_List::Bread:
	case Shop_List::Apple:
	case Shop_List::Orange:
		return true;
	default:
		return false;
	}
}

void display_shop_list(const std::vector<Shop_List>& shop_list)
{
	cout << "Shop List" << endl;
	cout << "==================================================" << endl;

	int invalid_item_count{ 0 };
	int valid_item_count{ 0 };
	for (Shop_List stop_item : shop_list) {
		cout << stop_item << endl;

		if (is_valid_shop_list_item(stop_item))
			valid_item_count++;
		else
			invalid_item_count++;
	}

	cout << "==================================================" << endl;
	cout << "Valid items: " << valid_item_count << endl;
	cout << "Invalid items: " << invalid_item_count << endl;
	cout << "Total items: " << valid_item_count + invalid_item_count << endl;
}

void scoped_enum_test1() {
	cout << "\n--- Test1 ----------------------------------------" << endl;

	/*std::vector<Shop_List> shopping_list{ Apple,Apple,Milk,Orange };*/
	std::vector<Shop_List> shopping_list;

	shopping_list.push_back(Shop_List::Apple);		//valid
	shopping_list.push_back(Shop_List::Milk);		//valid
	shopping_list.push_back(Shop_List::Orange);		//valid

	int Helicopter{ 1000 };

	shopping_list.push_back(Shop_List(Helicopter));	//invalid
	shopping_list.push_back(Shop_List(0));			//Milk
	shopping_list.push_back(Shop_List(2));			//Bread

	display_shop_list(shopping_list);
}

class Enum_Player {
	friend std::ostream& operator<<(std::ostream& os, const Enum_Player& p);
public:
	enum class Mode { Attack, Defense, Idle };

	enum class Direction { North, South, East, West };

	Enum_Player(std::string name, Mode mode = Mode::Idle, Direction direction = Direction::North)
		:name{ name }, mode{ mode }, direction{ direction } {
	}

	std::string get_name() const {
		return name;
	}
	void set_name(std::string name) {
		this->name = name;
	}

	Mode get_mode() const { return mode; }
	void set_mode(Mode mode) {
		this->mode= mode;
	}

	Direction get_direction() const { return direction; }
	void set_direction(Direction direction) {
		this->direction = direction;
	}

private:
	std::string name;
	Mode mode;
	Direction direction;
};

std::string get_Enum_Player_mode(Enum_Player::Mode mode) {
	std::string  result;
	switch (mode) {
	case Enum_Player::Mode::Attack:
		result = "Attack";
		break;
	case Enum_Player::Mode::Defense:
		result = "Defense";
		break;
	case Enum_Player::Mode::Idle:
		result = "Idle";
		break;
	};
	return result;
}

std::string get_Enum_Player_direction(Enum_Player::Direction direction) {
	std::string  result;
	switch (direction) {
	case Enum_Player::Direction::North:
		result = "North";
		break;
	case Enum_Player::Direction::South:
		result = "South";
		break;
	case Enum_Player::Direction::East:
		result = "East";
		break;
	case Enum_Player::Direction::West:
		result = "West";
		break;
	};
	return result;
}

std::ostream& operator<<(std::ostream& os, const Enum_Player& p) {
	os << "Enum_Player name:          " << p.get_name() << "\n"
		<< "Enum_Player mode:          " << get_Enum_Player_mode(p.mode) << "\n"
		<< "Enum_Player direction:     " << get_Enum_Player_direction(p.direction)
		<< endl;
	return os;
}

void scoped_enum_test2() {
	cout << "\n--- Test2 ----------------------------------------" << endl;

	Enum_Player p1{ "Cloud Strife",Enum_Player::Mode::Attack,Enum_Player::Direction::North};
	Enum_Player p2{ "Tifa Lockhart",Enum_Player::Mode::Defense ,Enum_Player::Direction::West };
	Enum_Player p3{ "Sephiroth",Enum_Player::Mode::Idle ,Enum_Player::Direction::South};

	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;

}

void enum_case_2() {
	scoped_enum_test1();
	scoped_enum_test2();
}
