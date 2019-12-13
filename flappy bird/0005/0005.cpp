// 0005.cpp : �������̨Ӧ�ó������ڵ㡣
//flappy bird
#include "stdafx.h"
#include"stdlib.h"
#include"conio.h"
#include"windows.h"
void starup();
void show();
void updatewithoutin();
void updatewithin();
//ȫ�ֱ���
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
void gotoxy(int x, int y)//����
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}   
void starup()//��ʼ��
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
void show()//��ʼ����
{
	gotoxy(0, 0);//����	
	int i, j;//�������
	for (i = 0; i<high; i++)
	{
		for (j = 0; j<width; j++)
		{
			if ((i == bird_y) && (j == bird_x))
				printf("*");//bird
			else if ((j == bar_x) && ((i<bar_ydown) || (i>bar_ytop)))
				printf("+");//bar
			else
				printf(" ");//��λ
		}
		printf("\n");
	}
	printf("Score��%d\n", score);//����
}
void updatewithoutin()//�Զ�ˢ��
{
	bird_y++;//����
	bar_x--;//ˮƽǰ��
	if (bird_x == bar_x)//����bar
	{
		if ((bird_y >= bar_ydown) && (bird_y <= bar_ytop))
			score++;//��ȫͨ��
		else//ײǽ
		{
			printf("game over\a\n");
			Sleep(10000);
			system("pause");
			exit(0);
		}
	}
	if (bar_x <= 0)//bar�ӽ�������ʧ
	{
		bar_x = width;
		int door = rand() % int(high*0.8);//����λ��
		bar_ydown = door - high / 10;
		bar_ytop = door + high / 10;//��������µ�bar
	}
	Sleep(150);//ˢ��ʱ��
}
void updatewithin()//�ֶ�ˢ��
{
	char input;
	if (kbhit())//�ж��Ƿ�������
	{
		input = getch();
		if (input == ' ')
		{
			bird_y = bird_y - 2;
		}//����ո�ʵ�ַ���
	}
}