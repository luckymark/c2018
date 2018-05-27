#include <stdio.h>

void move(char x,char y)
{
	printf("%c-->%c\n",x,y);
}

void hanoi(int n,char one,char two,char three)
{
	if (n == 1)
	{
		move(one,three);
	}
	else 
	{
		hanoi(n-1,one,three,two);
		move(one,three);
		hanoi(n-1,two,one,three);
	}
}

int main()
{
	int n;
	printf("Please enter the number of disks:\n");
	scanf("%d",&n);
	printf("The steps are as follows:\n");
	hanoi(n,'A','B','C');
	
}
