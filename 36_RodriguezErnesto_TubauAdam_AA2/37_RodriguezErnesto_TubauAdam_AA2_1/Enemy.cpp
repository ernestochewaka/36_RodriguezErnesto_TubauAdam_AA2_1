#include "Enemy.h"

Enemy1::Enemy1()
{
	Map map;

	for (int i = 0; i < map.rows; ++i) {
		for (int j = 1; j < map.columns + 1; ++j)
		{
			if (map.md[i][j] == '&')
			{
				xPos = i;
				yPos = j;
			}
		}
	}
}

void Enemy1::moveEnemy1(int dir, char** md)
{
	if (dir == 3 && md[xPos][yPos - 1] != 'X')
	{
		md[xPos][yPos] = nextPos;

		if (md[xPos][yPos - 1] == '*')
			nextPos = '*';

		if (md[xPos][yPos - 1] == ' ')
			nextPos = ' ';

		if (md[xPos][yPos-1] == '0')
			nextPos = '0';

		yPos--;
		if (yPos == 0)
		{
			yPos = 19;
		}
	}
	else if (dir == 4 && md[xPos][yPos + 1] != 'X')
	{
		md[xPos][yPos] = nextPos;

		if (md[xPos][yPos + 1] == '*')
			nextPos = '*';

		if (md[xPos][yPos + 1] == ' ')
			nextPos = ' ';

		if (md[xPos][yPos+1] == '0')
			nextPos = '0';

		yPos++;
		if (yPos == 20)
		{
			yPos = 1;
		}
	}
	else if (dir == 2 && md[xPos + 1][yPos] != 'X')
	{
		md[xPos][yPos] = nextPos;

		if (md[xPos+1][yPos] == '*')
			nextPos = '*';

		if (md[xPos+1][yPos] == ' ')
			nextPos = ' ';

		if (md[xPos + 1][yPos] == '0')
			nextPos = '0';

		xPos++;
		if (xPos == 20)
		{
			xPos = 0;
		}

	}
	else if (dir == 1 && md[xPos - 1][yPos] != 'X')
	{
		md[xPos][yPos] = nextPos;

		if (md[xPos - 1][yPos] == '*')
			nextPos = '*';

		if (md[xPos - 1][yPos] == ' ')
			nextPos = ' ';

		if (md[xPos - 1][yPos] == '0')
			nextPos = '0';

		xPos--;
		if (xPos == 0)
		{
			xPos = 20;
		}
	}
	md[xPos][yPos] = '&';
}

Enemy2::Enemy2()
{
	Map map;

	for (int i = 0; i < map.rows; ++i) {
		for (int j = 1; j < map.columns + 1; ++j)
		{
			if (map.md[i][j] == '$')
			{
				xPos = i;
				yPos = j;
			}
		}
	}
}

void Enemy2::moveEnemy2(int dir, char** md)
{

	if (dir == 4 && md[xPos][yPos - 1] != 'X')
	{
		md[xPos][yPos] = nextPos;

		if (md[xPos][yPos - 1] == '*')
			nextPos = '*';

		if (md[xPos][yPos - 1] == ' ')
			nextPos = ' ';

		if (md[xPos][yPos-1] == '0')
			nextPos = '0';

		yPos--;
		if (yPos == 0)
		{
			yPos = 19;
		}
	}
	else if (dir == 3 && md[xPos][yPos + 1] != 'X')
	{
		md[xPos][yPos] = nextPos;

		if (md[xPos][yPos + 1] == '*')
			nextPos = '*';

		if (md[xPos][yPos + 1] == ' ')
			nextPos = ' ';

		if (md[xPos][yPos+1] == '0')
			nextPos = '0';

		yPos++;
		if (yPos == 20)
		{
			yPos = 1;
		}
	}
	else if (dir == 1 && md[xPos + 1][yPos] != 'X')
	{
		md[xPos][yPos] = nextPos;

		if (md[xPos + 1][yPos] == '*')
			nextPos = '*';

		if (md[xPos + 1][yPos] == ' ')
			nextPos = ' ';

		if (md[xPos + 1][yPos] == '0')
			nextPos = '0';

		xPos++;
		if (xPos == 20)
		{
			xPos = 0;
		}

	}
	else if (dir == 2 && md[xPos - 1][yPos] != 'X')
	{
		md[xPos][yPos] = nextPos;

		if (md[xPos - 1][yPos] == '*')
			nextPos = '*';

		if (md[xPos - 1][yPos] == ' ')
			nextPos = ' ';

		if (md[xPos - 1][yPos] == '0')
			nextPos = '0';

		xPos--;
		if (xPos == 0)
		{
			xPos = 20;
		}
	}
	md[xPos][yPos] = '$';
}

Enemy3::Enemy3()
{
	Map map;

	for (int i = 0; i < map.rows; ++i) {
		for (int j = 1; j < map.columns + 1; ++j)
		{
			if (map.md[i][j] == '#')
			{
				xPos = i;
				yPos = j;
			}
		}
	}
}

void Enemy3::moveEnemy3(int &dir, char** md)
{
	if (dir == 3)
	{
		right = false;
		if (md[xPos][yPos - 1] != 'X') 
		{
			md[xPos][yPos] = nextPos;

			if (md[xPos][yPos - 1] == '*')
				nextPos = '*';

			if (md[xPos][yPos - 1] == ' ')
				nextPos = ' ';

			if (md[xPos][yPos-1] == '0')
				nextPos = '0';

			yPos--;
			if (yPos == 0)
			{
				yPos = 19;
			}

			if (md[xPos - 1][yPos] != 'X')
			{
				up = true;
			}
			else if (md[xPos + 1][yPos] != 'X')
			{
				down = true;
			}

			if (up&&down)
			{
				dir = (rand() % 2);
				if (dir == 0)
				{
					left = false;
					dir = 1;
				}

				if (dir == 1)
				{
					left = false;
					dir = 2;
				}

				if (dir == 2)
					dir = 3;
			}

			if (up&&!down)
			{
				dir = (rand() % 1);
				if (dir == 0)
				{
					left = false;
					dir = 1;
				}

				if (dir == 1)
					dir = 3;
			}
			if(down&&!up)
			{ 
				dir = (rand() % 1);
				if (dir == 0)
				{
					left = false;
					dir = 2;
				}

				if (dir == 1)
					dir = 3;
			}
			
			if (!up && !down)
				dir = 3;

			}
		else
		{
			left = false;

			if (up&&!down)
			{
				dir = 1;
			}
			if (down&&!up)
			{
				dir = 2;
			}
			if (up&&down)
			{
				dir = (rand() % 1);
				if (dir == 0)
					dir = 1;

				if (dir == 1)
					dir = 2;
			}
		}
	}
	else if (dir == 4)
	{
		left = false;
		if (md[xPos][yPos + 1] != 'X') {
			md[xPos][yPos] = nextPos;

			if (md[xPos][yPos + 1] == '*')
				nextPos = '*';

			if (md[xPos][yPos + 1] == ' ')
				nextPos = ' ';

			if (md[xPos][yPos+1] == '0')
				nextPos = '0';

			yPos++;
			if (yPos == 20)
			{
				yPos = 1;
			}
			if (md[xPos - 1][yPos] != 'X')
			{
				up = true;
			}
			else if (md[xPos + 1][yPos] != 'X')
			{
				down = true;
			}

			if (up)
			{
				dir = (rand() % 1);
				if (dir == 0)
				{
					right = false;
					dir = 1;
				}

				if (dir == 1)
					dir = 4;
			}
			if (down)
			{
				dir = (rand() % 1);
				if (dir == 0)
				{
					right = false;
					dir = 2;
				}

				if (dir == 1)
					dir = 4;
			}
			if (up&&down)
			{
				dir = (rand() % 2);
				if (dir == 0)
				{
					right = false;
					dir = 1;
				}

				if (dir == 1)
				{
					right = false;
					dir = 2;
				}

				if (dir == 2)
					dir = 4;
			}
			if (!up && !down)
				dir = 4;
		}
		else
		{
			
			right = false;
		
			if (up)
			{
				dir = 1;
			}
			if (down)
			{
				dir = 2;
			}
			if (up&&down)
			{
				dir = (rand() % 1);
				if (dir == 0)
					dir = 1;

				if (dir == 1)
					dir = 2;
			}
		}
	}
	else if (dir == 1 )
	{
		down = false;
		if (md[xPos - 1][yPos] != 'X') {
			md[xPos][yPos] = nextPos;

			if (md[xPos - 1][yPos] == '*')
				nextPos = '*';

			if (md[xPos - 1][yPos] == ' ')
				nextPos = ' ';

			if (md[xPos - 1][yPos] == '0')
				nextPos = '0';

			xPos--;
			if (xPos == 20)
			{
				xPos = 0;
			}
			if (md[xPos][yPos-1] != 'X')
			{
				left = true;
			}
			else if (md[xPos][yPos+1] != 'X')
			{
				right = true;
			}

			if (left)
			{
				dir = (rand() % 1);
				if (dir == 0)
					dir = 1;

				if (dir == 1)
				{
					up = false;
					dir = 3;
				}
			}
			if (right)
			{
				dir = (rand() % 1);
				if (dir == 0)
					dir = 1;

				if (dir == 1)
				{
					up = false;
					dir = 4;
				}
			}
			if (left&&right)
			{
				dir = (rand() % 2);
				if (dir == 0)
					dir = 1;

				if (dir == 1)
				{
					up = false;
					dir = 4;
				}

				if (dir == 2)
				{
					up = false;
					dir = 3;
				}
			}
			if (!left && !right)
				dir = 1;
		}
		else
		{
			
			up = false;

			if (left)
			{
				dir = 3;
			}
			if (right)
			{
				dir = 4;
			}
			if (left&&right)
			{
				dir = (rand() % 1);
				if (dir == 0)
					dir = 3;

				if (dir == 1)
					dir = 4;
			}
		}
	}
	else if (dir == 2)
	{
		up = false;
		if(md[xPos + 1][yPos] != 'X')
		{
			md[xPos][yPos] = nextPos;

			if (md[xPos + 1][yPos] == '*')
				nextPos = '*';

			if (md[xPos + 1][yPos] == ' ')
				nextPos = ' ';

			if (md[xPos + 1][yPos] == '0')
				nextPos = '0';

			xPos++;
			if (xPos == 0)
			{
				xPos = 20;
			}
			if (md[xPos][yPos - 1] != 'X')
			{
				left = true;
			}
			else if (md[xPos][yPos + 1] != 'X')
			{
				right = true;
			}

			if (left)
			{
				dir = (rand() % 1);
				if (dir == 0)
					dir = 2;

				if (dir == 1)
				{
					down = false;
					dir = 3;
				}
			}
			if (right)
			{
				dir = (rand() % 1);
				if (dir == 0)
					dir = 2;

				if (dir == 1)
				{
					down = false;
					dir = 4;
				}
			}
			if (left&&right)
			{
				dir = (rand() % 2);
				if (dir == 0)
					dir = 2;

				if (dir == 1)
				{
					down = false;
					dir = 4;
				}

				if (dir == 2)
				{
					down = false;
					dir = 3;
				}
			}
			if (!left && !right)
				dir = 2;

		}
		else
		{
			
			down = false;
			if (left)
			{
				dir = 3;
			}
			if (right)
			{
				dir = 4;
			}
			if (left&&right)
			{
				dir = (rand() % 1);
				if (dir == 0)
					dir = 3;

				if (dir == 1)
					dir = 4;
			}
		}
	}
	md[xPos][yPos] = '#';
}