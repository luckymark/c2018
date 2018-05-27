#include <stdio.h>
#include <math.h>

int judge(int num)
{
	int i,judge=0;
	for (i=2;i<(sqrt(num)+1);i++)
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
	int n,i,j;
	printf("Please enter the range:\n");
	scanf("%d",&j);
	for (n=4;n<=j;n+=2)
	{
		for (i=2;i<n;i++)
		{
			if (((judge(i)!=0)) && ((judge(n-i))!=0))
			{
				printf("%d = %d+%d \n",n,i,(n-i));
				break;
			}
			else continue;
		}
	}
	return 0;
}

