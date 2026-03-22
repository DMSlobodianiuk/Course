#include "Player.h"

//--------------------------------------------------------------
//assignment
//Player::Player() {
//	name = "None";
//	health = 100;
//	xp = 3;
//}
//
//Player::Player(string name) {
//	this->name = name;
//}
//
//Player::Player(string name, int health, int xp) {
//	this->name = name;
//	this->health = health;
//	this->xp = xp;
//}
//--------------------------------------------------------------
//--------------------------------------------------------------
//initialization
//Player::Player()
//	:name{ "None" }, health{ 0 }, xp{ 0 } {
//}
//
//Player::Player(string name_val)
//	:name{ name_val } {
//}
//
//Player::Player(string name_val, int health_val, int xp_val)
//	:name{ name_val }, health{ health_val }, xp{ xp_val } {
//}
//--------------------------------------------------------------
//--------------------------------------------------------------
//delegating
//Player::Player()
//	:Player{ "None",0,0 } {
//}
//
//Player::Player(string name_val)
//	:Player{ name_val,0,0 } {
//}

Player::Player(string name_val, int health_val, int xp_val)
	:name{ name_val }, health{ health_val }, xp{ xp_val } {
	cout << "Player " << name << " was created" << endl;
	++num_players;
}
//--------------------------------------------------------------
//--------------------------------------------------------------
//default contructor parameters
//Player::Player(string name_val = "None", int health_val = 0, int xp_val = 0)
//	:name{ name_val }, health{ health_val }, xp{ xp_val } {
//}
//--------------------------------------------------------------

int Player::num_players = 0;

int Player::get_num_players(){ return num_players; }

//Copy Constructor
Player::Player(const Player& source)
	/*:name{ source.name },
	health{ source.health },
	xp{ source.xp } {*/
	:Player{source.name,source.health,source.xp}{
	cout << "Copy constructor - made copy of: " << source.name << endl;
}

void Player::print_player() {
	cout << "Player's name: " << name << ", health: " << health << ", xp: " << xp << endl;
}

bool Player::is_dead() { return true; }


//string Player::get_name() { return name; }

//const
string Player::get_name() const { return name; }

void Player::set_name(string name) { this->name = name; }

int Player::get_health() { return health; }

int Player::get_xp() { return xp; }

Player::~Player() { 
	cout << "Player " << name << " was destroyed" << endl;
	num_players--;
}

void show_friend_name(Player &p) {
	cout << "I'm a friend of player "<<p.name << endl;
}
