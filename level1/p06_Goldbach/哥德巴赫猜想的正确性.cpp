#include <stdio.h>
#include <stdlib.h>
bool judge(int prime)
{
	int i;
	for(i=2;i<prime-1;i++)
	{
		if(prime%i==0)
		return false;
	}
	return true;
}


int main()
{
	int prime[50],even[50];
	int n=0;
	int m=0;
	int q=0;
	int j=0;
	for(int i=4;i<100;i++)
	{
		even[j]=i;
		i++;
		j++;
		
	}
	for(int i=2;i<100;i++)
	{
		if(i==2)
		{
			prime[n]=i;
			n++;
		}
		else if(judge(i))
		{
			prime[n]=i;
			n++;
		}
		
	}
	for(m=0;m<50;m++)
	{
		for(n=0;n<50;n++)
		{
			for(q=0;q<50;q++)
			{
			if(even[m]==prime[n]+prime[q])
			{
				printf("it is true\n");
				return 0;
			}
			}
	
		}
	}
	printf("it is false\n");
	return 0;
}
	
	
	
	
	

