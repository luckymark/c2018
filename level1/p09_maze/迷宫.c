#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#define N 15
int x,y;
int map[N][N]={
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,3,1,1,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,1,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,1,1,1,1,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,1,1,1,1,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,4,0},
} ;

void print();
void find();
int main() 
{
	while(map[14][13]==4)
	{
		print();
		find();
		char ch;
		scanf("%c",&ch);
		if(ch=='s')
		{
			if (map[x+1][y]!=0)
			{
				map[x+1][y]=3;
				map[x][y]=1;
			}
		}
		
		if(ch=='w')
		{
			if (map[x-1][y]!=0)
			{
				map[x-1][y]=3;
				map[x][y]=1;
			}
		}
		
		if(ch=='a')
		{
			if (map[x][y-1]!=0)
			{
				map[x][y-1]=3;
				map[x][y]=1;
			}
		}
		
		if(ch=='d')
		{
			if (map[x][y+1]!=0)
			{
				map[x][y+1]=3;
				map[x][y]=1;
			}
		}
		
		system("cls");
	}
	Sleep(1000);
	system("cls");
	printf("you win!!!");
	return 0;
}


void print()
{
	int i=0,j=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(map[i][j]==0)
			printf("¡ö"); 
			else if(map[i][j]==1)
			printf("  ");
			else if(map[i][j]==3)
			printf("¡ø");
			else if(map[i][j]==4)
			printf("¡î");
		}
		printf("\n");
	}
}

void find()
{
	int i=0,j=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(map[i][j]==3)
			{
				x=i;
				y=j;
				break;
			}
		}
	}
}

