#include"pch.h"
#include"fun.h"

void swap(int t[], int p1, int p2)
{
	int temp = t[p1];
	t[p1] = t[p2];
	t[p2] = temp;
}
void randomN(int t[], int n, int MAX)
{
	srand(time(NULL));
	srand(rand());
	int* temp = new int[MAX];
	for (int i = 0; i < MAX; i++)
	{
		temp[i] = i + 1;
	}
	for (int i = 0; i < n; i++)
	{
		swap(temp, i, rand() % MAX);
	}
	for (int i = 0; i < n; i++)
	{
		t[i] = temp[i];
	}
}
void handAlloc(int pool[], int hand[], int dora[], int mount[])
{
	for (int i = 0; i < 13; i++)
	{
		hand[i] = pool[i];
	}
	hand[13] = 0;
	for (int i = 0; i < 10; i++)
	{
		dora[i] = pool[i + 13];
	}
	for (int i = 0; i < MOUNT; i++)
	{
		mount[i] = pool[i + 23];
	}
}
void sort(int t[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = t[i];
		int minp = i;
		for (int j = i + 1; j < size; j++)
		{
			if (t[j] < min)
			{
				min = t[j];
				minp = j;
			}
		}
		int temp = t[i];
		t[i] = min;
		t[minp] = temp;
	}
}
void checkcount(int hand[], int count[])
{
	for (int i = 0; i < 14; i++)
	{
		count[(hand[i] - 1) / 4]++;
	}
}
void checkpair(int count[], pir pair[])
{
	int rec = 0;
	for (int i = 0; i < 34; i++)
	{
		if (i < 9)
		{
			if (count[i] >= 2)
			{
				pair[rec].param = i + 1;
				if (i == 0 || i == 8)
				{
					pair[rec].edge = 1;
				}
				else
					pair[rec].edge = 0;
				pair[rec].color = MAN;
				rec++;
			}
			continue;
		}
		if (i < 18)
		{
			if (count[i] >= 2)
			{
				pair[rec].param = i + 1 - 9;
				if (i == 9 || i == 17)
				{
					pair[rec].edge = 1;
				}
				else
					pair[rec].edge = 0;
				pair[rec].color = PIN;
				rec++;
			}
			continue;
		}
		if (i < 27)
		{
			if (count[i] >= 2)
			{
				pair[rec].param = i + 1 - 18;
				if (i == 18 || i == 26)
				{
					pair[rec].edge = 1;
				}
				else
					pair[rec].edge = 0;
				pair[rec].color = SOU;
				rec++;
			}
			continue;
		}
		if (i < 31)
		{
			if (count[i] >= 2)
			{
				pair[rec].param = i + 1 - 27;
				pair[rec].edge = 1;
				pair[rec].color = FU;
				rec++;
			}
			continue;
		}
		if (i < 34)
		{
			if (count[i] >= 2)
			{
				pair[rec].param = i + 1 - 31;
				pair[rec].edge = 1;
				pair[rec].color = SANGEN;
				rec++;
			}
			continue;
		}
		cout << "error pair";
	}
}
void checkpattern(int count[], pat pattern[])
{
	int rec = 0;
	for (int i = 0; i < 34; i++)
	{
		if (i < 9)
		{
			if (count[i] >= 3)
			{
				pattern[rec].type = KOU;
				pattern[rec].param = i + 1;
				if (i == 0 || i == 8)
				{
					pattern[rec].edge = 1;
				}
				else
					pattern[rec].edge = 0;
				pattern[rec].color = MAN;
				rec++;
			}
			continue;
		}
		if (i < 18)
		{
			if (count[i] >= 3)
			{
				pattern[rec].type = KOU;
				pattern[rec].param = i + 1 - 9;
				if (i == 9 || i == 17)
				{
					pattern[rec].edge = 1;
				}
				else
					pattern[rec].edge = 0;
				pattern[rec].color = PIN;
				rec++;
			}
			continue;
		}
		if (i < 27)
		{
			if (count[i] >= 3)
			{
				pattern[rec].type = KOU;
				pattern[rec].param = i + 1 - 18;
				if (i == 18 || i == 26)
				{
					pattern[rec].edge = 1;
				}
				else
					pattern[rec].edge = 0;
				pattern[rec].color = SOU;
				rec++;
			}
			continue;
		}
		if (i < 31)
		{
			if (count[i] >= 3)
			{
				pattern[rec].type = KOU;
				pattern[rec].param = i + 1 - 27;
				pattern[rec].edge = 1;
				pattern[rec].color = FU;
				rec++;
			}
			continue;
		}
		if (i < 34)
		{
			if (count[i] >= 3)
			{
				pattern[rec].type = KOU;
				pattern[rec].param = i + 1 - 31;
				pattern[rec].edge = 1;
				pattern[rec].color = SANGEN;
				rec++;
			}
			continue;
		}
	}
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 7; i++)
		{
			if (count[j * 9 + i] >= 4 && count[j * 9 + i + 1] >= 4 && count[j * 9 + i + 2] >= 4)
			{
				pattern[rec].type = pattern[rec + 1].type = pattern[rec + 2].type = pattern[rec + 3].type = SHUN;
				pattern[rec].param = pattern[rec + 1].param = pattern[rec + 2].param = pattern[rec + 3].param = i + 1;
				pattern[rec].color = pattern[rec + 1].color = pattern[rec + 2].color = pattern[rec + 3].color = j;
				if (i == 0 || i == 6)
					pattern[rec].edge = 1;
				rec += 4;
			}
			else if (count[j * 9 + i] >= 3 && count[j * 9 + i + 1] >= 3 && count[j * 9 + i + 2] >= 3)
			{
				pattern[rec].type = pattern[rec + 1].type = pattern[rec + 2].type = SHUN;
				pattern[rec].param = pattern[rec + 1].param = pattern[rec + 2].param = i + 1;
				pattern[rec].color = pattern[rec + 1].color = pattern[rec + 2].color = j;
				if (i == 0 || i == 6)
					pattern[rec].edge = 1;
				rec += 3;
			}
			else if (count[j * 9 + i] >= 2 && count[j * 9 + i + 1] >= 2 && count[j * 9 + i + 2] >= 2)
			{
				pattern[rec].type = pattern[rec + 1].type = SHUN;
				pattern[rec].param = pattern[rec + 1].param = i + 1;
				pattern[rec].color = pattern[rec + 1].color = j;
				if (i == 0 || i == 6)
					pattern[rec].edge = 1;
				rec += 2;
			}
			else if (count[j * 9 + i] >= 1 && count[j * 9 + i + 1] >= 1 && count[j * 9 + i + 2] >= 1)
			{
				pattern[rec].type = SHUN;
				pattern[rec].param = i + 1;
				pattern[rec].color = j;
				if (i == 0 || i == 6)
					pattern[rec].edge = 1;
				rec += 1;
			}
		}
	}
}
bool checkSame(int count[], pir pair[], pat pattern[], int a, int b, int c, int d, int e)
{
	int temp[34] = { 0 };
	{
		if (pattern[a].type == SHUN)
		{
			if (pattern[a].param - 1 < 0 || pattern[a].param + 1 > 8)
			{
				cout << "error!" << endl;
			}
			temp[9 * pattern[a].color + pattern[a].param - 1]++;
			temp[9 * pattern[a].color + pattern[a].param]++;
			temp[9 * pattern[a].color + pattern[a].param + 1]++;
		}
		if(pattern[a].type==KOU)
		{
			if (pattern[a].color != SANGEN)
				temp[9 * pattern[a].color + pattern[a].param - 1] += 3;
			else
				temp[30 + pattern[a].param] += 3;
		}

		if (pattern[b].type == SHUN)
		{
			if (pattern[b].param - 1 < 0 || pattern[b].param + 1 > 8)
			{
				cout << "error!" << endl;
			}
			temp[9 * pattern[b].color + pattern[b].param - 1]++;
			temp[9 * pattern[b].color + pattern[b].param]++;
			temp[9 * pattern[b].color + pattern[b].param + 1]++;
		}
		if (pattern[b].type == KOU)
		{
			if (pattern[b].color != SANGEN)
				temp[9 * pattern[b].color + pattern[b].param - 1] += 3;
			else
				temp[30 + pattern[b].param] += 3;
		}

		if (pattern[c].type == SHUN)
		{
			if (pattern[c].param - 1 < 0 || pattern[c].param + 1 > 8)
			{
				cout << "error!" << endl;
			}
			temp[9 * pattern[c].color + pattern[c].param - 1]++;
			temp[9 * pattern[c].color + pattern[c].param]++;
			temp[9 * pattern[c].color + pattern[c].param + 1]++;
		}
		if (pattern[c].type == KOU)
		{
			if (pattern[c].color != SANGEN)
				temp[9 * pattern[c].color + pattern[c].param - 1] += 3;
			else
				temp[30 + pattern[c].param] += 3;
		}

		if (pattern[d].type == SHUN)
		{
			if (pattern[d].param - 1 < 0 || pattern[d].param + 1 > 8)
			{
				cout << "error!" << endl;
			}
			temp[9 * pattern[d].color + pattern[d].param - 1]++;
			temp[9 * pattern[d].color + pattern[d].param]++;
			temp[9 * pattern[d].color + pattern[d].param + 1]++;
		}
		if (pattern[d].type == KOU)
		{
			if (pattern[d].color != SANGEN)
				temp[9 * pattern[d].color + pattern[d].param - 1] += 3;
			else
				temp[30 + pattern[d].param] += 3;
		}

		if (pair[e].color != SANGEN)
			temp[9 * pair[e].color + pair[e].param - 1] += 2;
		else
			temp[30 + pair[e].param] += 2;

	}


	for (int i = 0; i < 34; i++)
	{
		if (temp[i] != count[i])
			return false;
	}


	return true;
}
bool checkRON(int count[], pir pair[], pat pattern[])
{
	if (pair[6].param != 0)
	{
		return true;
	}
	//param a,b,c,d,e mean 4*3+1*2
	for (int a = 0; pattern[a].param != -1; a++)
	{
		for (int b = a+1; pattern[b].param != -1; b++)
		{
			for (int c = b+1; pattern[c].param != -1; c++)
			{
				for (int d = c+1; pattern[d].param != -1; d++)
				{
					for (int e = 0; pair[e].param != 0; e++)
					{
						if (checkSame(count, pair, pattern, a, b, c, d, e))
						{
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}
void showWithoutMerge(int group[], int amount)
{
	for (int i = 0; i < amount; i++)
	{
		if (group[i] <= 36)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << (group[i] + 3) / 4 << 'm';
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
				FOREGROUND_GREEN | FOREGROUND_BLUE);
			continue;
		}
		if (group[i] <= 72)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
			cout << (group[i] - 36 + 3) / 4 << 'p';
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
				FOREGROUND_GREEN | FOREGROUND_BLUE);
			continue;
		}
		if (group[i] <= 108)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << (group[i] - 72 + 3) / 4 << 's';
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
				FOREGROUND_GREEN | FOREGROUND_BLUE);
			continue;
		}
		if (group[i] <= 112)
		{
			cout << "東";
			continue;
		}
		if (group[i] <= 116)
		{
			cout << "南";
			continue;
		}
		if (group[i] <= 120)
		{
			cout << "西";
			continue;
		}
		if (group[i] <= 124)
		{
			cout << "北";
			continue;
		}
		if (group[i] <= 128)
		{
			cout << "白";
			continue;
		}
		if (group[i] <= 132)
		{
			cout << "發";
			continue;
		}
		if (group[i] <= 136)
		{
			cout << "中";
			continue;
		}
	}
}
void showWithMerge(int group[], int amount)
{
	cout << "  ";
	for (int i = 0; i < amount; i++)
	{
		switch (i)
		{
		case 0:
			cout << '1';
			break;
		case 1:
			cout << '2';
			break;
		case 2:
			cout << '3';
			break;
		case 3:
			cout << '4';
			break;
		case 4:
			cout << '5';
			break;
		case 5:
			cout << '6';
			break;
		case 6:
			cout << '7';
			break;
		case 7:
			cout << '8';
			break;
		case 8:
			cout << '9';
			break;
		case 9:
			cout << '0';
			break;
		case 10:
			cout << 'A';
			break;
		case 11:
			cout << 'S';
			break;
		case 12:
			cout << 'D';
			break;
		default:
			break;
		}
		if (group[i] >= 109)
			cout << ' ';
		if (i == 12) break;
		if (group[i] <= 36 && group[i + 1] > 36) cout << ' ';
		if (group[i] <= 72 && group[i + 1] > 72) cout << ' ';
		if (group[i] <= 108 && group[i + 1] > 108) cout << ' ';
	}
	cout << endl << "  ";
	for (int i = 0; i < amount; i++)
	{
		if (group[i] <= 36)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << (group[i] + 3) / 4;
			if (i + 1 < amount)
			{
				if (group[i + 1] > 36)
					cout << 'm';
			}
			if (i + 1 == amount)
			{
				cout << 'm';
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
				FOREGROUND_GREEN | FOREGROUND_BLUE);
			continue;
		}
		if (group[i] <= 72)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
			cout << (group[i] - 36 + 3) / 4;
			if (i + 1 < amount)
			{
				if (group[i + 1] > 72)
					cout << 'p';
			}
			if (i + 1 == amount)
			{
				cout << 'p';
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
				FOREGROUND_GREEN | FOREGROUND_BLUE);
			continue;
		}
		if (group[i] <= 108)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << (group[i] - 72 + 3) / 4;
			if (i + 1 < amount)
			{
				if (group[i + 1] > 108)
					cout << 's';
			}
			if (i + 1 == amount)
			{
				cout << 's';
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
				FOREGROUND_GREEN | FOREGROUND_BLUE);
			continue;
		}
		if (group[i] <= 112)
		{
			cout << "東";
			continue;
		}
		if (group[i] <= 116)
		{
			cout << "南";
			continue;
		}
		if (group[i] <= 120)
		{
			cout << "西";
			continue;
		}
		if (group[i] <= 124)
		{
			cout << "北";
			continue;
		}
		if (group[i] <= 128)
		{
			cout << "白";
			continue;
		}
		if (group[i] <= 132)
		{
			cout << "發";
			continue;
		}
		if (group[i] <= 136)
		{
			cout << "中";
			continue;
		}
	}
}
void showSingleCard(int group[], int num)
{
	if (group[num] <= 36)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout << (group[num] + 3) / 4 << 'm';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
			FOREGROUND_GREEN | FOREGROUND_BLUE);
		return;
	}
	if (group[num] <= 72)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		cout << (group[num] - 36 + 3) / 4 << 'p';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
			FOREGROUND_GREEN | FOREGROUND_BLUE);
		return;
	}
	if (group[num] <= 108)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		cout << (group[num] - 72 + 3) / 4 << 's';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
			FOREGROUND_GREEN | FOREGROUND_BLUE);
		return;
	}
	if (group[num] <= 112)
	{
		cout << "東";
		return;
	}
	if (group[num] <= 116)
	{
		cout << "南";
		return;
	}
	if (group[num] <= 120)
	{
		cout << "西";
		return;
	}
	if (group[num] <= 124)
	{
		cout << "北";
		return;
	}
	if (group[num] <= 128)
	{
		cout << "白";
		return;
	}
	if (group[num] <= 132)
	{
		cout << "發";
		return;
	}
	if (group[num] <= 136)
	{
		cout << "中";
		return;
	}
}
int decision(int hand[], char input)
{
	switch (input)
	{
	case '1':
		swap(hand, 0, 13);
		break;
	case '2':
		swap(hand, 1, 13);
		break;
	case '3':
		swap(hand, 2, 13);
		break;
	case '4':
		swap(hand, 3, 13);
		break;
	case '5':
		swap(hand, 4, 13);
		break;
	case '6':
		swap(hand, 5, 13);
		break;
	case '7':
		swap(hand, 6, 13);
		break;
	case '8':
		swap(hand, 7, 13);
		break;
	case '9':
		swap(hand, 8, 13);
		break;
	case '0':
		swap(hand, 9, 13);
		break;
	case 'a':
		swap(hand, 10, 13);
		break;
	case 's':
		swap(hand, 11, 13);
		break;
	case 'd':
		swap(hand, 12, 13);
		break;
	case ' ':
		break;
	case 'k':
		return 0;
	case 'l':
		if (checkRon(hand))
		{
			return 2;
		}
		else
			return 0;
	default:
		return 0;
	}
	sort(hand, 13);
	return 1;
}
bool checkTenpai(int hand[], int except)
{
	int temp = hand[except];
	for (int i = 1; i <= 34; i++)
	{
		hand[except] = i * 4;
		if (checkRon(hand))
		{
			int count(0);
			for (int j = 0; j < 14; j++)
			{
				if (j == except)
					continue;
				if ((hand[j] + 3) / 4 == i)
				{
					count++;
				}
			}
			if (count < 4)
			{
				hand[except] = temp;
				return true;
			}
			else
			{
				if (count == 4)
					cout << "听第五张牌";
				else
					cout << "error";
			}
		}
	}
	hand[except] = temp;
	return false;
}
bool checkRon(int hand[])
{
	int count[34] = { 0 };
	for (int i = 0; i < 14; i++)
	{
		count[(hand[i] + 3) / 4 - 1]++;
	}
	pir pair[7];
	checkpair(count, pair);
	pat pattern[50];
	checkpattern(count, pattern);

	if (pair[6].param != 0)
	{
		return true;
	}
	//param a,b,c,d,e mean 4*3+1*2
	for (int a = 0; pattern[a].param != -1; a++)
	{
		for (int b = a + 1; pattern[b].param != -1; b++)
		{
			for (int c = b + 1; pattern[c].param != -1; c++)
			{
				for (int d = c + 1; pattern[d].param != -1; d++)
				{
					for (int e = 0; pair[e].param != 0; e++)
					{
						if (checkSame(count, pair, pattern, a, b, c, d, e))
						{
							return true;
						}
					}
				}
			}
		}
	}
	if (count[0] >= 1 && count[8] >= 1 && count[9] >= 1 && count[17] >= 1 && count[18] >= 1 && count[26] >= 1 && count[27] >= 1 && count[28] >= 1 && count[29] >= 1 && count[30] >= 1 && count[31] >= 1 && count[32] >= 1 && count[33] >= 1)
	{
		if (!(count[0] == 1 && count[8] == 1 && count[9] == 1 && count[17] == 1 && count[18] == 1 && count[26] == 1 && count[27] == 1 && count[28] == 1 && count[29] == 1 && count[30] == 1 && count[31] == 1 && count[32] == 1 && count[33] == 1))
		{
			return true;
		}
	}
	return false;
}
void printPat(pat pattern[])
{
	cout << endl;
	for (int i = 0; pattern[i].param != -1; i++)
	{
		if (pattern[i].type == KOU)
		{
			cout << "KOU";
			for (int j = 0; j < 3; j++)
			{
				cout << pattern[i].param;
			}
			cout << ' ' << pattern[i].color << "  ";
		}
		else if(pattern[i].type==SHUN)
		{
			cout << "SHUN";
			for (int j = 0; j < 3; j++)
			{
				cout << pattern[i].param + j;
			}
			cout << ' ' << pattern[i].color << "  ";
		}
	}
	cout << endl;
}
void printToi(pir pair[])
{
	cout << endl;
	for (int i = 0; pair[i].param != 0; i++)
	{
		cout << pair[i].param << pair[i].param << ' ' << pair[i].color << "  ";
	}
	cout << endl;
}
void defineHand(int hand[])
{
	hand[0] = 1;
	hand[1] = 36;
	hand[2] = 37;
	hand[3] = 72;
	hand[4] = 73;
	hand[5] = 108;
	hand[6] = 109;
	hand[7] = 113;
	hand[8] = 117;
	hand[9] = 19;
	hand[10] = 125;
	hand[11] = 129;
	hand[12] = 133;
	hand[13] = 1;
}