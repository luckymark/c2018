#include<stdio.h>
#include<stdlib.h>
int manhang=9;int manlie=8;
int map[11][11];
void get(void);                             /*老师为啥我的程序需要按四下才能移动一步啊*/
void print(int a[11][11]);                                           /*求 帮 助*/
int main(void)
{
	int hang=1,lie=1;
	for(hang=1;hang<=10;hang++)
	{
		for(lie=1;lie<=10;lie++)
		{
			map[hang][lie]=1;
		}
	}
	map[4][1]=map[4][2]=map[5][2]=map[6][2]=map[6][3]=map[6][4]=0;
	map[5][4]=map[4][4]=map[3][4]=map[2][4]=map[2][5]=map[2][6]=0;
	map[2][7]=map[2][8]=map[2][9]=map[3][9]=map[4][9]=map[5][9]=0;
	map[6][9]=map[7][9]=map[7][8]=map[8][8]=map[9][8]=0;
	map[3][6]=map[4][6]=map[5][6]=map[6][6]=map[7][6]=0;
	map[9][8]=2;
	print(map[11][11]);
	int judge=1;

	while(judge)
	{
		fflush(stdout);
		get();
		system("CLS");
		map[manhang][manlie]=2;
		map[9][8]=0;
		print(map[11][11]);
		if(manhang==10||manhang==1||manlie==1||manlie==10)
			{
			judge=0;
			}
	}
	printf("Success\n");
	getchar();
	return 0;
}

void get(void)
{
	if(getch()=='w'&&map[manhang-1][manlie]==0)
	{
		map[manhang][manlie]=0;
		manhang-=1;
	}
	if(getch()=='s'&&map[manhang+1][manlie]==0)
	{
		map[manhang][manlie]=0;
		manhang+=1;
	}
	if(getch()=='a'&&map[manhang][manlie-1]==0)
	{
		map[manhang][manlie]=0;
		manlie-=1;
	}
	if(getch()=='d'&&map[manhang][manlie+1]==0)
	{
		map[manhang][manlie]=0;
		manlie+=1;
	}
	return;
}

void print(int a[11][11])
{
	int i,j=1;
	for(i=1;i<11;i++)
	{
		for(j=1;j<11;j++)
		{
			if(map[i][j]==1)
			{
				printf("#");
			}
			else if(map[i][j]==0)
			{
				printf(" ");
			}
			else printf("$");
		}
		printf("\n");
	}
	printf("\n Get from keyborad \nYou should aim the board for four times\n ");
	return;
}
