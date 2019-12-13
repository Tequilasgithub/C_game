// 0006.cpp : 定义控制台应用程序的入口点。
//模拟细胞分裂
#include"stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "windows.h"
#include "time.h"
#include"time.h"
#define High 29
#define Width 120//游戏画面尺寸
void gotoxy(int x, int y);
void startup();
void show();
void update();
//全局变量
int cells[High][Width];//所有位置细胞生1或死0
void main()
{
	srand((unsigned)time(NULL));
	startup();
	while (1)
	{
		show();
		update();
	}
}

void gotoxy(int x, int y)//清屏
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
void startup()//数据初始化
{
	int i, j;
	for (i = 0; i<High; i++)
		for (j = 0; j<Width; j++)
		{
			cells[i][j] = (rand() % 80 > 78 ? 1 : 0);//随机产生活细胞
		}
}
void show()//初始界面
{
	gotoxy(0, 0);//清屏
	int i, j;
	for (i = 1; i <= High - 1; i++)
	{
		for (j = 1; j <= Width - 1; j++)
		{
			if (cells[i][j] == 1)
				printf("*");//活的细胞
			else
				printf(" ");//死细胞			
		}
		printf("\n");
	}
	Sleep(100);
}
void update()  // 与用户输入无关的更新
{
	int NewCells[High][Width]; // 下一帧的细胞情况
	int NeibourNumber; //统计邻居的个数
	int i, j;
	for (i = 1; i <= High - 1; i++)
	{
		for (j = 1; j <= Width - 1; j++)
		{
			NeibourNumber = cells[i - 1][j - 1] + cells[i - 1][j] + cells[i - 1][j + 1]
				+ cells[i][j - 1] + cells[i][j + 1] + cells[i + 1][j - 1] + cells[i + 1][j] + cells[i + 1][j + 1];//周围细胞数
			  if (NeibourNumber == 8)//如果周围细胞饱和则死亡
				NewCells[i][j] = 0;
			  else if ((NeibourNumber ==2)||(NeibourNumber == 5))//周围有两个或5个细胞则产生细胞
				NewCells[i][j] = 1;
			  else if (NeibourNumber >= 6)//周围有6或7个细胞则随机死亡
				  NewCells[i][j] = rand ()%2;
			  else  NewCells[i][j] = cells[i][j];//其他情况保持原情况
		}
	}

	for (i = 1; i <= High - 1; i++)
	{
		for (j = 1; j <= Width - 1; j++)
		{
			cells[i][j] = NewCells[i][j];//更新
		}
	}
}