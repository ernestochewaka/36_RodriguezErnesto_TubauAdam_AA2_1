#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <Time.h>
#include "Player.h"

class Map
{
public:
	int columns;
	int rows;
	bool endGame;
	std::string mapStr;
	char **md;

	//Map();
	void initializeBoard();
	void updateBoard();

	//void gameOver();

	//Destructor
	//~Map();
};
