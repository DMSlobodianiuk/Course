#pragma once
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Player {
private:
	string name;
	int health;
	int xp;
public:
	//Player();
	//Player(string name);
	//Player(string name, int health, int xp);
	Player(string name = "None", int health = 0, int xp = 0);
	//Player(string name_val = "None", int health_val = 0, int xp_val = 0);

	void print_player();
	void talk(string);
	bool is_dead();

	~Player();
};