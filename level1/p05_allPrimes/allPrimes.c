#include <stdio.h>
#include <time.h>

#define MAXN 1000
int prime[MAXN+1],i,j;
int main()
{
	double begin=clock();
	for(i=2;i<=MAXN;i++)
	{
		if(!prime[i]) prime[++prime[0]]=i;
		for(j=1;j<=prime[0] && prime[j]<=MAXN/i;j++)
		{
			prime[prime[j]*i]=1;
			if(i%prime[j]==0) break;
		}
	}
	for(i=1;i<=prime[0];i++)
		printf("%d\n", prime[i]);
	double end=clock();
	printf("%f\n", (end-begin)/CLOCKS_PER_SEC);
	return 0;
}
