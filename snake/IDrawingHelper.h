#pragma once
#include <string>
using namespace std;
class snake;
class Food;
class IDrawingHelper  //ͼ��ӿ�
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
	void Draw(snake&, Food&);  //��һ֡
	void Clean();  //�������
private:
	string snakeHead;  //��ͷ�ַ�
	string snakeBody;  //�����ַ�
	string border;  //ǽ���ַ�
	string food;  //ʳ���ַ�
	int maxX;  //������������
	int maxY;  //�������������
	enum CURSOR_TYPE {
		NOCURSOR,
		SOLIDCURSOR,
		NORMALCURSOR
	};
	void SetCursorType(CURSOR_TYPE c);  //���ù������
	void Gotoxy(int x, int y);  //�ù��λ��
	int Getxy(char xy);  //��ȡ���λ��
	void SetWindowSize(int x, int y);  //���ô��ڴ�С
};

