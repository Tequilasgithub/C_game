// 0004.cpp : 定义控制台应用程序的入口点。
//打飞机2.0

#include "stdafx.h"
#include"stdio.h"
#include"stdlib.h"
#include"conio.h"
#include"windows.h"
void gotoxy(int x, int y);
void starup();
void show();
void updatewhioutin();
void updatewithin();
int plane_x, plane_y, bullet_x, bullet_y, high, width, enemy_x, enemy_y, score;
void main()
{
	starup();
	while (1)
	{
		show();
		updatewhioutin();
		updatewithin();
	}
}
void gotoxy(int x, int y)//控制光标位置
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
void starup()//初始化
{
	high = 28;
	width = 40;//空间
	plane_x = width / 2;
	plane_y = high / 2;//飞机位置
	bullet_x = plane_x;
	bullet_y = -1;//弹道位置
	enemy_x = plane_x;
	enemy_y = 0;//敌机位置
}
void show()
{
	gotoxy(0, 0);//光标瞬间回到左上角达到更优的清屏效果
	for (int i = 0; i < high; i++)//光标纵坐标
	{
		for (int j = 0; j < width; j++)//横坐标
		{
			if (((enemy_x == plane_x) && (enemy_y == plane_y)) || ((enemy_y == plane_y + 1) && ((enemy_x >= plane_x - 2) && (enemy_x <= plane_x + 2))))//与敌机相撞
				printf("game over"),Sleep(999999999999999);//游戏结束
			if ((j == plane_x) && (i == plane_y))printf("*");
			else if ((j == plane_x - 2) && (i == plane_y + 1))printf("*****");
			else if ((j == plane_x - 1) && (i == plane_y + 2))printf("* *");//飞机模型
			else if ((j == enemy_x) && (i == enemy_y))printf("+");//敌机
			else if ((i == bullet_y && (j == bullet_x)))printf("|");//弹道
			else printf(" ");//空位
		}
		printf("\n");
	}
	printf("Score=%d", score);//分数
}
void updatewhioutin()//自动刷新
{
	if (bullet_y > -1)bullet_y--;//子弹刷新位置
	if ((bullet_x == enemy_x) && ((bullet_y+1 == enemy_y)|| (bullet_y == enemy_y)))//击中
	{
		printf("\a");//音效
		score++;//加分
		enemy_y = -1;
		enemy_x = rand() % width;//敌机初始化
		bullet_y = -2;//弹道初始化
	}
	if (enemy_y>high)//敌机飞出屏幕
	{
		enemy_y = -1;
		enemy_x = rand() % width;//初始化
	}
	static int speed = 0;//控制敌机速度
	if (speed < 8)speed++;
	if (speed == 8)
	{
		enemy_y++;
		speed = 0;
	}
}
void updatewithin()//手动刷新
{
	char input;
	if (kbhit())//判断是否有键盘操作
	{
		input = getch();
		if (input == 'a')plane_x--;
		if (input == 's')plane_y++;
		if (input == 'd')plane_x++;
		if (input == 'w')plane_y--;//aswd控制飞机移动
		if (input == ' ')
		{
			bullet_x = plane_x;
			bullet_y = plane_y - 1;
			printf("\a");
		}//空格控制开火
	}
}