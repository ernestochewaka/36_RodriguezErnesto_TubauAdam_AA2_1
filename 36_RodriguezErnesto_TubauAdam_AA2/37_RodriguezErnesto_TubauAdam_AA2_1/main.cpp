#include "Map.h"
#include "Player.h"
#include "Enemy.h"

void sleep(int speed) { Sleep(speed); }

int lifes = 3;
bool paused = false;

void pause()
{
	if (!paused)
	{
		paused = true;
	}

	else if (paused)
	{
		paused = false;
	}
}

int main()
{
	char start;
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	std::cout << "INIT" << std::endl;
	Map map;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	std::cout << "PRESS 1 TO START GAME" << std::endl;
	std::cin >> start;

	Player player;
	Enemy1 enemy1;
	Enemy2 enemy2;
	Enemy3 enemy3;

	int speed = 50;

	if (start == '1') {
		map.endGame = false;
	}
	else
	{
		main();
	}

	while (!map.endGame)
	{
		srand(time(NULL));
		bool up = false;
		bool down = false;
		bool left = false;
		bool right = false;

		if (!paused)
		{
			if (GetAsyncKeyState(VK_UP))
			{
				up = true;
			}
			else if (GetAsyncKeyState(VK_DOWN))
			{

				down = true;
			}
			else if (GetAsyncKeyState(VK_LEFT))
			{
				left = true;
			}
			else if (GetAsyncKeyState(VK_RIGHT))
			{
				right = true;
			}
			else if (GetAsyncKeyState(VK_ESCAPE))
			{
				map.endGame = true;;
			}
		}
		if (GetAsyncKeyState(0x50))
		{
			pause();
		}
		if (!paused)
		{
			system("cls");
			std::cout << "PLAYING" << std::endl;
			map.updateBoard();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			std::cout << "SCORE: " << player.score << std::endl;
			std::cout << "LIFES: " << lifes << std::endl;

			sleep(speed);

			if (up)
			{
				player.movePlayer(1, map.md);
				enemy1.moveEnemy1(1, map.md);
				enemy2.moveEnemy2(1, map.md);
				enemy3.moveEnemy3(enemy3.dir, map.md);
			}
			if (down)
			{
				player.movePlayer(2, map.md);
				enemy1.moveEnemy1(2, map.md);
				enemy2.moveEnemy2(2, map.md);
				enemy3.moveEnemy3(enemy3.dir, map.md);
			}
			if (left)
			{
				player.movePlayer(3, map.md);
				enemy1.moveEnemy1(3, map.md);
				enemy2.moveEnemy2(3, map.md);
				enemy3.moveEnemy3(enemy3.dir, map.md);
			}
			if (right)
			{
				player.movePlayer(4, map.md);
				enemy1.moveEnemy1(4, map.md);
				enemy2.moveEnemy2(4, map.md);
				enemy3.moveEnemy3(enemy3.dir, map.md);
			}

			if (player.newGame) {
				player.newGame = false;
				lifes--;
				system("cls");
				main();
			}

			if (lifes == 0)
			{
				map.gameOver();
			}
		}
		else if (paused) {
			system("cls");
			std::cout << "PAUSED" << std::endl;
			map.updateBoard();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			std::cout << "SCORE: " << player.score << std::endl;
			std::cout << "LIFES: " << lifes << std::endl;
		}
	}
	return 0;
}