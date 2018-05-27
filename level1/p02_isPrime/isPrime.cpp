#include <stdio.h>
#include <math.h>

int judge(int num)
{
	int i,judge=0;
	for (i=2;i<=sqrt(num);i++)
	{
		judge=num%i;
		if (judge==0)
		{
			break;
		}
		else continue;
	}
	if (num==2||num==3)
	{
		judge=1;
	}
	return judge;
}

int main()
{
	int num;
	printf("Please enter a nunber:\n");
	scanf("%d",&num);
	if (judge(num)==0) 
	{
		printf("%d is not a prime number.\n",num);
	}
	else
	{
		printf("%d is a prime number.\n",num);
	}
	return 0;
}
