#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	printf("������һ�����ڵ���2����Ȼ��");
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