#include <stdio.h>

int main()
{
	int num,i;
	
	printf("Please input your number:\n");
	scanf("%d",&num);
	
	for(i = 2; i <= num - 1; i++)	
	{
		if(num % i == 0)
			break;
	}
	if(i == num)
		printf("Your number is a prime.\n");			
	else
		printf("Your number is not a prime.\n");
		
	return 0;
 } 
