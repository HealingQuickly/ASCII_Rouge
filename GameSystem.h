#pragma once

#include <string>

#include "Player.h"
#include "Level.h"

using namespace std;

class GameSystem
{
public:
	GameSystem(string levelFile);

	void playGame();
	void movePlayer();
private:
	Level _level;
	Player _player;
};

