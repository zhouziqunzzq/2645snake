#pragma once

#include "direction.h"
#include "SnakeNode.h"
#include <list>

using namespace std;

class snake  //����
{
public:
	snake() :posX(0), posY(0), length(0), nowDir(RIGHT) {}
	snake(int x, int y, int length) :posX(x), posY(y), length(length), nowDir(RIGHT) { InitNodes(); }
	~snake();
	void Grow(int); //��β����x����
	void Go();  //����ǰ����1��
	void Turn(direction d) { nowDir = d; }  //��ת��
	int getX() { return posX; }
	int getY() { return posY; }
	direction getDr() { return nowDir; }
	list<SnakeNode>& getNodes() { return nodes; }
private:
	int posX;  //��ͷx���꣨��x�У�
	int posY;  //��ͷy���꣨��y�У�
	int length;  //������
	direction nowDir;  //��ǰǰ������
	list<SnakeNode> nodes;  //�߽ڵ�����
	void InitNodes();  //��ʼ���߽ڵ�
};
