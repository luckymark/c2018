# include <stdio.h>
# include <math.h>

# define LOWERLIMIT 100
# define UPPERLIMIT 1000

int main(void)
{
	printf("3位水仙花数为:\n");
	int number[3] = {0};
	for(int i = LOWERLIMIT; i < UPPERLIMIT; i++)
	{
		int j = 0, sum = 0;
		int temp = i;
		do
		{
			number[j++] = temp % 10;
			temp /= 10;
		} while(temp);
		for(j = 0; j < 3; j++)
		{
			sum += pow(number[j], 3);
		}
		if(sum == i)
		{
			printf("%d\t", i);
		}
	}
	printf("\n");
	return 0;
}
