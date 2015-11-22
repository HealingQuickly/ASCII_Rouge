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

char Enemy::getTile(){
	return _tile;
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

char Enemy::getMove(int playerX, int playerY){
	static mt19937 randomEngine(time(0));
	uniform_int_distribution<int> moveRoll(0, 6);
	int distance;
	int diffX = _x - playerX;
	int diffY = _y - playerY;
	int aDiffX = abs(diffX);
	int aDiffY = abs(diffY);
	distance = aDiffX + aDiffY;
	if (distance <= 5){
		//Moving along X axis
		if (aDiffX < aDiffY){ // closer on X axis, so make them move closer on Y axis
			if (diffY > 0){ // enemy is to the bottom of player
				return 'w'; // so go up
			}
			else{
				return 's';
			}
		}
		else{ // closer on Y axis, so make them move clolser on X axis
			if (diffX > 0){ // enemy is to the right of player
				return 'a'; // so move left
			}
			else{
				return 'd';
			}
		}
	}
	int randomMove = moveRoll(randomEngine);
	switch (randomMove)
	{
	case 0:
		return 'a';
	case 1:
		return 'w';
	case 2:
		return 's';
	case 3:
		return 'd';
	default:
		return '.';
	}
}