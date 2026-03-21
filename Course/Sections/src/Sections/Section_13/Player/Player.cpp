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
}
//--------------------------------------------------------------
//--------------------------------------------------------------
//default contructor parameters
//Player::Player(string name_val = "None", int health_val = 0, int xp_val = 0)
//	:name{ name_val }, health{ health_val }, xp{ xp_val } {
//}
//--------------------------------------------------------------

void Player::print_player() {
	cout << "Player's name: " << name << ", health: " << health << ", xp: " << xp << endl;
}

bool Player::is_dead() { return true; }

Player::~Player() {}
