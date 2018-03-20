#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>

void create_maze(int maze[][20]);
void draw(int maze[][20]);
enum symbol{ empty, wall, player, terminal };

void main()
{
	system("mode con cols=50 lines=22");
	int dir;
	int maze[20][20];
	int posi[2] = {1,1};
replay:
	dir = 0;
	create_maze(maze);
	maze[1][1] = player;
	draw(maze);
	while(maze[18][18] != player)
	{
		dir = _getch();
		switch (dir)
		{
		case 72:                               //up
			if (maze[posi[0] - 1][posi[1]] == empty || maze[posi[0] - 1][posi[1]] == terminal)
			{
				maze[posi[0]][posi[1]] = empty;
				posi[0] = posi[0] - 1;
				maze[posi[0]][posi[1]] = player;
				draw(maze);
			}
			break;
		case 80:                               //down
			if (maze[posi[0] + 1][posi[1]] == empty || maze[posi[0] + 1][posi[1]] == terminal)
			{
				maze[posi[0]][posi[1]] = empty;
				posi[0] = posi[0] + 1;
				maze[posi[0]][posi[1]] = player;
				draw(maze);
			}
			break;
		case 75:                               //left
			if (maze[posi[0]][posi[1] - 1] == empty || maze[posi[0]][posi[1] - 1] == terminal)
			{
				maze[posi[0]][posi[1]] = empty;
				posi[1] = posi[1] - 1;
				maze[posi[0]][posi[1]] = player;
				draw(maze);
			}
			break;
		case 77:                               //right
			if (maze[posi[0]][posi[1] + 1] == empty || maze[posi[0]][posi[1] + 1] == terminal)
			{
				maze[posi[0]][posi[1]] = empty;
				posi[1] = posi[1] + 1;
				maze[posi[0]][posi[1]] = player;
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

void create_maze(int maze[][20])
{
	for (int n1 = 1; n1 < 19; n1++)
	{
		for (int n2 = 1; n2 < 19; n2++)
		{
			if (rand() % 4 + 1 > 1)
			{
				maze[n1][n2] = empty;
			}
			else
			{
				maze[n1][n2] = wall;
			}
		}
	}
	for (int n = 0; n < 20; n++)
	{
		maze[0][n] = wall;
		maze[19][n] = wall;
		maze[n][0] = wall;
		maze[n][19] = wall;
	}
	maze[18][18] = terminal;
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
			case empty:
				printf("  ");
				break;
			case wall:
				printf("墙");
				break;
			case player:
				printf("你");
				break;
			case terminal:
				printf("终");
				break;
			}
		}
		printf("\n");
	}
}