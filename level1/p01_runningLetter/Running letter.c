#include<stdio.h>
#include<stdlib.h>
#define LENGTH 110
int main(void)
{
	int i;
	int j=0;
	for(i=0;i<LENGTH;i++)
	{
		for(j=0;j<i;j++)
	{
		printf(" ");
	}
		printf("letter");
		system("CLS");
	}
	for(i=LENGTH;i>0;i--)
	{
		for(j=i;j>0;j--)
		{
			printf(" ");
		}
		printf("letter");
		system("CLS");
	}
	return 0;
}
