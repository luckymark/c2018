#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int map[8][8]={{0,0,0,0,0,0,0,0},
			   {2,4,4,4,4,0,0,1},
			   {0,4,0,4,0,0,0,4},
			   {0,4,0,4,4,4,0,4},
			   {0,4,4,0,0,4,0,4},
			   {0,4,0,4,0,4,0,4},
			   {4,4,4,4,0,4,4,4},
			   {0,0,0,0,0,0,0,0}};



void mapmaker()
	{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				switch(map[i][j])
				{
					case 0:
						printf("■");
						break;
					case 1:
						printf("☆");
						break;
					case 2:
						printf("♀");
						break;
					case 4:
						printf("  ");
						break;
				}
			}
			printf("\n");
		}
		
    }
void play()
{ //0代表墙，1代表正确地点，2代表人物 ,4代表空白区域 
	char ch;
	int m,n;
	for(int i=0;i<8;i++)
    {
    	for(int j=0;j<8;j++)
    	{
    		if(map[i][j]==2)
    		{
    		    m=i;
			    n=j;	
			}
		}
	}
	ch=getch();
		switch(ch)
		{
			case 'w':
			case 'W':
			if(map[m-1][n]==4)
			{
				map[m][n]=4;
				map[m-1][n]=2;
			}
			else if(map[m-1][n]==1)
			{
				map[m][n]=4;
				map[m-1][n]=2;
				printf("you win\n");
				system("pause");
			}
			break;
			case 's':
			case 'S':
			if(map[m+1][n]==4)
			{ 
				map[m][n]=4;
				map[m+1][n]=2;
			}
			else if(map[m-1][n]==1)
			{
				map[m][n]=4;
				map[m-1][n]=2;
				printf("you win\n");
				system("pause");
			}
			break; 
			case 'a':
			case 'A':
			if(map[m][n-1]==4)
			{
				map[m][n]=4;
				map[m][n-1]=2;		
			}
			else if(map[m-1][n]==1)
			{
				map[m][n]=4;
				map[m-1][n]=2;
				printf("you win\n");
				system("pause");
				return;
			}
			break;
			case 'd':
			case 'D':
			if(map[m][n+1]==4)
			{
				map[m][n]=4;
				map[m][n+1]=2;	
			}
			else if(map[m-1][n]==1)
			{
				map[m][n]=4;
				map[m-1][n]=2;
				printf("you win\n");
				system("pause");
				return;
			}
			break;
		}
	}
	
int main()
{
	while(1)
	{
	system("cls");
	mapmaker();
	play();
	}

	return 0;
}
























