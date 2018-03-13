#inc#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) 
{
	long long int n,i;
	printf("输入一个正整数：");
	scanf("%lld",&n);
	if(n==1)
	{
		printf("1不是素数");
		return 0;
	}
	
	if(n==2)
	{
		printf("2是素数");
		return 0;
	}
	
	for(i=2;i<sqrt(n)+1;i++)
	{
		if(n%i==0)
		{
			printf("%lld不是素数",n);
			return 0;
		}
	}
	
	printf("%lld是素数",n);
	return 0;
}
