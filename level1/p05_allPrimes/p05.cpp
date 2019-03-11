#include<stdio.h>
#include<math.h>
#include<time.h> 

int main(void)
{
	double start , stop;
	start=clock();
	double time=0;
	for (int a=2;a<=1000;a++)
	{
		int b=ceil(sqrt(a));    //ceil(n)：大于n的最小整数     floor(n): 小于等于n的最大整数 
		for (int i=2;i<=b;i++)
		{
			if (a%i==0) break;
			if (i==b)
			{
				printf("%d ",a);
				break; 
			}
		}
	}
	printf("\n");
	stop=clock();
    time=(stop-start)/CLOCKS_PER_SEC;
    printf("use time:%g seconds",time);
    return 0;
}
