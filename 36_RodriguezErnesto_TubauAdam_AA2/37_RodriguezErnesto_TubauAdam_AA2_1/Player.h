#pragma once
#include "Map.h"

class Player
{
public:
	int xPos, yPos;
	int score = 0;
	bool newGame = false;
	Player();
	void movePlayer(int, char**);
};
