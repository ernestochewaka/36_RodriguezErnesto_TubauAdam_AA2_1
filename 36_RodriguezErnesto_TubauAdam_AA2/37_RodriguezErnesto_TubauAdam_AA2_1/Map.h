#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <Time.h>
#include "Player.h"

class Map
{
public:
	int columns;
	bool paused;
	int rows;
	bool endGame=true;
	std::string mapStr;
	char **md;

	Map();
	void updateBoard();
	void Paused();
	void gameOver();

	//Destructor
	//~Map();
};
