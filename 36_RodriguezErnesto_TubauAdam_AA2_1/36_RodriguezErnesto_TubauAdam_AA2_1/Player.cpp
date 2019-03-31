#include "Player.h"


Player::Player()
{
	Map map;
	map.initializeBoard();
	for (int i = 0; i < map.rows; ++i) {
		for (int j = 1; j < map.columns + 1; ++j)
		{
			if (map.md[i][j] == '>')
			{
				xPos = i;
				yPos = j;
			}
		}
	}
}

void Player::movePlayer(int dir, char** md)
{
	if (dir == 3 && md[xPos][yPos - 1] != 'X')
	{
		md[xPos][yPos] = ' ';
		if (md[xPos][yPos - 1] == '*')
			score++;

		yPos--;
		if (yPos == 0)
		{
			yPos = 19;
		}
	}
	else if (dir == 4 && md[xPos][yPos + 1] != 'X')
	{
		md[xPos][yPos] = ' ';
		if (md[xPos][yPos + 1] == '*')
			score++;

		yPos++;
		if (yPos == 20)
		{
			yPos = 1;
		}
	}
	else if (dir == 2 && md[xPos + 1][yPos] != 'X')
	{
		md[xPos][yPos] = ' ';
		if (md[xPos + 1][yPos] == '*')
			score++;

		xPos++;
		if (xPos == 20)
		{
			xPos = 0;
		}

	}
	else if (dir == 1 && md[xPos - 1][yPos] != 'X')
	{
		md[xPos][yPos] = ' ';
		if (md[xPos - 1][yPos] == '*')
			score++;

		xPos--;
		if (xPos == 0)
		{
			xPos = 20;
		}
	}
	md[xPos][yPos] = '>';
}
