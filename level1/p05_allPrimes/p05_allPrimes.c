#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_PRIME 2
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int number;
	clock_t t1,t2;
	t1 = clock();
	number = MIN_PRIME;
	while(number<=1000)
	{
		if(is_prime(number))
		{
			printf("%d\n",number);
		}
		number++;
	}
	t2 = clock();
	printf("%d\n",t2-t1);
	return 0;
}
int is_prime(number){
	int i;
	for (i=MIN_PRIME;i<number;i++)
	{
		if(number==MIN_PRIME)
		{
			return 1;
		}
		else if(number%i!=0)
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
	
}
