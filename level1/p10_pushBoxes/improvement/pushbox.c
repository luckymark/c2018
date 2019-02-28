#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<windows.h>
#define N 20
int gmap[N][N]={0};
int x,y;
int all=0;
int now=0;
int num=0;
void choose(); 
void showmap();
void howmany();
void search();
void move();
void up();
void down();
void left();
void right();
void judge();

int main()
{
	int step=0;
	printf("choose map, 1or2:\n");
	choose();
	howmany();
	while(1) 
	{
		system("cls");
		showmap();
		search();
		move();
		step++;
		judge();
		if(all==now)
		break;
		else 
		now=0;
	}
	char name[N];
	Sleep(300);
	system("cls");
	printf("you win!!!\n");
	printf("your step:%d\n",step);
	printf("please enter your name:\n");
	fflush(stdin);
	gets(name);
 	FILE *record=fopen("record.txt","a");
 	fprintf(record,"map:%d player:%s step:%d\n",num,name,step);
 	fclose(record);
	
	return 0;
}

void choose()
{ 
	scanf("%d",&num);
	if(num==1)
	{
		int i=0,j=0;
		FILE *fp;
		fp=fopen("1.txt","r");
		for(i=0;i<9;i++)
 		{
 			for(j=0;j<11;j++)
 			{
 				fscanf(fp,"%d",&gmap[i][j]);
 			}
 		}
 		fclose(fp);
 	}
 	if(num==2)
	{
		int i=0,j=0;
		FILE *fp;
		fp=fopen("2.txt","r");
		for(i=0;i<10;i++)
 		{
 			for(j=0;j<10;j++)
 			{
 				fscanf(fp,"%d",&gmap[i][j]);
 			}
 		}
 		fclose(fp);
 	}
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
void howmany()
{
	int i=0,j=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(gmap[i][j]==3||gmap[i][j]==8)
			{
				all++;
			}
		}
	}
}

void judge()
{
	int i=0,j=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(gmap[i][j]==7)
			{
				now++;
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
