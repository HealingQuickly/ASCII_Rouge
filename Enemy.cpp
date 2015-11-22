#include "Enemy.h"

#include <random>
#include <ctime>


Enemy::Enemy(string name, char tile, int level, int attack, int defense, int health, int expValue)
{
	_name = name;
	_tile = tile;
	_level = level;
	_attack = attack;
	_defense = defense;
	_health = health;
	_expValue = expValue;
}

void Enemy::setPosition(int x, int y){
	_x = x;
	_y = y;
}

// get the position of player using reference variable
void Enemy::getPosition(int &x, int &y){
	x = _x;
	y = _y;
}

string Enemy::getName(){
	return _name;
}

int Enemy::attack(){
	static mt19937 randomEngine(time(0));
	uniform_int_distribution<int> attackRoll(0, _attack);

	return attackRoll(randomEngine);
}

int Enemy::takeDamage(int attack){
	attack -= _defense;
	if (attack > 0){
		_health -= attack;
		// check if died
		if (_health <= 0){
			return _expValue;
		}
	}
	return 0; // didn't die, return expValue if did die
}