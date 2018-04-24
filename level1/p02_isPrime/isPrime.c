#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int input_n;
	scanf("%lld", &input_n);
	if (input_n == 1)
	{
		printf("The number is not a Prime.\n");
		goto bottom;
	}
	for (int n = 2; n*n <= input_n; n++)
	{
		if (input_n%n == 0)
		{
			printf("The number is not a Prime.\n");
			break；
		}
			printf("The number is a Prime.\n");
	}
	getchar();
	getchar();
}