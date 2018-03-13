#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <windows.h>

void main()
{
	printf("2\n3\n4\n");
	for (int i = 2; i <= 1000; i++)
	{
		for (int n = 2; n*n <= i; n++)
		{
			if (i%n == 0)
				break;
			else if ((n+1)*(n+1) > i)
				printf("%d\n", i);
		}
	}
	printf("total time is:%ld ms",clock());
	getchar();
}