# include <stdio.h>
# define UPPERLIMIT 250

int main(void)
{
	for(double i = 0; i < UPPERLIMIT; i++)
	{
		if((i / 12 + i / 6 + i / 7 + 5 + i / 2 + 4) == i)
		{
			printf("当儿子死时, 丢番图的年龄为%.0f\n", i - 4);
			break;
		}
	}
}
