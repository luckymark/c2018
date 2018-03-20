#include<stdio.h>
#define LEVEL_HANOI 64

void move(int level, char A, char B, char C);

void main()
{
	char A = 'A';
	char B = 'B';
	char C = 'C';
	move(LEVEL_HANOI, A, B, C);
	getchar();
}

void move(int level, char A, char B, char C)
{
	if (level == 1)
	{
		printf("%c --> %c\n", A, C);
	}
	else
	{
		move(level - 1, A, C, B);
		printf("%c --> %c\n", A, C);
		move(level - 1, B, A, C);
	}
}