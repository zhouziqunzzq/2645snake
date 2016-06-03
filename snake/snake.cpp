#include "snake.h"
#include "SnakeNode.h"
#include <list>
using namespace std;



void snake::InitNodes()
{
	int tx = posX, ty = posY;
	for (int i = 0; i < length; ++i)
	{
		if (nowDir == LEFT)
		{
			SnakeNode anode(tx++, ty, LEFT);
			nodes.push_back(anode);
		}
		else if (nowDir == UP)
		{
			SnakeNode anode(tx, ty++, UP);
			nodes.push_back(anode);
		}
		else if (nowDir == RIGHT)
		{
			SnakeNode anode(tx--, ty, RIGHT);
			nodes.push_back(anode);
		}
		else if (nowDir == DOWN)
		{
			SnakeNode anode(tx, ty--, DOWN);
			nodes.push_back(anode);
		}
	}
}

void snake::Grow(int l)
{
	length += l;
	direction lastDr = nodes.back().nowDr;
	int tx = nodes.back().x;
	int ty = nodes.back().y;
	for (int i = 0; i < l; ++i)
	{
		if (lastDr == LEFT)
		{
			SnakeNode anode(tx++, ty, lastDr);
			nodes.push_back(anode);
		}
		else if (lastDr == RIGHT)
		{
			SnakeNode anode(tx--, ty, lastDr);
			nodes.push_back(anode);
		}
		else if (lastDr == UP)
		{
			SnakeNode anode(tx, ty++, lastDr);
			nodes.push_back(anode);
		}
		else if (lastDr == DOWN)
		{
			SnakeNode anode(tx, ty--, lastDr);
			nodes.push_back(anode);
		}
	}
}

void snake::Go()
{
	//加头
	if (nowDir == LEFT)
	{
		SnakeNode newNode(--posX, posY, nowDir);
		nodes.push_front(newNode);
	}
	else if (nowDir == RIGHT)
	{
		SnakeNode newNode(++posX, posY, nowDir);
		nodes.push_front(newNode);
	}
	else if (nowDir == UP)
	{
		SnakeNode newNode(posX, --posY, nowDir);
		nodes.push_front(newNode);
	}
	else if (nowDir == DOWN)
	{
		SnakeNode newNode(posX, ++posY, nowDir);
		nodes.push_front(newNode);
	}
	//去尾
	nodes.pop_back();
	//更新蛇节点的方向
	direction lastDr = nodes.front().nowDr;
	list<SnakeNode>::iterator it = nodes.begin();
	for (++it; it != nodes.end(); ++it)
	{
		direction tmpDr = it->nowDr;
		it->nowDr = lastDr;
		lastDr = tmpDr;
	}
}

snake::~snake()
{
}
