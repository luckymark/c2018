#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>

void createmaze(int maze[][20]);
void draw(int maze[][20]);

void main()
{
	system("mode con cols=50 lines=22");
replay:
	int dir = 0;
	int maze[20][20];
	int posi[2] = {1,1};
	createmaze(maze);
	maze[1][1] = 2;                         //2表示玩家
	draw(maze);
	while(maze[18][18] != 2)
	{
		dir = _getch();
		switch (dir)
		{
		case 72:                               //up
			if (maze[posi[0] - 1][posi[1]] == 0 || maze[posi[0] - 1][posi[1]] == 3)
			{
				maze[posi[0]][posi[1]] = 0;
				posi[0] = posi[0] - 1;
				maze[posi[0]][posi[1]] = 2;
				draw(maze);
			}
			break;
		case 80:                               //down
			if (maze[posi[0] + 1][posi[1]] == 0 || maze[posi[0] + 1][posi[1]] == 3)
			{
				maze[posi[0]][posi[1]] = 0;
				posi[0] = posi[0] + 1;
				maze[posi[0]][posi[1]] = 2;
				draw(maze);
			}
			break;
		case 75:                               //left
			if (maze[posi[0]][posi[1] - 1] == 0 || maze[posi[0]][posi[1] - 1] == 3)
			{
				maze[posi[0]][posi[1]] = 0;
				posi[1] = posi[1] - 1;
				maze[posi[0]][posi[1]] = 2;
				draw(maze);
			}
			break;
		case 77:                               //right
			if (maze[posi[0]][posi[1] + 1] == 0 || maze[posi[0]][posi[1] + 1] == 0)
			{
				maze[posi[0]][posi[1]] = 0;
				posi[1] = posi[1] + 1;
				maze[posi[0]][posi[1]] = 2;
				draw(maze);
			}
			break;
		case 'r':                               //recreate a maze
		{
			goto replay;
			break;
		}
		default:;
		}
	}
	
}

void createmaze(int maze[][20])
{
	for (int n1 = 1; n1 < 19; n1++)
	{
		for (int n2 = 1; n2 < 19; n2++)
		{
			if (rand() % 4 + 1 > 1)
			{
				maze[n1][n2] = 0;           //0表示空
			}
			else
			{
				maze[n1][n2] = 1;           //1表示墙
			}
		}
	}
	for (int n = 0; n < 20; n++)
	{
		maze[0][n] = 1;
		maze[19][n] = 1;
		maze[n][0] = 1;
		maze[n][19] = 1;                    //生成边界墙
	}
	maze[18][18] = 3;                       //终点   
}

void draw(int maze[][20])
{
	system("cls");
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			switch (maze[i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("墙");
				break;
			case 2:
				printf("你");
				break;
			case 3:
				printf("终");
				break;
			}
		}
		printf("\n");
	}
}