#inc#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) 
{
	long long int n,i;
	printf("����һ����������");
	scanf("%lld",&n);
	if(n==1)
	{
		printf("1��������");
		return 0;
	}
	
	if(n==2)
	{
		printf("2������");
		return 0;
	}
	
	for(i=2;i<sqrt(n)+1;i++)
	{
		if(n%i==0)
		{
			printf("%lld��������",n);
			return 0;
		}
	}
	
	printf("%lld������",n);
	return 0;
}
