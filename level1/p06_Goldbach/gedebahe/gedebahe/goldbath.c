#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int a[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91 };
	int i, j, k, x;
	//for (i = 4; i <= 100; i = i + 2)
	i = 4;
	while (i<=100)
	{
		for (j = 0; j<25; j++)
		{
			
			for (k = 0; k<25; k++)
			{
				if (a[j] + a[k] == i)
				{
					printf("%d+%d=%d 这是第%d个满足条件的偶数\n",a[j], a[k], i, i / 2 - 1);
					goto NEXT;
				}
				
			}
		}
		NEXT: i = i + 2;
	}
	system("pause");
	return 0;
}
