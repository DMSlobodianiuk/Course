//#include <iostream>
//#include <string>
//#include <vector>
//#include "Account/Account.h"
//#include "Player/Player.h"
//#include "Shallow/Shallow.h"
//#include "Deep/Deep.h"
//#include "Move/Move.h"
//#include "Challenge/section_13_challenge.h"
//
//using std::cout;
//using std::cin;
//using std::endl;
//using std::string;
//using std::vector;
//
////class Player{
////private:
////	string name;
////	int health;
////	int xp;
////public:
////	void print_player() {
////		cout << "Player's name: " << name<<", health: " << health << ", xp: " << xp << endl;
////	}
////	void talk(string);
////	bool is_dead();
////};
////class Account {
////public:
////	string name{"Account"};
////	double balance{0.0};
////
////	bool deposit(double bal) {
////		balance += bal;
////		cout << "In deposit|" <<"Current balance: "<<balance << endl;
////		return 0;
////	}
////	bool withdraw(double bal) {
////		balance -= bal;
////		cout << "In withdraw|" << "Current balance: "<<balance << endl;
////		return 0;
////	}
////};
//void declare_classes_objects_case_1() {
//
//	Player p1;
//	Player *p2 = new Player();
//	Player* p3{ nullptr };
//	Player p4;
//
//	p3 = new Player;
//
//	p1.print_player();
//
//	p2->print_player(); 
//	p3->print_player();
//
//	(*p2).print_player();
//	(*p3).print_player();
//
//	Player players[]{ p1,p4 };
//
//	vector<Player> player_vec{ p1 };
//	player_vec.push_back(p1);
//
//	delete p2;
//	delete p3;
//}
//
//class AnotherPlayer {
//public:
//	string name;
//	int health;
//	int xp;
//
//	void talk(string text_to_say) {
//		cout << name << " says "<<text_to_say << endl;;
//	}
//	bool is_dead();
//};
//void acceccing_class_members_case_1(){
//	//AnotherPlayer frank;
//
//	//frank.name = "Frank";
//	//frank.health = 100;
//	//frank.xp = 12;
//
//	//frank.talk("Hi there");
//
//	//AnotherPlayer* enemy = new AnotherPlayer;
//	//(*enemy).name = "Dot enemy";
//	//(*enemy).talk("I`m a dot");
//
//	//enemy->name = "Members of pointer enemy";
//	//enemy->talk("I'm a member of pointer");
//
//	//Account frank_account;
//	//frank_account.name = "Frank`s account";
//	//frank_account.balance = 5000.0;
//
//	//frank_account.deposit(1000.0);
//	//frank_account.withdraw(500);
//
//}
//
//class Warrior {
//private:
//	string name{"Warrior"};
//	int health;
//	int xp;
//public:
//	void talk(string text_to_say) {
//		cout << name << " says " << text_to_say << endl;
//	}
//	bool is_dead();
//};
//
//void public_private_case_1() {
//	Warrior w1;
//	//w1.name = "Garrosh";
//	w1.talk("This is a public method");
//}
//
//void implementing_members_method_case_1() {
//
//	Account *ac1 = new Account;
//	ac1->set_name("DMS");
//	ac1->set_balance(2476.0);
//
//	ac1->print_name();
//	ac1->print_balance();
//
//	ac1->deposit(500.0);
//	ac1->print_balance();
//	ac1->withdraw(200.0);
//	ac1->print_balance();
//
//	Account ac2;
//	ac2.set_name("Second name");
//	ac2.set_balance(789456.0);
//
//	ac2.print_name();
//	ac2.print_balance();
//	
//
//	delete ac1;
//}
//
//void constructors_destructors_case_1() {
//	Player slayer;
//	Player frank{ "Frank",100,4 };
//	Player hero{ "Hero" };
//	Player villian{ "Villian" };
//
//	Player* enemy = new Player("Enemy", 1000.0,0 );
//	delete enemy;
//}
//
//void constrictors_parameters_default_values_case_1() {
//	Player empty;
//	Player frank{ "Frank" };
//	Player hero{ "Hero",100 };
//	Player villian{ "Villian",100,55 };
//
//	empty.print_player();
//	frank.print_player();
//	hero.print_player();
//	villian.print_player();
//}
//
//void copy_constructor_cas1_1() {
//	Player empty;
//	Player frank{"Frank"};
//	Player hero{"Hero",100};
//	Player villian{"Villian",100,55};
//
//	//empty.print_player();
//	//frank.print_player();
//	//hero.print_player();
//	//villian.print_player();
//	
//	Player copy_player = hero; 
//	copy_player.print_player();
//}
//
//void display_shallow(Shallow s) {
//	cout << s.get_data_value() << endl;
//}
//
//void shallow_copying_case_1() {
//
//	Shallow obj1{ 100 };
//	display_shallow(obj1);
//
//	Shallow obj2{ obj1 };
//	obj2.set_data_value(1000);
//
//}
//
//void display_deep(Deep s) {
//	cout << s.get_data_value() << endl;
//}
//
//void deep_copying_case_1() {
//	Deep obj1{ 100 };
//	display_deep(obj1);
//
//	Deep obj2{ obj1 };
//	obj2.set_data_value(1000);
//
//}
//
//void move_constructors_case_1() {
//	vector<Move> vec;
//
//	vec.push_back(Move{ 10 });
//
//	vec.push_back(Move{ 20 });
//	vec.push_back(Move{ 30 });
//	vec.push_back(Move{ 40 });
//	vec.push_back(Move{ 50 });
//	vec.push_back(Move{ 60 });
//	vec.push_back(Move{ 70 });
//	vec.push_back(Move{ 80 });
//
//} 
//
//void using_const_with_classes_case_1() {
//	const Player villian{ "Villian",100,55 };
//
//	Player hero{ "Hero",100,15 };
//
//	cout << villian.get_name() << endl;
//	cout << hero.get_name() << endl;
//
//}
//
//void static_class_members_case_1() {
//
//	cout << "There are " << Player::get_num_players() <<" players" << endl;
//
//	Player empty;
//	Player frank{ "Frank" };
//	Player hero{ "Hero",100 };
//	Player villian{ "Villian",100,55 };
//
//	{
//		Player hero{ "Hero",100 };
//		Player villian{ "Villian",100,55 };
//		cout << "There are " << Player::get_num_players() << " players" << endl;
//	}
//
//	cout << "There are " << Player::get_num_players() <<" players" << endl;
//
//}
//
//void friend_of_class_case_1() {
//	Player *p1 = new Player{ "Frank",100,10 };
//
//	show_friend_name(*p1);
//}
//
//void section_13_challenge() {
//
//	Section_13* s_13 = new Section_13();
//
//	s_13->run();
//
//	delete s_13;
//}
