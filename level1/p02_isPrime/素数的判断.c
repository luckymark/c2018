#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 

int main()
{   
    int prime;
    int i=2;
    int j;
	printf("������һ��������");
	scanf("%d",&prime);
	if(prime==1)
	printf("%d��������\n",prime);
	else 
	{
	for(i=2;i<(int)sqrt(prime);i++)
	{
	j=prime%i;
	if(j==0)
	{
		printf("%d��������\n",prime);
		break;
	}
	else
	{
		printf("%d������\n",prime);
		break;
	}
	}
    
	}

	system("pause");
	return 0; 
	 
}
