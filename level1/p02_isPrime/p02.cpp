#include<stdio.h>
#include<math.h>

int main(void)
{
	int a;
	scanf("%d",&a);
	int b=ceil(sqrt(a));    //ceil(n)������n����С����     floor(n): С�ڵ���n��������� 
	for (int i=2;i<=b;i++) 
	{
		if (a%i==0)
		{
			printf("%d��������",a);
			break; 
		}
		if (i==b)
		{
			printf("%d������",a);
			break; 
		}
	}
	return 0;
}
