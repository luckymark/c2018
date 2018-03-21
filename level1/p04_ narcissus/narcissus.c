#include<Stdio.h>
#define MAX 1000
int main(void)
{
	int number;
	for(number=100;number<1000;number++)
	{
		int i=number%10;
		int j=(number/10)%10;
		int k=number/100;
		if(number==i*i*i+j*j*j+k*k*k)
			printf("%d\n",number);
	}
	return 0;

}
