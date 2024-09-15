#include <iostream>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

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

	cout << "Score:" << score << endl;
	for (int i = 0; i < width+2; i++)
		cout << "#";
	cout << endl;


	//West and East Walls
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == y && j == x)
				cout << "0";
			else if (i == dotY && j == dotX)
				cout << "F";
			else
				cout << " ";
			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	//Southern Wall
	for (int i = 0; i < width+2; i++)
		cout << "#";
	cout << endl;
}

void Control()
{
	if (_kbhit())
	{
		//kbhit will go off if when a key is hit, if its a key we'll use to control the snake it'll change the direction
		switch (_getch())
		{
		case 'w':
			dir = NORTH;
			break;
		case 'a':
			dir = WEST;
			break;
		case 's':
			dir = SOUTH;
			break;
		case 'd':
			dir = EAST;
			break;
		//Just in case you need to abort the game
		case 'l':
			gameLost = true;
			break;
		default:
			break;
		}
	}
}

void gameLogic()
{
	switch (dir)
	{
	case NORTH:
		y--;
		break;
	case WEST:
		x--;
		break;
	case SOUTH:
		y++;
		break;
	case EAST:
		x++;
		break;
	default:
		break;
	}

	//loss condition: hitting the wall
	if (x > width || x < 0 || y > height || y < 0)
		gameLost = true;

	//score condition: get the dot, move it somewhere else!
	if (x == dotX && y == dotY)
	{
		score += 1;
		//move it if you get it
		dotX = rand() % width;
		dotY = rand() % height;
	}
}

void loserScreen()
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
		Sleep(10);
	}

}