#include "Map.h"



/*Map::Map()
{
//initializeBoard();
}*/

void Map::initializeBoard()
{
	std::ifstream myFile("config.txt");

	char a;

	while (!myFile.eof())
	{
		myFile >> rows >> a >> columns >> a;
		std::getline(myFile, mapStr, ';');
	}

	myFile.close();
	//std::cout << mapStr;
	md = new char*[rows];
	for (int i = 0; i < rows; ++i)
		md[i] = new char[columns];

	for (int i = 0; i < rows; ++i) {
		for (int j = 1; j < columns + 1; ++j)
		{
			if (mapStr[i*(columns + 1) + j] == 'X')
				md[i][j] = 'X';
			else if (mapStr[i*(columns + 1) + j] == '*')
				md[i][j] = '*';
			else if (mapStr[i*(columns + 1) + j] == '*')
				md[i][j] = '*';
			else if (mapStr[i*(columns + 1) + j] == ' ')
				md[i][j] = ' ';
			else if (mapStr[i*(columns + 1) + j] == '>')
				md[i][j] = '>';
		}
	}
}
void Map::updateBoard()
{
	for (int i = 0; i < rows; ++i) {
		for (int j = 1; j < columns + 1; ++j)
		{
			std::cout << md[i][j];
		}
		std::cout << std::endl;
	}
}

