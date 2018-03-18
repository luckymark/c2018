#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int x,i,j,k;
	for (x = 100; x <= 999; x++)
	{
		k = x % 10;
		i = x / 100;
		j = (x - k - 100 * i) / 10;
		if (x == k * k*k + i * i*i + j * j*j)
		{
			printf("%d\n", x);
		}
	}
	system("pause");
	return 0;
}