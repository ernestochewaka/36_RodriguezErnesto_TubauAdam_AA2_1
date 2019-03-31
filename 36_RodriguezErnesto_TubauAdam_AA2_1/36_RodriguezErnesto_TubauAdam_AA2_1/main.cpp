#include "Map.h"
#include "Player.h"

void sleep(int speed) { Sleep(speed); }

int main()
{
	Map map;
	map.initializeBoard();
	Player player;

	int speed = 50;

	while (!map.endGame)
	{
		system("cls");
		//player.movePlayer();
		map.updateBoard();
		std::cout << "SCORE: " << player.score;
		sleep(speed);

		if (GetAsyncKeyState(VK_UP))
		{
			player.movePlayer(1, map.md);
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{

			player.movePlayer(2, map.md);
		}
		else if (GetAsyncKeyState(VK_LEFT))
		{
			player.movePlayer(3, map.md);
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			player.movePlayer(4, map.md);
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			//map.gameOver();
		}
	}

	return 0;
}