#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <time.h> 

bool judge(int prime)
{
	int i;
	int j;
	for(i=2;i<=(int)sqrt(prime);i++)
	{
		j=prime%i;
		if(j==0)
		{
		return false;
		}
	}
	return true;
}

int main()
{
	int prime,clock1,clock2;
	clock1=clock();
	for(prime=2;prime<1001;prime++)
	{
		if(prime==2)
		{
			printf(" %d  ",prime);
		}
		
		else if(judge(prime))
		{
			printf(" %d ",prime); 
		} 
	}
	clock2=clock();
	printf("Ê±¼äÊÇ%dºÁÃë",clock2-clock1);
	return 0;
}

