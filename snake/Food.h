#pragma once
class Food  //ʳ����
{
public:
	Food();
	~Food();
	void getRandFood(int maxX, int maxY);  //�������һ��ʳ��λ��
	int getX() { return x; }
	int getY() { return y; }
private:
	int x;  //ʳ��x����
	int y;  //ʳ��y����
};

