// 0005.cpp : 定义控制台应用程序的入口点。
//flappy bird
#include "stdafx.h"
#include"stdlib.h"
#include"conio.h"
#include"windows.h"
void starup();
void show();
void updatewithoutin();
void updatewithin();
//全局变量
int high, width, bird_x, bird_y, bar_x, bar_ytop, bar_ydown, score;
int main()
{
	starup();
	while (1) 
	{
		show();
		updatewithoutin();
		updatewithin();
	}
    return 0;
}
void gotoxy(int x, int y)//清屏
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}   
void starup()//初始化
{
	high = 25;
	width = 20;
	bird_x = 3;
	bird_y = high / 2;
	bar_x = width;
	bar_ytop = high / 2;
	bar_ydown = high / 3;
	score = 0;
}
void show()//初始界面
{
	gotoxy(0, 0);//清屏	
	int i, j;//光标坐标
	for (i = 0; i<high; i++)
	{
		for (j = 0; j<width; j++)
		{
			if ((i == bird_y) && (j == bird_x))
				printf("*");//bird
			else if ((j == bar_x) && ((i<bar_ydown) || (i>bar_ytop)))
				printf("+");//bar
			else
				printf(" ");//空位
		}
		printf("\n");
	}
	printf("Score：%d\n", score);//分数
}
void updatewithoutin()//自动刷新
{
	bird_y++;//重力
	bar_x--;//水平前进
	if (bird_x == bar_x)//遇到bar
	{
		if ((bird_y >= bar_ydown) && (bird_y <= bar_ytop))
			score++;//安全通过
		else//撞墙
		{
			printf("game over\a\n");
			Sleep(10000);
			system("pause");
			exit(0);
		}
	}
	if (bar_x <= 0)//bar从界面中消失
	{
		bar_x = width;
		int door = rand() % int(high*0.8);//开口位置
		bar_ydown = door - high / 10;
		bar_ytop = door + high / 10;//随机出现新的bar
	}
	Sleep(150);//刷新时间
}
void updatewithin()//手动刷新
{
	char input;
	if (kbhit())//判断是否有输入
	{
		input = getch();
		if (input == ' ')
		{
			bird_y = bird_y - 2;
		}//输入空格实现飞行
	}
}