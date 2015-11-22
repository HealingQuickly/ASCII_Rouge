#include "Level.h"
#include <fstream>
#include <iostream>
#include <cstdio>

Level::Level()
{

}

void Level::load(string fileName, Player &player){
	// load the level
	ifstream file;
	file.open(fileName);
	if (file.fail()){
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}

	// load file successfully
	string line;
	while (getline(file, line)){
		_levelData.push_back(line);
	}

	file.close();

	//process the level
	char tile;
	for (int i = 0; i < _levelData.size(); i++){
		for (int j = 0; j < _levelData[i].size(); j++){
			tile = _levelData[i][j];
			switch (tile){
			case 'P':
				player.setPosition(j, i);
				break;

			}
		}
	}
}

void Level::print(){
	cout << string(100, '\n');
	for (int i = 0; i < _levelData.size(); i++){
		printf("%s\n", _levelData[i].c_str());
	}
	printf("\n");
}

void Level::canMovePlayer(char input, Player &player){
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);
	char targetTile;

	switch (input){
	case 'w':
	case 'W':
		// UP
		processPlayerMove(player, playerX, playerY - 1);
		break;
	case 's':
	case 'S':
		// DOWN
		processPlayerMove(player, playerX, playerY + 1);
		break;
	case 'a':
	case 'A':
		// LEFT
		processPlayerMove(player, playerX - 1, playerY);
		break;
	case 'd':
	case 'D':
		// RIGHT
		processPlayerMove(player, playerX + 1, playerY);
		break;
	default:
		printf("Invalid input\n");
		system("PAUSE");
		break;
	}
}

char Level::getTile(int x, int y){
	return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile){
	_levelData[y][x] = tile;
}

void Level::processPlayerMove(Player &player, int targetX, int targetY){
	int playerX, playerY;
	player.getPosition(playerX, playerY);
	char targetTile = getTile(targetX, targetY);

	switch (targetTile){
	case '.':
		player.setPosition(targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, 'P');
	}
}