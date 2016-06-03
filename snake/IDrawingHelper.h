#pragma once
#include <string>
using namespace std;
class snake;
class Food;
class IDrawingHelper  //图像接口
{
public:
	IDrawingHelper();
	IDrawingHelper(int x, int y) :maxX(x), maxY(y) 
	{
		SetWindowSize(2 * x, y);
		SetCursorType(NOCURSOR);
	}
	~IDrawingHelper();
	void SetSnakeHead(string c) { snakeHead = c; }
	void SetSnakeBody(string c) { snakeBody = c; }
	void SetBorder(string c) { border = c; }
	void SetFood(string c) { food = c; }
	void Draw(snake&, Food&);  //画一帧
	void Clean();  //清除画面
private:
	string snakeHead;  //蛇头字符
	string snakeBody;  //蛇身字符
	string border;  //墙壁字符
	string food;  //食物字符
	int maxX;  //画板最大横坐标
	int maxY;  //画板最大纵坐标
	enum CURSOR_TYPE {
		NOCURSOR,
		SOLIDCURSOR,
		NORMALCURSOR
	};
	void SetCursorType(CURSOR_TYPE c);  //设置光标类型
	void Gotoxy(int x, int y);  //置光标位置
	int Getxy(char xy);  //获取光标位置
	void SetWindowSize(int x, int y);  //设置窗口大小
};

