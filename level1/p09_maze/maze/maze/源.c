#include <stdio.h> 
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
void ditu()
{
	printf("■■■■■■■■■■■\n");
	printf("            ■      ■\n");
	printf("■■■  ■      ■■■\n");
	printf("    ■  ■■■■    ■\n");
	printf("  ■■    ■■■  ■■\n");
	printf("        ■■        ■\n");
	printf("■■■  ■    ■■  ■\n");
	printf("        ■  ■■    ■\n");
	printf("  ■■■■  ■■  ■■\n");
	printf("            ■■     $\n");
	printf("■■■■■■■■■■■\n");
}
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
int judge(int x, int y)//判断是否为墙
{
	if (x % 2 == 1)
	{
		x = (x - 1) / 2;
	}
	else { x = x / 2; }
	int a[11][11] = { { 1,1,1,1,1,1,1,1,1,1,1 },
	{ 0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,1,1,0,1,0,0,0,1,1,1 },
	{ 0,0,1,0,1,1,1,1,0,0,1 },
	{ 0,1,1,0,0,1,1,1,0,1,1 },
	{ 0,0,0,0,1,1,0,0,0,0,1 },
	{ 1,1,1,0,1,0,0,1,1,0,1 },
	{ 0,0,0,0,1,0,1,1,0,0,1 },
	{ 0,1,1,1,1,0,1,1,0,1,1 },
	{ 0,0,0,0,0,0,1,1,0,0,0 },
	{ 1,1,1,1,1,1,1,1,1,1,1 } };
	if (a[y][x] == 1)
	{
		return 1;
	}
	else {
		return 0;
	}


}




int main()
{
	ditu();
	int x = 0, y = 1;
	PrintChar("○", 2, x, y);
	for (; x != 20 || y != 9; ) {


		char ch;
		ch = _getch();
		if (ch == -32)
		{
			PrintChar("  ", 2, x, y);
			switch (getch())
			{
			case 72: //上				
				y--;
				if (judge(x, y) == 1)
				{
					y++;
				}
				PrintChar("○", 2, x, y);
				break;
			case 80: //下				
				y++;
				if (judge(x, y) == 1)
				{
					y--;
				}
				PrintChar("○", 2, x, y);
				break;
			case 75: //左				
				x = x - 2;
				if (judge(x, y) == 1)
				{
					x = x + 2;
				}
				PrintChar("○", 2, x, y);
				break;
			case 77: //右
				x = x + 2;
				if (judge(x, y) == 1)
				{
					x = x - 2;
				}
				PrintChar("○", 2, x, y);
				break;
			default:break;
			}
		}
	}
	printf("you win!");
	system("pause");
	return 0;
}