#include <stdio.h> 

int n,i;
int main()
{
 	scanf("%d", &n);
	if(n==1)
	{
		printf("1 is not a prime number nor a composite number.\n");
		exit(0);
	}
	if(n<=0)
	{
		printf("Please input a positive integer!");
		scanf("%d", &n);
	}
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0) 
		{
			printf("%d is not a prime.\n", n);
			exit(0);
		}
	}
	printf("%d is a prime.\n", n);

 	return 0;
}



