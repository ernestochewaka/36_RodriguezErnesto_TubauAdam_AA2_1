#include "Map.h"


Map::Map()
{
	std::ifstream myFile("config.txt");

	char a;

	while (!myFile.eof())
	{
		myFile >> rows >> a >> columns>> a;
		std::getline(myFile, mapStr, '\0');
	}

	myFile.close();
	md = new char*[rows];
	for (int i = 0; i < rows; ++i)
		md[i] = new char[columns];

	for (int i = 0; i < rows; ++i) {
		for (int j = 1; j < columns + 1; ++j)
		{
			if (mapStr[i*(columns + 1) + j] == 'X') {
				md[i][j] = 'X';
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

			}
			else if (mapStr[i*(columns + 1) + j] == '*') {
				md[i][j] = '*';
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

			}
			else if (mapStr[i*(columns + 1) + j] == '>') 
			{
				md[i][j] = '>';
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}

			else if (mapStr[i*(columns + 1) + j] == ' ') {
				md[i][j] = ' ';
			}
			else if (mapStr[i*(columns + 1) + j] == '#') {
				md[i][j] = '#';
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

			}
			else if (mapStr[i*(columns + 1) + j] == '&') {
				md[i][j] = '&';
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);

			}
			else if (mapStr[i*(columns + 1) + j] == '$') {
				md[i][j] = '$';
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

			}
			else if (mapStr[i*(columns + 1) + j] == '0') {
				md[i][j] = '0';
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			}
			std::cout << md[i][j];
		}
		std::cout << std::endl;

	}
}

void Map::updateBoard()
{
	for (int i = 0; i < rows; ++i) {
		for (int j = 1; j < columns + 1; ++j)
		{
			if (md[i][j] == 'X') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			}
			else if (md[i][j] == '*') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			}
			else if (md[i][j] == '>') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else if (md[i][j] == '#') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			}
			else if (md[i][j] == '&') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			}
			else if (md[i][j] == '$') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			}
			else if (md[i][j] == '0') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			std::cout << md[i][j];
		}
		std::cout << std::endl;
	}
}

void Map::gameOver()
{

	system("cls");

	std::cout << "GAME OVER" << std::endl;
	std::cout << "ESC => EXIT" << std::endl;
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		endGame = true;
	}
	else gameOver();
}