#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int a=0,b=0,c=0;
	int sum;
	for(n=100;n<1000;n++)
	{
		a=n/100;
		b=n/10-n/100*10;
		c=n/1-n/100*100-b*10;
		sum=a*a*a+b*b*b+c*c*c;
		if(sum==n)
		{
			printf("%d ",n);
		}
	}
	return 0;
}

