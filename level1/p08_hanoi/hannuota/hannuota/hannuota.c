#include<stdio.h>
#include<stdlib.h>
int main()
{
	int cengshu, i;
	unsigned long long  k = 1;
	scanf_s("%d", &cengshu);
	for (i = 1; i<cengshu; i++)
	{
		k = 2 * k + 1;
	}
	printf("%llu", k);
	system("pause");
	return 0;
}