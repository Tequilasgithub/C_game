// game.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include"stdafx.h"
#include"iostream"
#include"windows.h"
#include "string"
void Pangbai(char pangbai[]);
int Shenmidewushidao(int gra, int atk);
#include "conio.h"


int main()
{
	int hp, hpmax, mp, mpmax, exe = 0,exemax, gra = 1, money = 0, atk = 1, defense = 0;
	Pangbai("��ӭ������Ϸ���磡\n");
	Sleep(1000);
	Pangbai("��������ϷID\n");
	char gamename[]="�Զ���";
	scanf("%s", &gamename);
	Sleep(1000);
	system("cls");
	Pangbai("��ʹ��-С-д-Ӣ-��-��-��-��\n�Ա������õ���Ϸ���飡\n");
	Sleep(5000);
	system("cls");
	Pangbai("��ѡ����Ϸְҵ\nA.������\nB.ѧ��(�����ڴ�)\nC.��Ϸլ�������ڴ���\nD.�����ߣ������ڴ���\n");
choosecareer:
	char career = getch();
	int careernum;
	Pangbai("�װ���");
	printf("%s", gamename);
	if (career == 97)
	{
		char career[] = "������";
		careernum = 1;
		Pangbai(",��ѡ���� ������\n");
	}
	else if (career == 98)
	{
		Pangbai("ѧ��·�߻��ڿ����������ڴ�QAQ\n");
		goto choosecareer;
		char career[] = "ѧ��";
		careernum = 2;
		Pangbai("��ѡ���� ѧ��\n");
	}
	else if (career == 99)
	{
		Pangbai("��Ϸլ·�߻��ڿ����������ڴ�QAQ\n");
		goto choosecareer;
		char career[] = "��Ϸլ";
		careernum = 3;
		Pangbai("��ѡ���� ��Ϸլ\n");
	}
	else if (career == 100)
	{
		Pangbai("������·�߻��ڿ����������ڴ�QAQ\n");
		goto choosecareer;
		char career[] = "������";
		careernum = 4;
		Pangbai("��ѡ���� ������\n");
	}
	else
		goto choosecareer;
	switch (careernum)
	{
	case 1:hpmax = 50, mpmax = 10, atk = 5, defense = 1; break;
	case 2:hpmax = 30, mpmax = 40, atk = 3, defense = 1; break;
	case 3:hpmax = 30, mpmax = 20, atk = 7, defense = 1; break;
	case 4:hpmax = 40, mpmax = 30, atk = 3, defense = 1; break;
	}
	exemax = 5 * 2 ^ gra;
	hp = hpmax;
	mp = mpmax;
	Sleep(3000);
	system("cls");
	printf("3");
	Sleep(1000);
	system("cls");
	printf("2");
	Sleep(1000);
	system("cls");
	printf("1");
	Sleep(1000);
	system("cls");
	printf("��Ϸ��ʼ��");
	Sleep(1000);
	system("cls");
	printf("GRA %d\tEXE %d/%d\tHP %d/%d\tMP %d/%d\tATK %d\tMONEY %d\tDEFENSE %d\n", gra, exe,exemax, hp, hpmax, mp, mpmax, atk, money, defense);
	Sleep(2000);
	int choosenum1 = 0;
choose1:
	switch (careernum)
	{
	case 1:
		Pangbai("ž!ž!žž!žžž�������ѷ���û����̵��������ѡ�\nA.����˯��\tB�����´�\n");
choose1_1:
		char choose1_1 = getch();
		if (choose1_1 == 97)
		{
			choosenum1++;
			if (choosenum1 < 5)
			{
				goto choose1;
			}
			else
				Pangbai("�������۾������ҵĵƹ�������һ���谵���Ѿ��������\n��ȥ���ذ�������Ѫ����\n����ֵ����������Ұ����þ����˶�������һ��������\n�����أ�\n�Ӵ������𡣡���\nͷʹ���ѡ�����\n"); 
			goto jump1;
jump1_1:
			    Pangbai("��һ��տ����΢���������۾���\nһ��Ư������ʿ����\n�����Ͽ��ż���Ư���ĺ��֣�����һ��һ����������ʮ�ա�\nA.ʰ��\tB.������\n");
				Sleep(1000);
choose1_3:
			char choose1_3 = getch();
			if (choose1_3 == 97)
			{
				Pangbai("��õ��ߣ������ص���ʿ������S��������\n������+2*�ȼ�\n");
				Sleep(1000);
				Shenmidewushidao(gra, atk);
				printf("GRA %d\tEXE %d/%d\tHP %d/%d\tMP %d/%d\tATK %d\tMONEY %d\tDEFENSE %d\n", gra, exe, exemax, hp, hpmax, mp, mpmax, atk, money, defense);
			}
			else if (choose1_3 == 98)
			{
				Pangbai("��Ȼ��ҪQAQ\n");
			}
			else
				goto choose1_3;
			Sleep(1000);
		}
		else if (choose1_1 == 98)
		{
			Pangbai("�������走�������ˣ������˲����ˣ�һȺ�Ӷ��ѡ�\n�������߰����Է�ȥ��");
			printf("%s", gamename);
			Pangbai(",��������?\nA.��\tB.����\n");
choose1_2:
			char choose1_2 = getch();
			if (choose1_2 == 97)
			{
				Pangbai("�����������ˣ��Ұ�������\n");

			}
			else if (choose1_2 == 98)
			{
				Pangbai("����/�������ݰݣ�\n");
			}
			else
				goto choose1_2;
			Sleep(1000);
			Pangbai("ʱ�������š�����");
			Sleep(5000);
			Pangbai("һ��Сʱ�󡣡���\n");
			Sleep(1000);
jump1:
			Pangbai("��ȥ���ˣ�������\n��ɫ��������������\n�����ĵ������Ϸ���һ����ֵıʼǡ�\n��֡�����\n��ΪʲôҪ˵��ֵıʼǣ�������\n��Ϊ�ʼǵķ�����д�ţ�����ֵıʼǡ�������\n��ȡ���ߡ���ֵıʼǱ�����S��������\n�ȼ�Ϊ��ı���ʱ��ü��ܡ�\n");
			Sleep(1000);
			if (choose1_1 == 97)
			goto jump1_1;
		}
		else
			goto choose1_1;
	}
	Pangbai("Զ������һ������ļ�С�����\n���ǯ}�ˡ�\n�䣡�������䣡�������䣡������\n���ҵ�Сľ���ܵ������ҵ�ײ����\nA.����\tB.������\n");
	system("pause");
	printf("δ�����\n");
	system("pause");
	return 0;
}
void Pangbai(char pangbai[])
{
	for (int i = 0; i < strlen(pangbai); i++)
	{
		printf("%c", pangbai[i]);
		Sleep(100);
	}
}
int Shenmidewushidao(int gra, int atk)
{
	atk += 2 * gra;
	return atk;
}
