#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 

int main()
{   
    int prime;
    int i=2;
    int j;
	printf("请输入一个正整数");
	scanf("%d",&prime);
	if(prime==1)
	printf("%d不是素数\n",prime);
	else 
	{
	for(i=2;i<(int)sqrt(prime);i++)
	{
	j=prime%i;
	if(j==0)
	{
		printf("%d不是素数\n",prime);
		break;
	}
	else
	{
		printf("%d是素数\n",prime);
		break;
	}
	}
    
	}

	system("pause");
	return 0; 
	 
}
