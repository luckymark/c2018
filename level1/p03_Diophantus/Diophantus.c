#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int d_age;
	int s_age;
	for (int n = 1; n < 1000; n++)
	{
		if (n % 12 == 0)
			if (n % 7 == 0)
			{
				s_age = 5 + (n / 12) + (n / 7) + (n / 6);
				d_age = s_age * 2;
				break;
			}
	}
	printf("Diophantus is %d years old.", d_age);
	getchar();
	getchar();
}