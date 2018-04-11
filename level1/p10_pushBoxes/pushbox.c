#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<windows.h>
#define N 10
int gmap[N][N]=
{
{1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,4,0,4,0,0,0,1},
{1,0,0,0,0,0,1,0,0,1},
{1,0,4,1,1,1,1,0,0,1},
{1,0,0,1,8,3,3,4,0,1},
{1,0,0,1,3,3,0,0,0,1},
{1,0,4,1,3,0,0,4,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1}
};
int x,y;
void showmap();
void search();
void move();
void up();
void down();
void left();
void right();

int main()
{
	int num=0;
	while(gmap[5][4]!=7||gmap[5][5]!=7||gmap[5][6]!=7||gmap[6][4]!=7||gmap[6][5]!=7||gmap[7][4]!=7) 
	{
		num+=1;
		system("cls");
		showmap();
		search();
		move();
	}
	Sleep(1000);
	system("cls");
	printf("you win!!!\n");
	printf("your step:%d\n",num);
	return 0;
}



void showmap()
{
	int i=0,j=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			switch (gmap[i][j])
			{
			case 0:
                printf("  ");
                break;
            case 1:
                printf("■");
                break;
            case 3:
                printf("☆");
                break;
            case 4:
                printf("□");
                break;
            case 5:
                printf("♀");  //人
                break;
            case 7:     //4 + 3 箱子在目的地中
                printf("★");
                break;
            case 8:     // 5 + 3 人在目的地当中 
                printf("♀");
                break;
			}
		}
		printf("\n");
	}
}

void search()
{
	int i=0,j=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(gmap[i][j]==5||gmap[i][j]==8)
			{
				x=i;
				y=j;
				break;
			}
		}
	}
}


void move()
{
	char ch;
	ch=getch();
	if(ch=='w')
	{
	up();
	}
	if(ch=='s')
	{
	down();
	}
	if(ch=='a')
	{
	left();
	}
	if(ch=='d')
	{
	right();
	}
}
void up()
{
	if(gmap[x-1][y]==0||gmap[x-1][y]==3)
	{
		gmap[x-1][y]+=5;
		gmap[x][y]-=5;
	}
	else if(gmap[x-1][y]==4||gmap[x-1][y]==7)
	{
		if(gmap[x-2][y]==0||gmap[x-2][y]==3)
		{
			gmap[x-2][y]+=4;
			gmap[x-1][y]+=1;
			gmap[x][y]-=5;
		}
	}
}
void down()
{
	if(gmap[x+1][y]==0||gmap[x+1][y]==3)
	{
		gmap[x+1][y]+=5;
		gmap[x][y]-=5;
	}
	else if(gmap[x+1][y]==4||gmap[x+1][y]==7)
	{
		if(gmap[x+2][y]==0||gmap[x+2][y]==3)
		{
			gmap[x+2][y]+=4;
			gmap[x+1][y]+=1;
			gmap[x][y]-=5;
		}
	}
}
void left()
{
	if(gmap[x][y-1]==0||gmap[x][y-1]==3)
	{
		gmap[x][y-1]+=5;
		gmap[x][y]-=5;
	}
	else if(gmap[x][y-1]==4||gmap[x][y-1]==7)
	{
		if(gmap[x][y-2]==0||gmap[x][y-2]==3)
		{
			gmap[x][y-2]+=4;
			gmap[x][y-1]+=1;
			gmap[x][y]-=5;
		}
	}
}
void right()
{
	if(gmap[x][y+1]==0||gmap[x][y+1]==3)
	{
		gmap[x][y+1]+=5;
		gmap[x][y]-=5;
	}
	else if(gmap[x][y+1]==4||gmap[x][y+1]==7)
	{
		if(gmap[x][y+2]==0||gmap[x][y+2]==3)
		{
			gmap[x][y+2]+=4;
			gmap[x][y+1]+=1;
			gmap[x][y]-=5;
		}
	}
}
