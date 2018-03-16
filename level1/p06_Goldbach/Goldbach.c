#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int make_primes(int *prime);

void main()
{
	int n_prime = 26;     //100内有25个质数和证明所需用到的1
	int prime[26];
	make_primes(prime);
	for (int n = 3; n <= 100; n++)
	{
		for (int n1 = 0; n1 < 26; n1++)
		{
			for (int n2 = 1; n2 < 26; n2++)
			{
				if (prime[n1] + prime[n2] == n)
				{
					printf("%d = %d + %d\n", n, prime[n1], prime[n2]);
				}
				else if (prime[n1] + prime[n2] > n)
				{
					break;
				}
			}
		}
	}
	getchar();
}

int make_primes(int *prime)
{
	prime[0] = 1;
	prime[1] = 2;
	prime[2] = 3;
	int n_p=3;
	for (int i = 2; i <= 100; i++)
	{
		for (int j = 2; j*j <= i; j++)
		{
			if (i%j == 0)
				break;
			else if ((j + 1)*(j + 1) > i && (j + 1)*(j + 1) != i)
			{
				prime[n_p] = i;
				n_p++;
				break;
			}
		}
	}
}