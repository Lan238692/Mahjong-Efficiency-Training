// majang-game.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "fun.h"

void printLine()
{
	for (int i = 0; i < 40; i++)
		cout << '=';
	cout << endl;
}
void welcome()
{
	printLine();
	cout << endl;
	cout << "      欢迎来到  单人麻将练习游戏       " << endl;
	cout << "              按H进入教程              " << endl;
	cout << "          按其他任意键进入游戏         " << endl;
	cout << endl;
	printLine();
}
void tutorial()
{
	printLine();
	cout << endl;
	cout << "              这里是教程              " << endl;
	cout << "             麻将这玩意儿             " << endl;
	cout << "              有手就会打              " << endl;
	cout << "        教程结束，按任意键开始        " << endl<<endl;
	cout << "          空格键摸切，L键和牌         " << endl;
	cout << "       立直、杠和算番暂时还没做       " << endl;
	cout << endl;
	printLine();
	cout << endl;
}
void win()
{
	cout << endl;
	printLine();
	cout << endl << endl;
	printLine();
	cout << endl;
	cout << "                  和了              " << endl << endl;
	printLine();
	cout << endl;
}
void lose()
{
	printLine();
	cout << endl;
	cout << "                  流局              " << endl<<endl;
	printLine();
	cout << endl;
}
//single game
void gamestart()
{
	bool isRiichi = false;
	int pool[136];
	int hand[14];
	int dora[10];
	int valid_dora = 1;
	int mount[MOUNT];
	int left(MOUNT);
	randomN(pool, 13 + 10 + MOUNT, 136);
	handAlloc(pool, hand, dora, mount);
	sort(hand, 13);
	while (left>0)
	{
		left--;
		hand[13] = mount[MOUNT - left - 1];
		printLine();
		//defineHand(hand);
		cout << endl;
		cout << "  当前余牌： ";
		if (left < 10) cout << ' ';
		cout << left << "  Dora指示牌: ";
		showWithoutMerge(dora, valid_dora);
		cout << endl << endl;
		showWithMerge(hand, 13);
		cout << "  ";
		showSingleCard(hand, 13);
		cout << "  ";
		for (int i = 0; i < 14; i++)
		{
			if (checkTenpai(hand, i)&&isRiichi==false)
			{
				cout << "立直  ";
				break;
			}
		}
		if (checkRon(hand))
		{
			cout << "和  ";
		}

		while (true)
		{
			bool leave = false;
			char ch = _getch();
			int result = decision(hand, ch);
			switch (result)
			{
			case 1:
				leave = true;
				break;
			case 2:
				win();
				return;
			case 3:
				isRiichi = true;
				leave = true;
				break;
			default:
				break;
			}
			if (leave)
				break;
		}
		cout << endl << endl;
		printLine();
		cout << endl;
	}
	lose();
	char ch = _getch();
	return;
}
int main()
{
	welcome();
	char ch = _getch();
	if (ch == 'h')
	{
		cout << endl;
		tutorial();
		ch = _getch();
	}
	gamestart();
	while (_getch())
	{
		gamestart();
	}
	return 0;
}
