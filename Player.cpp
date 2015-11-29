#include "Player.h"
#include <random>
#include <ctime>

using namespace std;


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

int Player::attack(){
	static mt19937 randomEngine(time(0));
	uniform_int_distribution<int> attackRoll(0, _attack);

	return attackRoll(randomEngine);
}

int Player::takeDamage(int attack){
	attack -= _defense;
	if (attack > 0){
		_health -= attack;
		// check if died
		if (_health <= 0){
			return 1;
		}
	}
	return 0; // didn't die; return 1 if did die
}

void Player::setPosition(int x, int y){
	_x = x;
	_y = y;
}

void Player::addExp(int expValue){
	_exp += expValue;
	//Level UP!!
	while (_exp > 50){
		printf("Leveled UP!\n");
		_exp -= 50;
		_attack += 10;
		_defense += 7;
		_level++;
		_health += 15;
		system("PAUSE");
	}
}

// get the position of player using reference variable
void Player::getPosition(int &x, int &y){
	x = _x;
	y = _y;
}
