#include "Food.h"
#include <ctime>
#include <cstdlib>
using namespace std;


Food::Food()
{
	x = 0, y = 0;
}


Food::~Food()
{
}

void Food::getRandFood(int maxX, int maxY)
{
	srand((unsigned int)time(0));
	x = rand() % maxX;
	y = rand() % maxY;
}
