#pragma once
#include "direction.h"
class snake;
class SnakeNode  //����ڵ���
{
public:
	SnakeNode();
	SnakeNode(int x, int y, direction d) :x(x), y(y), nowDr(d) {}
	~SnakeNode();
	friend snake;
	int getX() { return x; }
	int getY() { return y; }
private:
	int x;  //�߽ڵ��x����
	int y;  //�߽ڵ��y����
	direction nowDr;  //�߽ڵ��ǰ������
};

