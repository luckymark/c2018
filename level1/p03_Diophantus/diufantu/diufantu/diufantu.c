#include <stdio.h>
#include<stdlib.h>
int main(void)
{
	float i;
	for (i = 1; i <= 100; i++)
	{
		if (i - i / 6 - i / 12 - i / 7 - 4 - 5 == i / 2)
			printf("儿子去世时丢番图为%d岁 \n", int(i - 4));
	}
	system("pause");
	return 0;

}
