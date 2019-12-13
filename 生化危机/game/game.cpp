// game.cpp : 定义控制台应用程序的入口点。
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
	Pangbai("欢迎进入游戏世界！\n");
	Sleep(1000);
	Pangbai("请输入游戏ID\n");
	char gamename[]="自定义";
	scanf("%s", &gamename);
	Sleep(1000);
	system("cls");
	Pangbai("请使用-小-写-英-文-输-入-法\n以便获得良好的游戏体验！\n");
	Sleep(5000);
	system("cls");
	Pangbai("请选择游戏职业\nA.体育生\nB.学霸(敬请期待)\nC.游戏宅（敬请期待）\nD.旅行者（敬请期待）\n");
choosecareer:
	char career = getch();
	int careernum;
	Pangbai("亲爱的");
	printf("%s", gamename);
	if (career == 97)
	{
		char career[] = "体育生";
		careernum = 1;
		Pangbai(",您选择了 体育生\n");
	}
	else if (career == 98)
	{
		Pangbai("学霸路线还在开发，敬请期待QAQ\n");
		goto choosecareer;
		char career[] = "学霸";
		careernum = 2;
		Pangbai("您选择了 学霸\n");
	}
	else if (career == 99)
	{
		Pangbai("游戏宅路线还在开发，敬请期待QAQ\n");
		goto choosecareer;
		char career[] = "游戏宅";
		careernum = 3;
		Pangbai("您选择了 游戏宅\n");
	}
	else if (career == 100)
	{
		Pangbai("旅行者路线还在开发，敬请期待QAQ\n");
		goto choosecareer;
		char career[] = "旅行者";
		careernum = 4;
		Pangbai("您选择了 旅行者\n");
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
	printf("游戏开始！");
	Sleep(1000);
	system("cls");
	printf("GRA %d\tEXE %d/%d\tHP %d/%d\tMP %d/%d\tATK %d\tMONEY %d\tDEFENSE %d\n", gra, exe,exemax, hp, hpmax, mp, mpmax, atk, money, defense);
	Sleep(2000);
	int choosenum1 = 0;
choose1:
	switch (careernum)
	{
	case 1:
		Pangbai("啪!啪!啪啪!啪啪啪！被室友疯狂敲击键盘的声音吵醒。\nA.继续睡下\tB醒来下床\n");
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
				Pangbai("睁开了眼睛，寝室的灯光像往常一样昏暗，已经天黑了吗？\n我去！地板上满是血迹。\n更奇怪的是整个寝室安静得就像人都死光了一样。。。\n室友呢？\n从床上爬起。。。\n头痛欲裂。。。\n"); 
			goto jump1;
jump1_1:
			    Pangbai("被一道湛蓝的微光闪到了眼睛。\n一把漂亮的武士刀。\n刀身上刻着几个漂亮的汉字：二零一厂一七年三月三十日。\nA.拾起\tB.不管它\n");
				Sleep(1000);
choose1_3:
			char choose1_3 = getch();
			if (choose1_3 == 97)
			{
				Pangbai("获得道具：【神秘的武士刀】【S】。。。\n攻击力+2*等级\n");
				Sleep(1000);
				Shenmidewushidao(gra, atk);
				printf("GRA %d\tEXE %d/%d\tHP %d/%d\tMP %d/%d\tATK %d\tMONEY %d\tDEFENSE %d\n", gra, exe, exemax, hp, hpmax, mp, mpmax, atk, money, defense);
			}
			else if (choose1_3 == 98)
			{
				Pangbai("居然不要QAQ\n");
			}
			else
				goto choose1_3;
			Sleep(1000);
		}
		else if (choose1_1 == 98)
		{
			Pangbai("阿喵：妈蛋！又输了，不玩了不玩了，一群坑队友。\n曼宁：走啊，吃饭去，");
			printf("%s", gamename);
			Pangbai(",你来不来?\nA.来\tB.不来\n");
choose1_2:
			char choose1_2 = getch();
			if (choose1_2 == 97)
			{
				Pangbai("阿喵：不用了，我帮你打包。\n");

			}
			else if (choose1_2 == 98)
			{
				Pangbai("阿喵/曼宁：拜拜！\n");
			}
			else
				goto choose1_2;
			Sleep(1000);
			Pangbai("时间在流逝。。。");
			Sleep(5000);
			Pangbai("一个小时后。。。\n");
			Sleep(1000);
jump1:
			Pangbai("人去哪了？。。。\n天色暗了下来。。。\n伊莱文的书桌上放着一本奇怪的笔记。\n奇怪。。。\n我为什么要说奇怪的笔记？。。。\n因为笔记的封面上写着：‘奇怪的笔记’。。。\n获取道具【奇怪的笔记本】【S】。。。\n等级为五的倍数时获得技能。\n");
			Sleep(1000);
			if (choose1_1 == 97)
			goto jump1_1;
		}
		else
			goto choose1_1;
	}
	Pangbai("远处传来一声诡异的尖叫。。。\n真是瘆人。\n轰！。。。轰！。。。轰！。。。\n寝室的小木门受到了猛烈的撞击。\nA.开门\tB.不出声\n");
	system("pause");
	printf("未完待续\n");
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
