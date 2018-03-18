#include <stdio.h>
#include <stdlib.h>
#define maxn 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int prime[maxn];
	prime[0]=2;
	int count=1;
	for(int i=3;i<maxn+1;i++)
	{
		int j=2;
		for(;j<i;j++)
		{
			if(i%j==0)
			break;
		}
		if(j==i)
		{
			prime[count]=i;
			count=count+1;
		}
	}
	for(int t=4;t<=maxn+1;t=t+2)
	{
		for(int u=0;u<count;u++)
		{
			for(int p=0;p<count;p++)
			{
				if(t==(prime[u]+prime[p])) 
				{
					printf("%d=%d+%d\n",t,prime[u],prime[p]);
				}	
			}
		}
	}
	return 0;
}
