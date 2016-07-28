#include "GameControler.h"
#include <iostream>
#include <cstdio>
#include <locale>
#include <Windows.h>
using namespace std;

int main()
{
	while (1)
	{
		system("cls");
		int gs = 0;
		do
		{
			cout << "Please input the gamespeed(number between 0 and 500):";
			cin >> gs;
		} while (gs < 0 || gs > 500);
		GameControler gc(30, 15, gs);
		bool isOver = false;
		while (!isOver)
		{
			isOver = gc.Looper();
		}
		cout << "Game over!";
		Sleep(1000);
	}
	
	return 0;
}