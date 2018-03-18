# include <stdio.h>
# include <math.h>
# include <time.h>

# define LOWERLIMIT 2
# define UPPERLIMIT 1000

int is_prime(int i);
int main(void)
{
	//测量时间 
	clock_t start, finish;
	double  duration;
	start = clock(); 
	//打印素数 
	printf("2-1000内所有的素数为:\n");
	for(int i = LOWERLIMIT; i <= UPPERLIMIT; i++)
	{
		if(is_prime(i))
		{
			printf("%d\t", i);
		}
	}
	//测量时间 
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\n该程序运行总时间为: %f seconds\n", duration);
	return 0;
}

int is_prime(int i)
{
	int sqrt_of_i = (int)sqrt(i);
	int j, if_is_prime;
	for(j = 2; j <= sqrt_of_i; j++)
	{
		if(i % j == 0) break;
	}
	if(j > sqrt_of_i)
	{
		if_is_prime = 1;
	}
	else
	{
		if_is_prime = 0;
	}
	return if_is_prime;
}
