#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	printf("请输入一个大于等于2的自然数");
	int  j = 1, i, x;
	scanf_s("%d", &x);

	for (i = 2; i < x; i++)
	{
		if (x%i == 0)
		{
			j--;
			break;
		}

	}
	if (j == 1)
	{
		printf("isprime");
	}
	else
	{
		printf("not is prime");
	}

	system("pause");
	return 0;
}