#include <stdio.h>
#include <math.h>
int main(void)
{
    int num,i;
	scanf("%d",&num);
	if(num==1){
	
	printf("no");
	return 0;}
	if(num==2){
	
	printf("yes");
	return 0;}
	for(i=2;i<sqrt((double)num)+1;i++)
	{
		if(num%i==0)
		{
		printf("no");
	return 0;
	}
}
	printf("yes");
	return 0;
	
	
}
