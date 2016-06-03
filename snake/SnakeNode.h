#pragma once
#include "direction.h"
class snake;
class SnakeNode  //蛇身节点类
{
public:
	SnakeNode();
	SnakeNode(int x, int y, direction d) :x(x), y(y), nowDr(d) {}
	~SnakeNode();
	friend snake;
	int getX() { return x; }
	int getY() { return y; }
private:
	int x;  //蛇节点的x坐标
	int y;  //蛇节点的y坐标
	direction nowDr;  //蛇节点的前进方向
};

