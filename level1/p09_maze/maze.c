#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>

int x,y,i,j,t;

int map_TWO[10][10];

const int map_ONE[10][10] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{2, 0, 0, 0, 0, 0, 0, 0, 1, 1},
{1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
{1, 1, 1, 1, 0, 1, 0, 0, 1, 1},
{1, 1, 1, 0, 0, 1, 1, 1, 1, 1},
{1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
{1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
{1, 0, 0, 0, 1, 0, 0, 0, 0, 3},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int main()
{
	printf("Game start\n");
	printf("w is up, a is left, s is down, d is right, q is end\n");
	x = 1;
	y = 0;
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			map_TWO[i][j] = map_ONE[i][j];
		}
	}
	map_TWO[1][0] = 9;
	
	plot();
	
	while(map_TWO[8][9] != 9)
	{
		for(i = 0; i < 10; i++)
		{
			for(j = 0; j < 10; j++)
			{
				map_TWO[i][j] = map_ONE[i][j];
			}
		}
		move();
		if(map_TWO[8][9] == 9)
		{
			printf("You win!\n");
			break;
		}
	}
	
	return 0;
}

void plot()//根据当前位置绘制迷宫图 
{
	system("cls");
	printf("Game start\n");
	printf("w is up, a is left, s is down, d is right, q is end\n");
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			if(map_TWO[i][j] == 1)
			{
				printf("#");
			}
			else if(map_TWO[i][j] == 0)
			{
				printf(" ");
			}
			else if(map_TWO[i][j] == 2)
			{
				printf("+");
			}
			else if(map_TWO[i][j] == 3)
			{
				printf("-");
			}
			else if(map_TWO[i][j] == 9)
			{
				printf("*");
			}
		}
		printf("\n");
	}
}

void move()//当前位置移动操作 
{
	t = getch();
	switch (t)
	{
		case 'w':
			{
				if(map_ONE[x-1][y] == 0 || map_ONE[x-1][y] == 2 || map_ONE[x-1][y] == 3)
				{
					x--;
					map_TWO[x][y] = 9;
					plot();
				}
				break;
			}
		case 'a':
			{
				if(map_ONE[x][y-1] == 0 || map_ONE[x][y-1] == 2 || map_ONE[x][y-1] == 3)
				{
					y--;
					map_TWO[x][y] = 9;
					plot();
				}
				break;
			}
		case 's':
			{
				if(map_ONE[x+1][y] == 0 || map_ONE[x+1][y] == 2 || map_ONE[x+1][y] == 3)
				{
					x++;
					map_TWO[x][y] = 9;
					plot();
				}
				break;
			}
		case 'd':
			{
				if(map_ONE[x][y+1] == 0 || map_ONE[x][y+1] == 2 || map_ONE[x][y+1] == 3)
				{
					y++;
					map_TWO[x][y] = 9;
					plot();
				}
				break;
			}
		case 'q':  
                {  
                    printf("Do you want to end the game?(y is yes)\n");  
                    t = getch();  
                    if(t == 'y')
                    {
                    	exit(0);
					}
					break;
                }  
        default:  
            {  
                plot();  
                puts("You touch a wrong key.\n");  
                break;  
            }  
	}
}
