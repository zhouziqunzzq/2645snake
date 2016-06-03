#pragma once
class Food  //食物类
{
public:
	Food();
	~Food();
	void getRandFood(int maxX, int maxY);  //随机产生一个食物位置
	int getX() { return x; }
	int getY() { return y; }
private:
	int x;  //食物x坐标
	int y;  //食物y坐标
};

