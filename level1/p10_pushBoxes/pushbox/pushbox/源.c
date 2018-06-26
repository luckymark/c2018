#include <stdio.h> 
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define WIDE 19
#define LONG 11
void PrintChar(char *ch, UINT count, UINT x, UINT y)  //在坐标(x,y)处输出字符串ch,ch里有count个字符
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	ULONG unuse;
	pos.X = x;
	pos.Y = y;
	CONSOLE_SCREEN_BUFFER_INFO bInfo; // 窗口缓冲区信息
	GetConsoleScreenBufferInfo(h, &bInfo);
	WriteConsoleOutputCharacterA(h, ch, count, pos, &unuse);
}
void printditu(int ditu[][WIDE]) //打印地图
{
	int i, j;
	for (i = 0; i < WIDE; i++) {
		for (j = 0; j <LONG; j++) {
			switch (ditu[j][i])
			{
			case 1:  //墙
				PrintChar("■", 2, i * 2, j);
				break;
			case 0:  //空格
				PrintChar("  ", 2, i * 2, j);
				break;
			case 3:  //宝物
				PrintChar("◎", 2, i * 2, j);
				break;
			default:break;
			}
		}
	}
}
void printxiangzi(int xiangzi[][WIDE])//打印箱子
{
	int i, j;
	for (i = 0; i < WIDE; i++) {
		for (j = 0; j <LONG; j++) {
			switch (xiangzi[j][i])
			{
			case 2:  //箱子
				PrintChar("□", 2, i * 2, j);
				break;
			default:break;
			}
		}
	}
}
int ifwin(int ditu[][WIDE], int xiangzi[][WIDE]) //判断是否胜利
{
	int i, j, k = 1;
	for (i = 0; i < WIDE; i++) {
		for (j = 0; j < LONG; j++) {
			if (ditu[j][i] == 3)
			{
				if (xiangzi[j][i] != 2)
				{
					k--;
				}
			}
		}
	}
	if (k == 1)
	{
		return 1;
	}
	else { return 0; }
}
int ifmove(int x, int y, int ditu[][WIDE], int z) //判断能否移动
{
	int k = 1;
	switch (z)
	{
	case 1: //上
		switch (ditu[y - 1][x])
		{
		case 1:
			k--;
			break;
		case 2:
			if (ditu[y - 2][x] == 1 || ditu[y - 2][x] == 2)
			{
				k--;
			}
		}
		break;
	default: break;
	case 2: //下
		switch (ditu[y + 1][x])

		{
		case 1:
			k--;
			break;
		case 2:
			if (ditu[y + 2][x] == 1 || ditu[y + 2][x] == 2)
			{
				k--;
			}
		}
		break;
	case 3: //左
		switch (ditu[y][x - 1])
		{
		case 1:
			k--;
			break;
		case 2:
			if (ditu[y][x - 2] == 1 || ditu[y][x - 2] == 2)
			{
				k--;
			}
		}
		break;
	case 4: //右
		switch (ditu[y][x + 1])
		{
		case 1:
			k--;
			break;
		case 2:
			if (ditu[y][x + 2] == 1 || ditu[y][x + 2] == 2)
			{
				k--;
			}
		}
		break;

	}
	if (k == 1)
	{
		return 1;
	}
	else { return 0; }
}
int main(void)
{

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("将所有邪恶之源封印，你将成为拯救世界的英雄，迎娶白富美，走向人生巅峰！\n");
	/*int ditu3[LONG][WIDE] = {   { 0,0,0,0,1,1,1,1,1,},
	{ 0,0,0,0,1,0,0,0,1,},
	{ 0,0,0,0,1,0,0,0,1,},
	{ 0,0,1,1,1,0,0,0,1,1,},
	{ 0,0,1,0,0,0,0,0,0,1,},
	{ 1,1,1,0,1,0,1,1,0,1,0,0,0,1,1,1,1,1,1},
	{ 1,0,0,0,1,0,1,1,0,1,1,1,1,1,0,0,3,3,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,1},
	{ 1,1,1,1,1,0,1,1,1,0,1,0,1,1,0,0,3,3,1},
	{ 0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
	{ 0,0,0,0,1,1,1,1,1,1,1}
	};
	int ditu[LONG][WIDE];*/
	/*int xiangzi[LONG][WIDE] = { { 0,0,0,0,1,1,1,1,1, },
	{ 0,0,0,0,1,0,0,0,1, },
	{ 0,0,0,0,1,2,0,0,1, },
	{ 0,0,1,1,1,0,0,2,1,1, },
	{ 0,0,1,0,0,2,0,2,0,1, },
	{ 1,1,1,0,1,0,1,1,0,1,0,0,0,1,1,1,1,1,1 },
	{ 1,0,0,0,1,0,1,1,0,1,1,1,1,1,0,0,0,0,1 },
	{ 1,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,0,1,1,1,0,1,0,1,1,0,0,0,0,1 },
	{ 0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 0,0,0,0,1,1,1,1,1,1,1 }
	};*/
	FILE *fp1;
	/*fopen_s(&fp1,"D:\\vs\\程序设计项目\\zyh3.txt","r+");
	fwrite(ditu3, sizeof(ditu3), 1, fp1);
	fread(ditu, sizeof(ditu3), 1, fp1);
	fclose(fp1);
	int i, j;*/
	fopen_s(&fp1, "D:\\vs\\程序设计项目\\zyh1.txt", "r+");
	int ditu[LONG][WIDE];
	int i, j;
	for (i = 0; i<11; i++)
		for (j = 0; j < 19; j++)
		{
			fscanf_s(fp1, "%d", &ditu[i][j], sizeof(int));
		}
	fclose(fp1);//关闭文件
	FILE *fp2;
	fopen_s(&fp2, "D:\\vs\\程序设计项目\\zyh2.txt", "r+");
	int xiangzi[LONG][WIDE];
	for (i = 0; i<11; i++)
		for (j = 0; j < 19; j++)
		{
			fscanf_s(fp2, "%d", &xiangzi[i][j], sizeof(int));
		}
	fclose(fp2);//关闭文件
	printditu(ditu);
	printxiangzi(xiangzi);
	int x = 11, y = 8, z, bushu = 0;//起始坐标
	PrintChar("○", 2, x * 2, y);
	while (ifwin(ditu, xiangzi) != 1)
	{
		bushu++;
		z = 0;
		char ch;
		ch = _getch();
		if (ch == -32)
		{

			switch (_getch())
			{
			case 72: //上
				z = 1;
				if (ifmove(x, y, xiangzi, z))
				{
					PrintChar("  ", 2, x * 2, y);
					switch (ditu[y - 1][x])
					{
					case 0:
						switch (xiangzi[y - 1][x])
						{
						case 0:
							y--;
							printditu(ditu);
							printxiangzi(xiangzi);
							PrintChar("○", 2, x * 2, y);
							break;
						case 2:
							xiangzi[y - 1][x] = 0;
							xiangzi[y - 2][x] = 2;
							printditu(ditu);
							printxiangzi(xiangzi);
							y--;
							PrintChar("○", 2, x * 2, y);
							break;
						default: break;
						}
						break;
					case 3:
						switch (xiangzi[y - 1][x])
						{
						case 0:
							y--;
							printditu(ditu);
							printxiangzi(xiangzi);
							PrintChar("○", 2, x * 2, y);
							break;
						case 2:
							xiangzi[y - 1][x] = 0;
							xiangzi[y - 2][x] = 2;
							printditu(ditu);
							printxiangzi(xiangzi);
							y--;
							PrintChar("○", 2, x * 2, y);
							break;
						default: break;
						}

					default: break;
					}
				}
				break;
			case 80: //下
				z = 2;
				if (ifmove(x, y, xiangzi, z))
				{
					PrintChar("  ", 2, x * 2, y);
					switch (ditu[y + 1][x])
					{
					case 0:
						switch (xiangzi[y + 1][x])
						{
						case 0:
							y++;
							printditu(ditu);
							printxiangzi(xiangzi);
							PrintChar("○", 2, x * 2, y);
							break;
						case 2:
							xiangzi[y + 1][x] = 0;
							xiangzi[y + 2][x] = 2;
							printditu(ditu);
							printxiangzi(xiangzi);
							y++;
							PrintChar("○", 2, x * 2, y);
							break;
						default: break;
						}
						break;
					case 3:
						switch (xiangzi[y + 1][x])
						{
						case 0:
							y++;
							printditu(ditu);
							printxiangzi(xiangzi);
							PrintChar("○", 2, x * 2, y);
							break;
						case 2:
							xiangzi[y + 1][x] = 0;
							xiangzi[y + 2][x] = 2;
							printditu(ditu);
							printxiangzi(xiangzi);
							y++;
							PrintChar("○", 2, x * 2, y);
							break;
						default: break;
						}
					default: break;
					}
				}
				break;
			case 75: //左
				z = 3;
				if (ifmove(x, y, xiangzi, z))
				{
					PrintChar("  ", 2, x * 2, y);
					switch (ditu[y][x - 1])
					{
					case 0:
						switch (xiangzi[y][x - 1])
						{
						case 0:
							x--;
							printditu(ditu);
							printxiangzi(xiangzi);
							PrintChar("○", 2, x * 2, y);
							break;
						case 2:
							xiangzi[y][x - 1] = 0;
							xiangzi[y][x - 2] = 2;
							printditu(ditu);
							printxiangzi(xiangzi);
							x--;
							PrintChar("○", 2, x * 2, y);
							break;
						default: break;
						}
						break;
					case 3:
						switch (xiangzi[y][x - 1])
						{
						case 0:
							x--;
							printditu(ditu);
							printxiangzi(xiangzi);
							PrintChar("○", 2, x * 2, y);
							break;
						case 2:
							xiangzi[y][x - 1] = 0;
							xiangzi[y][x - 2] = 2;
							printditu(ditu);
							printxiangzi(xiangzi);
							x--;
							PrintChar("○", 2, x * 2, y);
							break;
						default: break;
						}
					default: break;
					}
				}
				break;
			case 77: //右
				z = 4;
				if (ifmove(x, y, xiangzi, z))
				{
					PrintChar("  ", 2, x * 2, y);
					switch (ditu[y][x + 1])
					{
					case 0:
						switch (xiangzi[y][x + 1])
						{
						case 0:
							x++;
							printditu(ditu);
							printxiangzi(xiangzi);
							PrintChar("○", 2, x * 2, y);
							break;
						case 2:
							xiangzi[y][x + 1] = 0;
							xiangzi[y][x + 2] = 2;
							printditu(ditu);
							printxiangzi(xiangzi);
							x++;
							PrintChar("○", 2, x * 2, y);
							break;
						default: break;
						}
						break;
					case 3:
						switch (xiangzi[y][x + 1])
						{
						case 0:
							x++;
							printditu(ditu);
							printxiangzi(xiangzi);
							PrintChar("○", 2, x * 2, y);
							break;
						case 2:
							xiangzi[y][x + 1] = 0;
							xiangzi[y][x + 2] = 2;
							printditu(ditu);
							printxiangzi(xiangzi);
							x++;
							PrintChar("○", 2, x * 2, y);
							break;
						default: break;
						}
					default: break;
					}
				}
				break;
			default:break;
			}
		}
	}

	printf("\n\n你成功了！\n从此和公主过上没羞没臊的幸福生活\n");
	fprintf(stdout, "步数：%d", bushu);


	system("pause");
	return 0;
}
