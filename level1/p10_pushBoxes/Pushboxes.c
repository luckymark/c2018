#include<stdio.h>
#include<stdlib.h>
int hang,lie,judge=1;
hang=5;
lie=2;
int i,j=1;
int map[7][8];
void start(void);
void formove(void);
void paint(void);
int serch(void);
int main(void)
{
	start();
	while(judge)
	{
		paint();
		formove();
		system("CLS");
	}
	printf("\n\nSUCCESS");
	return 0;
}

void start(void)
{

	for(i=1;i<8;i++)
	{
		for(j=1;j<8;j++)
		{
			map[i][j]=1;
		}
	}
	for(i=2;i<7;i++)
	{
		for(j=2;j<7;j++)
		{
			map[i][j]=0;
		}
	}
	map[3][4]=map[6][4]=1;  /*墙*/

	map[2][2]=map[2][3]=map[2][5]=map[2][6]=2;
	map[3][2]=map[3][3]=map[3][5]=map[3][6]=2;  /*箱子归位*/

	map[2][4]=map[4][3]=map[4][4]=map[4][5]=3;     /*箱子*/
	map[5][4]=map[6][3]=map[6][4]=map[6][5]=3;

}

void paint(void)
{
	map[hang][lie]=4;     /*人物  位于map[5][2]*/
	for(i=1;i<8;i++)
	{
		for(j=1;j<8;j++)
		{
			if(map[i][j]==1)
			{
				printf("#");
			}
			else if(map[i][j]==0)
			{
				printf(" ");
			}
			else if(map[i][j]==2)
			{
				printf("X");
			}
			else if(map[i][j]==3)
			{
				printf("O");
			}
			else if(map[i][j]==4)
			{
				printf("$");
			}
			else if(map[i][j]==5)
			{
				printf("@");
			}
		}
		printf("\n");
	}

	return 0;
}
void formove(void)
{
	char key;
	key=getch();
	switch(key)
	{
	case 'w':
		if(map[hang-1][lie]==0&&(hang-1)>1)
		{
			map[hang][lie]=0;
			hang--;
		}
		else if(map[hang-1][lie]==1)
		{
		break;
		}
		else if(map[hang-1][lie]==2&&(hang-1)>1)
		{
			map[hang][lie]=0;
			map[2][2]=map[2][3]=map[2][5]=map[2][6]=2;
			map[3][2]=map[3][3]=map[3][5]=map[3][6]=2;
			hang--;
		}
		else if(map[hang-1][lie]==3&&(hang-2)>1)
		{
			if(map[hang-2][lie]==0)
			{
				map[hang][lie]=map[hang-1][lie]=0;
				hang--;
				map[hang-1][lie]=3;
			}
			else if(map[hang-2][lie]==1)
			{
				break;
			}
			else if(map[hang-2][lie]==2)
			{
				map[hang][lie]=map[hang-1][lie]=0;
				map[2][2]=map[2][3]=map[2][5]=map[2][6]=2;
				map[3][2]=map[3][3]=map[3][5]=map[3][6]=2;
				hang--;
				map[hang-1][lie]=3;
			}
			}
			break;
	case 's':
		if(map[hang+1][lie]==0&&(hang+1)<7)
		{
			map[hang][lie]=0;
			map[2][2]=map[2][3]=map[2][5]=map[2][6]=2;
			map[3][2]=map[3][3]=map[3][5]=map[3][6]=2;
			hang++;
		}
		else if(map[hang+1][lie]==1)
		{
		break;
		}
		else if(map[hang+1][lie]==2&&(hang+1)<7)
		{
			map[hang][lie]=0;
			map[2][2]=map[2][3]=map[2][5]=map[2][6]=2;
			map[3][2]=map[3][3]=map[3][5]=map[3][6]=2;
			hang++;
		}
		else if(map[hang+1][lie]==3&&(hang+2)<7)
		{
			if(map[hang+2][lie]==0)
			{
				map[hang][lie]=map[hang+1][lie]=0;
				hang++;
				map[hang+1][lie]=3;
			}
			else if(map[hang+2][lie]==1)
			{
				break;
			}
			else if(map[hang+2][lie]==2)
			{
				map[hang][lie]=map[hang+1][lie]=0;
				map[2][2]=map[2][3]=map[2][5]=map[2][6]=2;
				map[3][2]=map[3][3]=map[3][5]=map[3][6]=2;
				hang++;
				map[hang+1][lie]=3;
			}
			}
			break;

	case 'a':
		if(map[hang][lie-1]==0&&(lie-1)>1)
		{
			map[hang][lie]=0;
			lie--;
		}
		else if(map[hang][lie-1]==1)
		{
		break;
		}
		else if(map[hang][lie-1]==2&&(lie-1)>1)
		{
			map[hang][lie]=0;
			map[2][2]=map[2][3]=map[2][5]=map[2][6]=2;
			map[3][2]=map[3][3]=map[3][5]=map[3][6]=2;
			lie--;
		}
		else if(map[hang][lie-1]==3&&(lie-2)>1)
		{
			if(map[hang][lie-2]==0)
			{
				map[hang][lie]=map[hang][lie-1]=0;
				lie--;
				map[hang][lie-1]=3;
			}
			else if(map[hang][lie-2]==1)
			{
				break;
			}
			else if(map[hang][lie-2]==2)
			{
				map[hang][lie]=map[hang][lie-1]=0;
				map[2][2]=map[2][3]=map[2][5]=map[2][6]=2;
				map[3][2]=map[3][3]=map[3][5]=map[3][6]=2;
				lie--;
				map[hang][lie-1]=3;
			}
			}
			break;

	case 'd':
		if(map[hang][lie+1]==0&&(lie+1)<7)
		{
			map[hang][lie]=0;
			lie++;
		}
		else if(map[hang][lie+1]==1)
		{
		break;
		}
		else if(map[hang][lie+1]==2&&(lie+1)<7)
		{
			map[hang][lie]=0;
			map[2][2]=map[2][3]=map[2][5]=map[2][6]=2;
			map[3][2]=map[3][3]=map[3][5]=map[3][6]=2;
			lie++;
		}
		else if(map[hang][lie+1]==3&&(lie+2)<7)
		{
			if(map[hang][lie+2]==0)
			{
				map[hang][lie]=map[hang][lie+1]=0;
				lie++;
				map[hang][lie+1]=3;
			}
			else if(map[hang][lie+2]==1)
			{
				break;
			}
			else if(map[hang][lie+2]==2)
			{
				map[hang][lie]=map[hang][lie+1]=0;
				map[2][2]=map[2][3]=map[2][5]=map[2][6]=2;
				map[3][2]=map[3][3]=map[3][5]=map[3][6]=2;
				lie++;
				map[hang][lie+1]=3;
			}
			}
			break;

	}
	return;
}

int serch(void)
{
	int a,b;
	for(a=1;a<8;a++)
	{
		for(b=1;b<8;b++)
		{
			if(map[a][b]==2)
			{
				judge=1;
				return judge;
			}
		}
	}
	judge=0;
	return judge;
}
