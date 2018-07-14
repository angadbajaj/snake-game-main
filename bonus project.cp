// bonus project.cpp : Defines the entry point for the console application.

#include"stdafx.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
class Obstacle
{
public:
	int obstacleX;
	int obstacleY;
	public:
	Obstacle()
	{
		obstacleX=rand()%width;
		obstacleY=rand()%height;
	}
	void printObstacle(int i, int j)
	{
				if (i == obstacleY && j == obstacleX)
					cout << "*";
	}
};

class Bonus
{
public:
	int bonusX;
	int bonusY;
public:
	Bonus()
	{
		bonusX=rand()%width;
		bonusY=rand()%height;
	}
	void printBonus(int i, int j)
	{
				if (i == bonusY && j == bonusX)
					cout << "@";
	}
};
Bonus bonus;
Obstacle obstacle1;
Obstacle obstacle2;
Obstacle obstacle3;
void Setup()
{
 gameOver = false;
 dir = STOP;
 x = width / 2;
 y = height / 2;
 fruitX = rand() % width;
 fruitY = rand() % height;
 score = 0;
}
void Draw()
{
 system("cls"); //system("clear");
 for (int i = 0; i < width+3; i++)
 cout << "#";
 cout << endl;
 
 for (int i = 0; i < height; i++)
 {
 for (int j = 0; j < width; j++)
 {
 bonus.printBonus(i,j);
 obstacle1.printObstacle(i,j);
 obstacle2.printObstacle(i,j);
 obstacle3.printObstacle(i,j);
 if (j == 0)
 cout << "#";
 if (i == y && j == x)
 cout << "O";
 else if (i == fruitY && j == fruitX)
 cout << "F";
 else
 {
 bool print = false;
 for (int k = 0; k < nTail; k++)
 {
 if (tailX[k] == j && tailY[k] == i)
 {
 cout << "o";
 print = true;
 }
 }
 if (!print)
 cout << " ";
 }
 

 if(j == width - 1 && i == obstacle1.obstacleY)
	  cout<<"#";
 else if(j == width - 1 && i == obstacle2.obstacleY)
	  cout<<"#";
 else if(j == width - 1 && i == obstacle3.obstacleY)
	  cout<<"#";
 else if (j == width - 1 &&(i != bonus.bonusY && j != bonus.bonusX))
 cout << " #";
 else if(j == width - 1 && i == bonus.bonusY)
	 cout<<"#";
 
 }
 cout << endl;
 }

 


 
 for (int i = 0; i < width+3; i++)
 cout << "#";
 cout << endl;
 cout << "Score:" << score << endl;
}
void Input()
{
 if (_kbhit())
 {
 switch (_getch())
 {
 case 'a':
 dir = LEFT;
 break;
 case 'd':
 dir = RIGHT;
 break;
 case 'w':
 dir = UP;
 break;
 case 's':
 dir = DOWN;
 break;
 case 'x':
 gameOver = true;
 break;
 }
 }
}
void Logic()
{
 int prevX = tailX[0];
 int prevY = tailY[0];
 int prev2X, prev2Y;
 tailX[0] = x;
 tailY[0] = y;
 for (int i = 1; i < nTail; i++)
 {
 prev2X = tailX[i];
 prev2Y = tailY[i];
 tailX[i] = prevX;
 tailY[i] = prevY;
 prevX = prev2X;
 prevY = prev2Y;
 }
 switch (dir)
 {
 case LEFT:
 x--;
 break;
 case RIGHT:
 x++;
 break;
 case UP:
 y--;
 break;
 case DOWN:
 y++;
 break;
 default:
 break;
 }
 //if (x > width || x < 0 || y > height || y < 0)
 // gameOver = true;
 if (x >= width) x = 0; else if (x < 0) x = width - 1;
 if (y >= height) y = 0; else if (y < 0) y = height - 1;
 
 for (int i = 0; i < nTail; i++)
 if (tailX[i] == x && tailY[i] == y)
 gameOver = true;
 
 if (x == obstacle1.obstacleX && y == obstacle1.obstacleY)
	 gameOver = true;
 if (x == obstacle2.obstacleX && y == obstacle2.obstacleY)
	 gameOver = true;
  if (x == obstacle3.obstacleX && y == obstacle3.obstacleY)
	 gameOver = true;
 if (x == fruitX && y == fruitY)
 {
 score += 10;
 fruitX = rand() % width;
 fruitY = rand() % height;
 nTail++;
 }
 if (x == bonus.bonusX && y == bonus.bonusY)
 {
 score += 15;
 bonus.bonusX = rand() % width;
 bonus.bonusY = rand() % height;
 nTail=nTail+2;
 }
}
int main()
{
	cout<<"Game Rules: "<<endl;
	cout<<"'F' is normal food: you get 10 points for eating F"<<endl;
	cout<<"'@' is super food: you get 15 points for eating @"<<endl;
	cout<<"If you touch '*', you die."<<endl;
	cout<<"NOTE: The Snake will curve Randomly. Be aware!"<<endl<<endl;
	int a;
	cout<<" What kind of game do you want to play?	"<<endl;
	cout<<" For Arcade, press 1 "<<endl<<" For classic, press 2 "<<endl<<" For Levels, press 3"<<endl;
	cin>> a;
	if(a>0 && a<=3)
	{
		if(a==2)	//old code game- classic
		{
 Setup();

 while (!gameOver)
 {
 Draw();

 Input();
 Logic();
 Sleep(10); //sleep(10);
 }
		}
		if(a==1)	
		{

 Setup();

 while (!gameOver)
 {
 Draw();
 Input();
 Logic();
 if(score>=0&&score<=30)
 Sleep(100);
 if(score>30&&score<=60)
 Sleep(50); 
 if(score>60&&score<=100)
 Sleep(25); 
 if(score>100)
 Sleep(5); 
 }
		}
		if(a==3)
		{
			system("cls");
			cout<<" Easy, Medium, or Hard? "<<endl<<"1:		For Easy"<<endl<<"2:		For Medium"<<endl<<"3:		For Hard"<<endl;
			int level;
			cin>>level;
			if(level==1)
			{
 Setup();

 while (!gameOver)
 {
 Draw();
 Input();
 Logic();
 Sleep(100);
 }
			}
			if(level==2)
			{
 Setup();

 while (!gameOver)
 {
 Draw();
 Input();
 Logic();
 Sleep(25);
 }
			}
			if(level==3)
			{
 Setup();

 while (!gameOver)
 {
 Draw();
 Input();
 Logic();
 Sleep(5);
 }
			}
		}
		
	}
	else
	{
		cout<<"input invalid, please enter again "<<endl;
		cin>> a;
	}

	return 0;
}
