#pragma once

#include "direction.h"
#include "SnakeNode.h"
#include <list>

using namespace std;

class snake  //蛇类
{
public:
	snake() :posX(0), posY(0), length(0), nowDir(RIGHT) {}
	snake(int x, int y, int length) :posX(x), posY(y), length(length), nowDir(RIGHT) { InitNodes(); }
	~snake();
	void Grow(int); //蛇尾生长x长度
	void Go();  //蛇向前爬行1次
	void Turn(direction d) { nowDir = d; }  //蛇转向
	int getX() { return posX; }
	int getY() { return posY; }
	direction getDr() { return nowDir; }
	list<SnakeNode>& getNodes() { return nodes; }
private:
	int posX;  //蛇头x坐标（第x列）
	int posY;  //蛇头y坐标（第y行）
	int length;  //蛇身长度
	direction nowDir;  //当前前进方向
	list<SnakeNode> nodes;  //蛇节点链表
	void InitNodes();  //初始化蛇节点
};
