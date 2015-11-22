#pragma once
#include <string>

using namespace std;

class Enemy
{
public:
	Enemy(string name, char tile, int level, int attack, int defense, int health, int expValue);
	//setter
	void setPosition(int x, int y);

	//getter
	void getPosition(int &x, int &y);
	string getName();

	int attack();
	int takeDamage(int attack); // attack is the chance range from 0 to player's max attack value
private:
	string _name;
	char _tile;
	int _level;
	int _attack;
	int _defense;
	int _health;
	int _expValue;

	//position
	int _x;
	int _y;

	// vector<Item> _possibleDrops;
};

