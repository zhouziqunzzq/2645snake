#include "IDrawingHelper.h"

#include "snake.h"
#include "Food.h"
#include "SnakeNode.h"

#include <Windows.h>
#include <string>
#include <sstream>
#include <list>
#include <iostream>

using namespace std;

IDrawingHelper::IDrawingHelper()
{
}


IDrawingHelper::~IDrawingHelper()
{
}

void IDrawingHelper::Draw(snake& s, Food& f)
{
	//画蛇头
	list<SnakeNode>::iterator it = s.getNodes().begin();
	Gotoxy(2 * it->getX(), it->getY());
	cout << snakeHead;
	++it;
	//画蛇身
	for (; it != s.getNodes().end(); ++it)
	{
		Gotoxy(2 * it->getX(), it->getY());
		cout << snakeBody;
	}
	//画食物
	Gotoxy(2 * f.getX(), f.getY());
	cout << food;
}

void IDrawingHelper::SetCursorType(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c)
	{
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void IDrawingHelper::Gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int IDrawingHelper::Getxy(char xy)
{
	HANDLE gh_std_out;
	gh_std_out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(gh_std_out, &bInfo);
	if (xy == 'y' || xy == 'Y')
		return	bInfo.dwCursorPosition.Y;
	else
		return bInfo.dwCursorPosition.X;
}

void IDrawingHelper::SetWindowSize(int x, int y)
{
	//string s1 = "mode con: cols=", s2 = " lines=";
	stringstream ss;
	string sx, sy;
	ss << x;
	ss >> sx;
	ss.clear();
	ss << y;
	ss >> sy;
	ss.clear();
	string cmd = "mode con: cols=" + sx + " lines=" + sy;
	//cout << cmd << endl;
	system(cmd.c_str());
}

void IDrawingHelper::Clean()
{
	system("cls");
}