#pragma once
#include "snake.h"
#include "direction.h"
#include "Food.h"
#include "IDrawingHelper.h"
class GameControler  //游戏逻辑流程控制类
{
public:
	GameControler();
	GameControler(int x, int y) :mySnake(3, 3, 3), aFood(), maxX(x), maxY(y), score(0), dh(maxX,maxY)
	{ 
		aFood.getRandFood(x, y);
		dh.SetBorder("■");
		dh.SetFood("◎");
		dh.SetSnakeBody("○");
		dh.SetSnakeHead("●");
	}
	~GameControler();
	bool Looper();
private:
	int maxX;  //最大横坐标
	int maxY;  //最大纵坐标
	int score;  //当前游戏分数
	snake mySnake;  //玩家控制的蛇
	Food aFood;  //食物
	IDrawingHelper dh;  //图像绘制接口实例

	bool Judge();  //判断游戏是否结束
	void Update();  //更新状态
	direction GetArrowKey();  //获取按下的方向键方向
	void UpdateDr();  //使蛇转向
};

