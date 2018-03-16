#include <stdio.h>
#include <math.h>
#include <time.h>
int main(void){
	int prime[200]={2};
	int i=1,j,k,start,end;
	start=clock();
	printf("2 ");
	for(j=2;j<1001;j++)
	{
		for(k=0;k<i;k++)
		{
			if(j%prime[k]==0)
				break;							
		}
		if(k==i)
		{
			prime[i]=j;
			printf("%d ",j);
			i++;
		}
	}
	end=clock();
	printf("%d\n ",end-start);
	return 0;
	
}
