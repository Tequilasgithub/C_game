// 0006.cpp : �������̨Ӧ�ó������ڵ㡣
//ģ��ϸ������
#include"stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "windows.h"
#include "time.h"
#include"time.h"
#define High 29
#define Width 120//��Ϸ����ߴ�
void gotoxy(int x, int y);
void startup();
void show();
void update();
//ȫ�ֱ���
int cells[High][Width];//����λ��ϸ����1����0
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

void gotoxy(int x, int y)//����
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
void startup()//���ݳ�ʼ��
{
	int i, j;
	for (i = 0; i<High; i++)
		for (j = 0; j<Width; j++)
		{
			cells[i][j] = (rand() % 80 > 78 ? 1 : 0);//���������ϸ��
		}
}
void show()//��ʼ����
{
	gotoxy(0, 0);//����
	int i, j;
	for (i = 1; i <= High - 1; i++)
	{
		for (j = 1; j <= Width - 1; j++)
		{
			if (cells[i][j] == 1)
				printf("*");//���ϸ��
			else
				printf(" ");//��ϸ��			
		}
		printf("\n");
	}
	Sleep(100);
}
void update()  // ���û������޹صĸ���
{
	int NewCells[High][Width]; // ��һ֡��ϸ�����
	int NeibourNumber; //ͳ���ھӵĸ���
	int i, j;
	for (i = 1; i <= High - 1; i++)
	{
		for (j = 1; j <= Width - 1; j++)
		{
			NeibourNumber = cells[i - 1][j - 1] + cells[i - 1][j] + cells[i - 1][j + 1]
				+ cells[i][j - 1] + cells[i][j + 1] + cells[i + 1][j - 1] + cells[i + 1][j] + cells[i + 1][j + 1];//��Χϸ����
			  if (NeibourNumber == 8)//�����Χϸ������������
				NewCells[i][j] = 0;
			  else if ((NeibourNumber ==2)||(NeibourNumber == 5))//��Χ��������5��ϸ�������ϸ��
				NewCells[i][j] = 1;
			  else if (NeibourNumber >= 6)//��Χ��6��7��ϸ�����������
				  NewCells[i][j] = rand ()%2;
			  else  NewCells[i][j] = cells[i][j];//�����������ԭ���
		}
	}

	for (i = 1; i <= High - 1; i++)
	{
		for (j = 1; j <= Width - 1; j++)
		{
			cells[i][j] = NewCells[i][j];//����
		}
	}
}