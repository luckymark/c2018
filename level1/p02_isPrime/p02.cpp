#include<stdio.h>
#include<math.h>

int main(void)
{
	int a;
	scanf("%d",&a);
	int b=ceil(sqrt(a));    //ceil(n)：大于n的最小整数     floor(n): 小于等于n的最大整数 
	for (int i=2;i<=b;i++) 
	{
		if (a%i==0)
		{
			printf("%d不是素数",a);
			break; 
		}
		if (i==b)
		{
			printf("%d是素数",a);
			break; 
		}
	}
	return 0;
}
