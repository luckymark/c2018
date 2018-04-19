#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[]) 
{
	int a[200],i,m,judge=1;
	int Tstart=clock();
	a[0]=2;
	printf("2\n");
	a[1]=3;
	for(i=1;;)
	{
		for(m=0;m<i;m++)
		{
			if(a[i]%a[m]==0)
			{
				judge=0;
				break;
			}
		}
		if(judge==1)
		{
			printf("%d\n",a[i]);
			++i;
			a[i]=a[i-1];
		}
		if(a[i]==1000)
		{
			break;
		}
		a[i]++;
		judge=1;
	}
	int Tend=clock();
	printf("Total time:%dms",Tend-Tstart);
	return 0;
}
