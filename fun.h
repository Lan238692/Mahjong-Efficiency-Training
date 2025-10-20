#pragma once
class pat
{
public:
	pat()
	{
		type = -1;
		color = -1;
		param = -1;
		edge = 0;
	}
	int type;
	int color;
	int param;
	bool edge;
};
class pir
{
public:
	pir()
	{
		param = 0;
		color = -1;
		edge = 0;
	}
	int param;
	int color;
	bool edge;
};
void randomN(int t[], int n, int MAX);
void handAlloc(int pool[], int hand[], int dora[], int mount[]);
void sort(int t[], int size);
void checkcount(int hand[], int count[]);
void checkpair(int count[], pir pair[]);
void checkpattern(int count[], pat pattern[]);
bool checkSame(int count[], pir pair[], pat pattern[], int a, int b, int c, int d, int e);
bool checkRON(int count[], pir pair[], pat pattern[]);
void showWithMerge(int group[], int amount);
void showWithoutMerge(int group[], int amount);
void showSingleCard(int group[], int num);
//切出一张牌/立直/和牌/杠 ,返回值代表这是否为一个合法操作
int decision(int hand[], char input);
bool checkTenpai(int hand[], int except);
bool checkRon(int hand[]);
void printPat(pat pattern[]);
void printToi(pir pair[]);
void defineHand(int hand[]);