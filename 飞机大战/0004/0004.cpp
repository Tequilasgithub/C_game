// 0004.cpp : �������̨Ӧ�ó������ڵ㡣
//��ɻ�2.0

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
void gotoxy(int x, int y)//���ƹ��λ��
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
void starup()//��ʼ��
{
	high = 28;
	width = 40;//�ռ�
	plane_x = width / 2;
	plane_y = high / 2;//�ɻ�λ��
	bullet_x = plane_x;
	bullet_y = -1;//����λ��
	enemy_x = plane_x;
	enemy_y = 0;//�л�λ��
}
void show()
{
	gotoxy(0, 0);//���˲��ص����ϽǴﵽ���ŵ�����Ч��
	for (int i = 0; i < high; i++)//���������
	{
		for (int j = 0; j < width; j++)//������
		{
			if (((enemy_x == plane_x) && (enemy_y == plane_y)) || ((enemy_y == plane_y + 1) && ((enemy_x >= plane_x - 2) && (enemy_x <= plane_x + 2))))//��л���ײ
				printf("game over"),Sleep(999999999999999);//��Ϸ����
			if ((j == plane_x) && (i == plane_y))printf("*");
			else if ((j == plane_x - 2) && (i == plane_y + 1))printf("*****");
			else if ((j == plane_x - 1) && (i == plane_y + 2))printf("* *");//�ɻ�ģ��
			else if ((j == enemy_x) && (i == enemy_y))printf("+");//�л�
			else if ((i == bullet_y && (j == bullet_x)))printf("|");//����
			else printf(" ");//��λ
		}
		printf("\n");
	}
	printf("Score=%d", score);//����
}
void updatewhioutin()//�Զ�ˢ��
{
	if (bullet_y > -1)bullet_y--;//�ӵ�ˢ��λ��
	if ((bullet_x == enemy_x) && ((bullet_y+1 == enemy_y)|| (bullet_y == enemy_y)))//����
	{
		printf("\a");//��Ч
		score++;//�ӷ�
		enemy_y = -1;
		enemy_x = rand() % width;//�л���ʼ��
		bullet_y = -2;//������ʼ��
	}
	if (enemy_y>high)//�л��ɳ���Ļ
	{
		enemy_y = -1;
		enemy_x = rand() % width;//��ʼ��
	}
	static int speed = 0;//���Ƶл��ٶ�
	if (speed < 8)speed++;
	if (speed == 8)
	{
		enemy_y++;
		speed = 0;
	}
}
void updatewithin()//�ֶ�ˢ��
{
	char input;
	if (kbhit())//�ж��Ƿ��м��̲���
	{
		input = getch();
		if (input == 'a')plane_x--;
		if (input == 's')plane_y++;
		if (input == 'd')plane_x++;
		if (input == 'w')plane_y--;//aswd���Ʒɻ��ƶ�
		if (input == ' ')
		{
			bullet_x = plane_x;
			bullet_y = plane_y - 1;
			printf("\a");
		}//�ո���ƿ���
	}
}