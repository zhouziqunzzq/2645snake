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
	//ǽ��x=0, x=maxX, y=0, y=maxY
	bool flag1 = !(nextX == 0 || nextX == maxX - 1 || nextY == 0 || nextY == maxY - 1);
	bool flag2 = true;  //flag1:�Ƿ�ײ��ǽ��,flag2:�Ƿ�ײ������
	list<SnakeNode>::iterator it = mySnake.getNodes().begin();
	for (; it != mySnake.getNodes().end(); ++it)
	{
		if (it->getX() == nextX && it->getY() == nextY)  //ײ������
		{
			flag2 = false;
			break;
		}
	}
	return flag1 && flag2;
}

void GameControler::Update()
{
	//������һ��
	mySnake.Go();
	//�ж��Ƿ�Ե�ʳ��
	if (mySnake.getX() == aFood.getX() && mySnake.getY() == aFood.getY())
	{
		mySnake.Grow(1);  //������
		score += 10;  //�ӷ�
		bool isGoodFood;  //ʳ���Ƿ�����ںϷ���λ��
		do
		{
			isGoodFood = false;  
			aFood.getRandFood(maxX, maxY);  //��ȡ��һ��ʳ�����λ��
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
	Update();
	dh.Draw(mySnake, aFood, score);
	//��λ�ȡ�����״̬��ʹ��ת��
	for (int i = 0; i < gameSpeed; ++i)
	{
		Pause();
		UpdateDr();
		Sleep(1);
	}
	return !Judge();
}

void GameControler::Pause()
{
	if (GetAsyncKeyState(VK_SPACE) < 0)
	{
		Sleep(1000);  //��֤����������
		while (GetAsyncKeyState(VK_SPACE) >= 0)
			Sleep(1);
		Sleep(1000);  //��֤����������
	}
}

direction GameControler::GetArrowKey()
{
	if (GetAsyncKeyState(VK_UP) < 0 || GetAsyncKeyState('W') < 0 || GetAsyncKeyState('K') < 0)
	{
		return UP;
	}
	if (GetAsyncKeyState(VK_DOWN) < 0 || GetAsyncKeyState('S') < 0 || GetAsyncKeyState('J') < 0)
	{
		return DOWN;
	}
	if (GetAsyncKeyState(VK_LEFT) < 0 || GetAsyncKeyState('A') < 0 || GetAsyncKeyState('H') < 0)
	{
		return LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT) < 0 || GetAsyncKeyState('D') < 0 || GetAsyncKeyState('L') < 0)
	{
		return RIGHT;
	}
	return NOTCHANGE;
}

void GameControler::UpdateDr()
{
	//��ȡ�����״̬��ʹ��ת��
	direction cmd = GetArrowKey();
	bool isReverse = false;  //�ж��Ƿ���
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