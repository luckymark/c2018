#include <stdio.h>
#include <math.h>

int main()
{
	int num,i;
	
	printf("Please input your number:\n");
	scanf("%d",&num);
	
	if(num == 1)
	{
		printf("Your number is not a prime.\n");
	}
	else if(num == 2)
	{
		printf("Your number is a prime.\n");
	}
	else
	{
		for(i = 2; i <= sqrt(num); i++)	
		{
			if(num % i == 0)
				break;
		}
		if(i > sqrt(num))
			printf("Your number is a prime.\n");			
		else
			printf("Your number is not a prime.\n");
	}
		
	return 0;
 } 
