#include<stdio.h>
int main(void)
{
	int number;
	int i=2;
	scanf("%d",&number);
	for(i=2;i<number;i++)
	{
		if(number%i==0)
		{
			printf("NotPrime");
			break;
		}
	}
	if(i==number)
	{
		printf("istPrime");
	}
	return 0;
}
