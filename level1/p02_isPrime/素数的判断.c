#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{   
    int prime;
    int i;
    int j;
	printf("请输入一个正整数");
	scanf("%d",&prime);
	if(prime==1)
	{	
		printf("%d不是素数\n",prime);
	}
	else 
	{
	for(i=2;i<=prime-1;i++)
	{
	if(	prime%i==0)
	{
		printf("%d不是素数\n",prime);
		return 0; 
	}
    }
        printf("%d是素数\n",prime); 	
	}
	system("pause");
	return 0;
}
    
