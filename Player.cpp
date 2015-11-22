#include "Player.h"


Player::Player()
{
	_x = 0;
	_y = 0;
}

void Player::init(int level, int health, int attack, int defense, int exp){
	_level = level;
	_health = health;
	_attack = attack;
	_defense = defense;
	_exp = exp;
}

void Player::setPosition(int x, int y){
	_x = x;
	_y = y;
}

// get the position of player using reference variable
void Player::getPosition(int &x, int &y){
	x = _x;
	y = _y;
}