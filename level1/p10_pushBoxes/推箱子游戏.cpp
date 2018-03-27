#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
int map[8][8];
int step=0;

FILE *fpRead=fopen("map.txt","r");

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
					case 3:
						printf("□");
						break;
					case 4:
						printf("  ");
						break;
					default:
						printf("error");
				}
			}
			printf("\n");
		}
		printf("your step is ");
		
    }
void play()
{ //0代表墙，1代表正确地点，2代表人物，3代表箱子 ,4代表空白区域 
    int m,n;
    int k,l;
    int over=0;
    for(int i=0;i<8;i++)
    {
    	for(int j=0;j<8;j++)
    	{
    		if(map[i][j]==2)
    		{
    		    m=i;
			    n=j;	
			}
			if(map[i][j]==3) 
			{
				k=i;
				l=j;
			}
			if(map[i][j]==1)
			{
				over++;
			}
		}
	}
	if(over==0)
	{
		printf("%d\n",step);
		printf("you win\n");
		system("pause");
		return;
	}
	

	char ch;
	ch=getch();
		printf("%d\n",step);
		switch(ch)
		{
			case 'w':
			case 'W':
			step++;
			if(map[m-1][n]==4)
			{
				map[m][n]=4;
				map[m-1][n]=2;
			}
			if(map[m-1][n]==3)
			{
				if(map[k-1][l]!=1)
				{
				map[k][l]=4;
			    map[k-1][l]=3;
				map[m][n]=4;
				map[m-1][n]=2;	
				}
				else if(map[k-1][l]==1&&map[k][l]!=1)
				{
				map[k][l]=4;
			    map[k-1][l]=3;
				map[m][n]=4;
				map[m-1][n]=2;	
				}
				else if(map[k-1][l]==1&&map[k][l]==1)
				{
				map[k][l]=1;
				map[k-1][l]=3;
				map[m][n]=4;
				map[m-1][n]=2;	
				}	
			}
			if(map[m-1][n]==0)
			{
				map[m-1][n]=0;
				map[m][n]=2;
			}
			break;
			case 's':
			case 'S':
			step++;
			if(map[m+1][n]==4)
			{ 
				map[m][n]=4;
				map[m+1][n]=2;
			}
			if(map[m+1][n]==3)
			{
				if(map[k+1][l]!=1)
				{
				map[k][l]=4;
				map[k+1][l]=3;
				map[m][n]=4;
				map[m+1][n]=2;	
				}
				else if(map[k+1][l]==1&&map[k][l]!=1)
				{
				map[k][l]=4;
				map[k+1][l]=3;
				map[m][n]=4;
				map[m+1][n]=2;		
				}
				else if(map[k+1][l]==1&&map[k][l]==1)
				{
				map[k][l]=1;
				map[k+1][l]=3;
				map[m][n]=4;
				map[m+1][n]=2;	
				}
				
			}
			break; 
			case 'a':
			case 'A':
			step++;
			if(map[m][n-1]==4)
			{
		
				map[m][n]=4;
				map[m][n-1]=2;		
			}
			if(map[m][n-1]==3)
			{
				if(map[k][l-1]!=1)
				{
				map[k][l]=4;
				map[k][l-1]=3;
				map[m][n]=4;
				map[m][n-1]=2;	
				}
				else if(map[k][l-1]==1&&map[k][l]!=1)
				{
				map[k][l]=4;
				map[k][l-1]=3;
				map[m][n]=4;
				map[m][n-1]=2;	
				}
				else if(map[k][l-1]==1&&map[k][l]==1)
				{
				map[k][l]=1;
				map[k][l-1]=3;
				map[m][n]=4;
				map[m][n-1]=2;	
				}
				
			}
			break;
			case 'd':
			case 'D':
			step++;
			if(map[m][n+1]==4)
			{
				map[m][n]=4;
				map[m][n+1]=2;	
			}
			if(map[m][n+1]==3)
			{
				if(map[k][l+1]!=1)
				{
				map[k][l]=4;
				map[k][l+1]=3;
				map[m][n]=4;
				map[m][n+1]=2;	
				}
				if(map[k][l+1]==1&&map[k][l]!=1)
				{
				map[k][l]=4;
				map[k][l+1]=3;
				map[m][n]=4;
				map[m][n+1]=2;	
				}
				if(map[k][l+1]==1&&map[k][l]==1)
				{
				map[k][l]=1;
				map[k][l+1]=3;
				map[m][n]=4;
				map[m][n+1]=2;	
				}
			}
			break;
		}
	
	}
	
				   
int main()
{  	
	while(1)
	{
	
	if(fpRead==NULL)
	{
	return 0;
	}
	for(int i=0;i<8;i++)
	{
	for(int j=0;j<8;j++)
	{
		fscanf(fpRead,"%d",&map[i][j]);
	}
    }
    system("cls");
	mapmaker();
	play();
	
	

}
	return 0;
}		 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 

