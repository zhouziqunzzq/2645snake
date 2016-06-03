#pragma once
#ifndef _DIRECTION_
#define _DIRECTION_
enum direction  //上下左右四个方向的枚举型
{
	LEFT = 1,
	UP,
	RIGHT,
	DOWN,
	NOTCHANGE  //用于方向键返回值没有按下任何方向键的情况
};
#endif // !_DIRECTION_
