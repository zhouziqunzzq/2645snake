﻿#include "GameControler.h"
#include <iostream>
#include <cstdio>
#include <locale>
#include <Windows.h>
using namespace std;

int main()
{
	//setlocale(LC_CTYPE, "");
	//wchar_t wc = '■';
	//cout << '■' << '❤' << '○' << '●' << endl;
	//wprintf(L"❤○●");
	//string s = "◎❉☪○●";
	//cout << s;
	//getchar();
	while (1)
	{
		GameControler gc(30, 15, 100);
		bool isOver = false;
		while (!isOver)
		{
			isOver = gc.Looper();
		}
	}
	
	return 0;
}