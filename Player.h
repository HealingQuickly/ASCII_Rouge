#pragma once
class Player
{
public:
	Player();
	void init(int level, int health, int attack, int defense, int exp);

	int attack();

	//setter
	void setPosition(int x, int y);
	void addExp(int expValue);

	//getter
	void getPosition(int &x, int &y);

	int takeDamage(int attack); // attack is the chance range from 0 to player's max attack value
private:
	int _level;
	int _health;
	int _attack;
	int _defense;
	int _exp;

	//position
	int _x;
	int _y;
};

