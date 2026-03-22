#pragma once
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Player {
private:
	friend void show_friend_name(Player &p);
	string name;
	int health;
	int xp;
	static int num_players;
public:
	//Contructors
	//Player();
	//Player(string name);
	//Player(string name, int health, int xp);
	Player(string name = "None", int health = 0, int xp = 0);
	//Player(string name_val = "None", int health_val = 0, int xp_val = 0);

	//Copy constructor
	Player(const Player& source); 

	void print_player();
	void talk(string);
	bool is_dead();

	//Getters
	//string get_name();
	//const 
	string get_name() const;

	void set_name(string name);

	static int get_num_players();

	int get_health();
	int get_xp();

	//Destructor
	~Player();
};
