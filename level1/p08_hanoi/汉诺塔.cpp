#include <stdio.h>

int i;

void move(int n, char start, char end)
{
	printf("%d: put NO.%d from %c to %c\n", i++, n, start, end);
}

void hanoi(int n, char A_post, char B_post, char C_post)
{
	if(n == 1)
	{
		move(n, A_post, C_post);
	}
	else
	{
		hanoi(n-1, A_post, C_post, B_post);
		move(n, A_post, C_post);
		hanoi(n-1, B_post, A_post, C_post);
	}
}

int main()
{
	i = 1;
	char post[3] = {'A', 'B', 'C'};
	hanoi(8, post[0], post[1], post[2]);
	
	return 0;
}
