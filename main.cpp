#include <iostream>
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
	gameLost = False;
	dir = STOP;

	//Start in middle
	x = width / 2;
	y = height / 2;

	fruitX = rand() % width; //0 to width - 1
	fruitY = rand() % height; //0 to height - 1; if we're 0 indexed this is just right

	score = 0;
}

void Draw()
{
	//Northern Wall
	system("cls");
	for (int i = 0; i < width; i++)
		cout << "—";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j  = 0; j < weidth; j++)
			if (j == 0)
				cout << "|"
			else
				cout << " "
			if (j == width - 1)
				cout << "|"

	}

	//Southern Wall
	for (int i = 0; i < width; i++)
		cout << "—"

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
		Logic();
		//sleep(5); How slow do we need to go?
	}

}