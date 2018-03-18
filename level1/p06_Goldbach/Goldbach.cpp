#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int prime,num,i,j;
	int Even_num,max;
	int a[100];
	
	max = 0;
	
	for(prime = 2, i = 0; prime <= 100; prime++)	
	{
		for(j = 2; j <= sqrt(prime); j++)
		{
			if(prime % j == 0)
				break;
		}
		if(sqrt(prime) < j)
		{
			a[i] = prime;
			i++;
			max++;
		}
		else
			continue;
	}
	
	for(Even_num = 4; Even_num <= 100; Even_num = Even_num + 2)
	{
		for(i = 0; i < max; i++)
		{
			num = Even_num - a[i];
			for(j = 0; j < max; j++) 
			{
				if(a[j] == num)
					goto aa;
				else
					continue;
			}
		}

		aa: 
		if(i < max)
			printf("%d = %d + %d\n", Even_num, a[i], a[j]);
		else if(i >= max || j >= max)
			printf("Goldbach's conjecture is wrong.\n");
	}
		
	return 0;
 }
