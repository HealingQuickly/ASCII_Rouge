#pragma once
class Player
{
public:
	Player();
	void init(int level, int health, int attack, int defense, int exp);

	//setter
	void setPosition(int x, int y);

	//getter
	void getPosition(int &x, int &y);
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

