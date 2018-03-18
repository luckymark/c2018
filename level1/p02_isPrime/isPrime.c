#include <stdio.h>
#include <stdlib.h>
int main(void)
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
	int i,mod,num;
	scanf("%d",&num);
	if(num<=0)
	{
	printf("error");
	exit(1);
	}
	else if(num==1)
    printf("no");
	else 
	{
	i=num;
    do
	{
		--i;
		mod=(num%i);
	}
	while(mod!=0);
    if(i>=2)
	printf("yes");
	else
	printf("no");
	}
	getchar();
	getchar();
	return 0;
}
