#include "GameControler.h"

#include <Windows.h>
#include "direction.h"
#include "snake.h"
#include "SnakeNode.h"
#include <list>

using namespace std;


GameControler::GameControler()
{
}


GameControler::~GameControler()
{
}

bool GameControler::Judge()
{
	int nextX = mySnake.getX(), nextY = mySnake.getY();
	switch (mySnake.getDr())
	{
	case LEFT:
		nextX--;
		break;
	case RIGHT:
		nextX++;
		break;
	case UP:
		nextY--;
		break;
	case DOWN:
		nextY++;
		break;
	default:
		break;
	}
	bool flag1 = nextX >= 0 && nextX < maxX && nextY >= 0 && nextY < maxY;
	bool flag2 = true;  //flag1:是否撞到墙壁,flag2:是否撞到身体
	list<SnakeNode>::iterator it = mySnake.getNodes().begin();
	for (; it != mySnake.getNodes().end(); ++it)
	{
		if (it->getX() == nextX && it->getY() == nextY)  //撞到身体
		{
			flag2 = false;
			break;
		}
	}
	return flag1 && flag2;
}

void GameControler::Update()
{
	//多次获取方向键状态并使蛇转向
	for (int i = 0; i < gameSpeed; ++i)
	{
		UpdateDr();
		Sleep(1);
	}
	//蛇爬行一次
	mySnake.Go();
	//判断是否吃到食物
	if (mySnake.getX() == aFood.getX() && mySnake.getY() == aFood.getY())
	{
		mySnake.Grow(1);  //蛇生长
		score += 10;  //加分
		bool isGoodFood;  //食物是否出现在合法的位置
		do
		{
			isGoodFood = false;  
			aFood.getRandFood(maxX, maxY);  //获取下一个食物随机位置
			list<SnakeNode>::iterator it = mySnake.getNodes().begin();
			for (; it != mySnake.getNodes().end(); ++it)
			{
				if (it->getX() == aFood.getX() && it->getY() == aFood.getY())
				{
					isGoodFood = true;
					break;
				}
			}
		} while (isGoodFood);
	}
}

bool GameControler::Looper()
{
	dh.Clean();
	dh.Draw(mySnake, aFood, score);
	Update();
	return !Judge();
}

direction GameControler::GetArrowKey()
{
	if (GetAsyncKeyState(VK_UP) < 0 || GetAsyncKeyState('W') < 0)
	{
		return UP;
	}
	if (GetAsyncKeyState(VK_DOWN) < 0 || GetAsyncKeyState('S') < 0)
	{
		return DOWN;
	}
	if (GetAsyncKeyState(VK_LEFT) < 0 || GetAsyncKeyState('A') < 0)
	{
		return LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT) < 0 || GetAsyncKeyState('D') < 0)
	{
		return RIGHT;
	}
	return NOTCHANGE;
}

void GameControler::UpdateDr()
{
	//获取方向键状态并使蛇转向
	direction cmd = GetArrowKey();
	bool isReverse = false;  //判断是否反向
	switch (cmd)
	{
	case LEFT:
		isReverse = mySnake.getDr() == RIGHT;
		break;
	case RIGHT:
		isReverse = mySnake.getDr() == LEFT;
		break;
	case UP:
		isReverse = mySnake.getDr() == DOWN;
		break;
	case DOWN:
		isReverse = mySnake.getDr() == UP;
		break;
	}
	if (cmd != NOTCHANGE && !isReverse)
		mySnake.Turn(cmd);
}