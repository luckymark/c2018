#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
void PrintChar(char *ch,UINT count,UINT x, UINT y) //在屏幕指定位置输出字符的函数 
{
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
 COORD pos;
 ULONG unuse;
 pos.X=x;
 pos.Y=y;
  CONSOLE_SCREEN_BUFFER_INFO bInfo; // 窗口缓冲区信息
 GetConsoleScreenBufferInfo(h, &bInfo );
 WriteConsoleOutputCharacterA(h,ch,count,pos,&unuse);
}
struct obstacle {
	int x1;
	int y1;
};
 struct obstacle point[50]={{4,1},{4,2},{6,2},{6,1},{10,2},{10,3},{10,4},{2,4},{6,4},{8,4},
		   					{14,2},{14,3},{14,4},{14,5},{14,6},{14,7},{12,6},{12,7},{10,6},
		  					{4,4},{10,7},{8,6},{8,7},{6,6},{6,7},{4,6},{4,7},{16,6},{16,7}};
int barrier(int x2,int y2)
{
	int c,p=0;
	for (c=0;c<50;c++)
	{
		if(x2==point[c].x1 && y2==point[c].y1)
		{
			p=1;
		}	
	}  
	return p;
}
    static int X=2,Y=1;
	char a[]="●";
	int i=sizeof(a)-1;
int main()
{
	system("color 0a");
	void PrintChar(char *ch,UINT count,UINT x,UINT y);
	void maze (void);
	void move(void);
	void menu(void);
	maze();
	menu();
	PrintChar(a,i,X,Y);
	move();
	if (X==16 && Y==8) printf("恭喜通关！！！\n"); 
	system("pause");
	return 0;	
} 
void menu(void)
{
	char list1[]="欢迎来到迷宫小游戏！！!";
	char list2[]="按ESC键退出游戏。"; 
	char list3[]="按←↑→↓键控制小球移动方向";
	PrintChar(list1,sizeof(list1),40,3);
	PrintChar(list2,sizeof(list2),40,4);
	PrintChar(list3,sizeof(list3),40,5);
}
void maze (void)
{
	printf("██████████\n");
	printf("█  ██          █\n");
	printf("█  ██  █  █  █\n");
	printf("█        █  █  █\n");
	printf("██████  █  █\n");
	printf("█            █  █\n");
	printf("█  ████████\n");
	printf("█  ████████\n");
	printf("█                █\n");
	printf("████████  █\n");
}
void move (void)
{
	void moveUP(void);
	void moveDOWN(void);
	void moveLEFT(void);
	void moveRIGHT(void);
	void maze(void);
	char turn;
	while ((turn=getch())!=0x1B) /*PRESS ESC TO QUIT*/
	{
		system("cls");
		maze();
		menu();
			switch(turn)
		{
			case 72:moveUP();break;
			case 75:moveLEFT();break;
			case 80:moveDOWN();break;
			case 77:moveRIGHT();break;
			dafault : break;
	    }
	    if (X==16 && Y==8) break; 
	}
}
void moveUP (void)
{
	Y--;
	if (Y==0)
	{
	   Y++;
	}
	else if(barrier(X,Y))
	{
		Y++;
    }
    PrintChar(a,i,X,Y);
}
void moveDOWN (void)
{
    Y++;
	if (Y==9)
	{
	   Y--;
	}
	else if(barrier(X,Y))
	{
		Y--;
    }
    PrintChar(a,i,X,Y);
}
void moveLEFT (void)
{
	X=X-2;
	if (X==0)
	{
	   X+=2;
	}
	else if(barrier(X,Y))
	{
		X+=2;
    }
    PrintChar(a,i,X,Y);
}
void moveRIGHT (void)
{
	X=X+2;
	if (X==18)
	{
	   X-=2;
	}
	else if(barrier(X,Y))
	{
		X-=2;
    }
    PrintChar(a,i,X,Y);
} 
