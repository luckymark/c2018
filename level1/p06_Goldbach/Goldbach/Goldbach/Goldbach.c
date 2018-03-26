//验证100以内哥德巴赫猜想成立
#include<stdio.h>
#include<stdlib.h>
int find(const int*,const int, int);
int main(void)
{
	const int Primes[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	const int length = sizeof(Primes)/sizeof(int);
	for (int i = 2; 2 * i <= 100; i++)
		printf("哥德巴赫猜想对偶数%d%s\n", 2 * i, find(Primes,length, 2 * i) ? "成立" : "不成立");
	system("pause");
	return 0;
}
int find(const int* Primes,const int length,int TextNumber)
{
	for (int i = 0; i < length; i++)
		if (Primes[i] < TextNumber)
			for (int j = 0; j <= i; j++)
				if (Primes[j] + Primes[i] == TextNumber)
					return 1;
	return 0;
}