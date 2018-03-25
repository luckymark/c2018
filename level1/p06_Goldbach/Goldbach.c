#include <stdio.h>

#define MAXN 100

int prime[MAXN+1],i,j,isPrime[MAXN+1];
int main()
{
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
	{
		isPrime[prime[i]]=1;
	}
	for(i=4;i<=MAXN;i+=2)
	{
		for(j=1;prime[j]<i && j<=prime[0];j++)
		{
			if(isPrime[i-prime[j]]==1)
			{
				printf("%d=%d+%d\n",i,prime[j],i-prime[j]);
				break;
			} 
		}
	}
	return 0;
}
