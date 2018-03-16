#include <stdio.h>
#include <stdbool.h>
int main(void){
	int i=1,j,k,l;
	bool jump=false;
	int prime[100]={2};
	for(j=2;j<101;j++)
	{
		for(k=0;k<i;k++)
		{
			if(j%prime[k]==0)
				break;							
		}
		if(k==i)
		{
			prime[i]=j;
			i++;
		}
	}
	for(j=4;j<101;j+=2)
	{
		for(k=0;k<i;k++)
		{
			for(l=k;l<i;l++)
			{
				if(prime[k]+prime[l]==j)
				{
					printf("%d=%d+%d\n",j,prime[k],prime[l]);
					jump=true;
					break;
				}
			}
			if(jump){
				jump=false;
				break;
			}
		}
	}
	return 0;
}
