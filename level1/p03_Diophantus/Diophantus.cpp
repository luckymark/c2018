#include<stdio.h>

int main()
{
	int x;
	for (x=1;x<200;x++)
	{
		if ((x/6.0+x/12.0+x/7.0+5+x/2.0+4)==(x/1.0))
		{
			printf("Diophantus was %d years old\n",x);
		}
		else continue;
	}
	return 0;
}
