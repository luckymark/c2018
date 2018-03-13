#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int power(int num, int times);

void main()
{
	int p1, p2, p3;
	for (int n=100; n < 1000; n++)
	{
		p1 = n % 10;
		p2 = (n % 100) / 10;
		p3 = (n - p1 - p2) / 100;
		if (n == p1 * p1*p1 + p2 * p2*p2 + p3 * p3*p3)
		{
			printf("%d\n", n);
		}
	}
	getchar();
}