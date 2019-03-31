#pragma once
#include "Map.h"

class Player
{
public:
	int xPos, yPos;
	int score = 0;
	Player();
	void movePlayer(int, char**);
};
#pragma once
