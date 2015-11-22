#pragma once

#include <vector>
#include <string>

#include "Player.h"

using namespace std;

class Level
{
public:
	Level();
	
	void load(string fileName, Player &player);
	void print();
	void canMovePlayer(char input, Player &player);

	//getter
	char getTile(int x, int y);
	//setter
	void setTile(int x, int y, char tile);
private:
	void processPlayerMove(Player &player, int targetX, int targetY);

	vector<string> _levelData;
};

