#pragma once
#include "Player.h"
#include <time.h>

class Enemy1
{
	public:
		int xPos, yPos;
		char nextPos = '*';
		Enemy1();
		void moveEnemy1(int, char**);
};

class Enemy2
{
public:
	int xPos, yPos;
	char nextPos = '*';
	Enemy2();
	void moveEnemy2(int, char**);
};

class Enemy3
{
public:

	int xPos, yPos, counter;
	int dir = 2;
	bool up = false, down = false, left = false, right = false;
	char nextPos = '*';
	Enemy3();
	void moveEnemy3(int&, char**);
};
