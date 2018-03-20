#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#define map_size 15

int set_level(int set_level, int map[][15], FILE *level);
void draw(int map[][15],int steps);
void refill_terminal(int map[][15]);
enum symbol { empty, wall, player, terminal ,box};

void main()
{
	system("mode con cols=60 lines=22");
	FILE *level;
	int select_level;
	int step_count = 0;
	int dir = 0;
	int map[15][15];
	int posi[2] = {1,1};
re_select:
	printf("please input a number between 1-3 to select levels.\n");
	scanf("%d", &select_level);
	if (set_level(select_level, map, &level))
	{
		goto re_select;
	}
	draw(map,step_count);
	while (map[13][1] != box || map[13][2] != box || map[13][3] != box)
	{
		dir = _getch();
		switch (dir)
		{
		case 72:                                //up
			step_count++;
			if (map[posi[0] - 1][posi[1]] == empty || map[posi[0] - 1][posi[1]] == terminal)
			{
				map[posi[0]][posi[1]] = empty;
				posi[0] = posi[0] - 1;
				map[posi[0]][posi[1]] = player;
			}
			else if (map[posi[0] - 1][posi[1]] == box && (map[posi[0] - 2][posi[1]] == empty || map[posi[0] - 2][posi[1]] == terminal))
			{
				map[posi[0]][posi[1]] = empty;
				map[posi[0] - 1][posi[1]] = player;
				posi[0] = posi[0] - 1;
				map[posi[0] - 1][posi[1]] = box;
			}
			refill_terminal(map);
			draw(map, step_count);
			break;
		case 80:                               //down
			step_count++;
			if (map[posi[0] + 1][posi[1]] == empty || map[posi[0] + 1][posi[1]] == terminal)
			{
				map[posi[0]][posi[1]] = empty;
				posi[0] = posi[0] + 1;
				map[posi[0]][posi[1]] = player;
			}
			else if (map[posi[0] + 1][posi[1]] == box && (map[posi[0] + 2][posi[1]] == empty || map[posi[0] + 2][posi[1]] == terminal))
			{
				map[posi[0]][posi[1]] = empty;
				map[posi[0] + 1][posi[1]] = player;
				posi[0] = posi[0] + 1;
				map[posi[0] + 1][posi[1]] = box;
			}
			refill_terminal(map);
			draw(map, step_count);
			break;
		case 75:                               //left
			step_count++;
			if (map[posi[0]][posi[1] - 1] == empty || map[posi[0]][posi[1] - 1] == terminal)
			{
				map[posi[0]][posi[1]] = empty;
				posi[1] = posi[1] - 1;
				map[posi[0]][posi[1]] = player;
			}
			else if (map[posi[0]][posi[1] - 1] == box && (map[posi[0]][posi[1] - 2] == empty || map[posi[0]][posi[1] - 2] == terminal))
			{
				map[posi[0]][posi[1]] = empty;
				map[posi[0]][posi[1] - 1] = player;
				posi[1] = posi[1] - 1;
				map[posi[0]][posi[1] - 1] = box;
			}
			refill_terminal(map);
			draw(map, step_count);
			break;
		case 77:                               //right
			step_count++;
			if (map[posi[0]][posi[1] + 1] == empty || map[posi[0]][posi[1] + 1] == terminal)
			{
				map[posi[0]][posi[1]] = empty;
				posi[1] = posi[1] + 1;
				map[posi[0]][posi[1]] = player;
			}
			else if (map[posi[0]][posi[1] + 1] == box && (map[posi[0]][posi[1] + 2] == empty || map[posi[0]][posi[1] + 2] == terminal))
			{
				map[posi[0]][posi[1]] = empty;
				map[posi[0]][posi[1] + 1] = player;
				posi[1] = posi[1] + 1;
				map[posi[0]][posi[1] + 1] = box;
			}
			refill_terminal(map);
			draw(map, step_count);
			break;
		}
	}
	system("cls");
	printf("666 你赢了 666\n");
	system("pause");
}

int set_level(int set_level, int map[][15],FILE *level)
{
	char ch = '0';
	int num_n;
	int n1 = 0;
	int n2 = 0;
	switch (set_level)
	{
	case 1:
		level = fopen("level1.txt", "r");
		break;
	case 2:
		level = fopen("level2.txt", "r");
		break;
	case 3:
		level = fopen("level3.txt", "r");
		break;
	}
	if (level == NULL)
	{
		printf("can not find the map file.\nplease try another level.\n");
		return 1;
	}
	while (ch != EOF)
	{
		ch = fgetc(level);
		switch (ch)
		{
		case '0':
			num_n = 0;
			break;
		case '1':
			num_n = 1;
			break;
		case '2':
			num_n = 2;
			break;
		case'3':
			num_n = 3;
			break;
		case '4':
			num_n = 4;
			break;
		default:
			break;
		}
		if (ch != '\n')
		{
			map[n1][n2] = num_n;
			n2++;
		}
		else
		{
			n1++;
			n2 = 0;
		}
	}
	fclose(level);
	return 0;
}

void draw(int map[][15],int steps)
{
	system("cls");
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			switch (map[i][j])
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
			case box:
				printf("箱");
				break;
			}
		}
		printf("\n");
	}
	printf("您已移动%d步。\n", steps);
}

void refill_terminal(int map[][15])
{
	for (int i = 1; i <= 3; i++)
	{
		if (map[13][i] != box && map[13][i] != player)
		{
			map[13][i] = terminal;
		}
	}

}