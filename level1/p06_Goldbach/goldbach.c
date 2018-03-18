//Goldbach
# include <stdio.h>
# include <math.h>

# define LENGTH 25
# define LOWERLIMIT 2
# define UPPERLIMIT 100
# define LOWERLIMIT1 4
# define UPPERLIMIT1 100

int is_prime(int n);
int main(void)
{
	int primes[LENGTH] = {0};
	for(int i = LOWERLIMIT, j = 0; i <= UPPERLIMIT;  i++)
	{
		if(is_prime(i))
		{
			primes[j++] = i;
		}
	}
	for(int i = LOWERLIMIT1;i <= UPPERLIMIT; i += 2)
	{
		for(int j = 0; j < LENGTH; j++)
		{
			for(int k = 0; k < LENGTH; k++)
			{
				if(primes[j] + primes[k] == i)
				{
					printf("%d == %d + %d\n", i, primes[j], primes[k]);
				}
			}
		}
	}
	return 0;
}
int is_prime(int n)
{
	int sqrt_of_n = (int)sqrt(n);
	int i, if_is_prime;
	for(i = 2; i <= sqrt_of_n; i++)
	{
		if(n % i == 0) break;
	}
	if(i > sqrt_of_n)
	{
		if_is_prime = 1;
	}
	else
	{
		if_is_prime = 0;
	}
	return if_is_prime;
}
