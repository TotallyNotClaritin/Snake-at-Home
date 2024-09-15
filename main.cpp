#include <iostream>
#include <stdbool.h>

using namespace std;

//variables
bool gameLost;
int x, y, dotX, dotY, score;
enum snakeDir {STOP = 0, WEST, EAST, NORTH, SOUTH};
snakeDir dir;
//constants
const int width = 20;
const int height = 20;


void createGame()
{
	gameLost = false;
	dir = STOP;

	//Start in middle
	x = width / 2;
	y = height / 2;

	dotX = rand() % width; //0 to width - 1
	dotY = rand() % height; //0 to height - 1; if we're 0 indexed this is just right

	score = 0;
}

void Draw()
{
	//Northern Wall
	system("cls");
	for (int i = 0; i < width; i++)
		cout << "—";
	cout << endl;


	//West and East Walls
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "|";
			else
				cout << " ";
			if (j == width - 1)
				cout << "|";
		}

	}

	//Southern Wall
	for (int i = 0; i < width; i++)
		cout << "—";
	cout << endl;
}

void Control()
{

}

void gameLogic()
{

}

int main()
{
	createGame();
	while (!gameLost)
	{
		Draw();
		Control();
		gameLogic();
		//sleep(5); How slow do we need to go?
	}

}