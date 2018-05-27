#include <stdio.h>
#include <time.h>

int judge(int num)
{
	int i,judge=0;
	for (i=2;i<(num/2+1);i++)
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
	int a=clock();
	int i,c;
	for (i=2;i<1000;i++)
	{
		if (judge(i)==0) 
		{
			continue;
		}
		else
		{
			printf("%-4d",i);
		}
	}
	int b=clock();
	printf ("\nRunning time:%d ms",c=b-a);
	return 0;
}
