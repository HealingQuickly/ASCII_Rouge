#include "GameSystem.h"

#include <iostream>
#include <conio.h>

// set up the game
GameSystem::GameSystem(string levelFile)
{
	_player.init(1, 100, 10, 10, 0);
	_level.load(levelFile, _player);

	system("PAUSE");
}

void GameSystem::playGame(){
	bool isDone = false;
	while (isDone == false){
		_level.print();
		movePlayer();
		_level.updateEnemies(_player);
	}
}

void GameSystem::movePlayer(){
	char input;
	printf("Enter a move command (w a s d): ");
	input = _getch();

	_level.canMovePlayer(input, _player);
}