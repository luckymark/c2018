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
		int b=ceil(sqrt(a));    //ceil(n)������n����С����     floor(n): С�ڵ���n��������� 
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
