# include <stdio.h>
# include <math.h>

void is_prime(int n);
int main(void)
{
	long long int n;
	printf("请输入一个整数:");
	if(scanf("%lld", &n))
	{
		is_prime(n);
	}
	else
	{
		printf("Oops!你应该输入一个整数!");
	}
	return 0;
}
void is_prime(int n)
{
	int i;
	int sqrt_of_n = (int)sqrt(n);
	for(i = 2; i <= sqrt_of_n; i++)
	{
		if(n % i == 0) break;
	}
	if(i > sqrt_of_n)
	{
		printf("您所输入的%d是素数\n", n);
	}
	else
	{
		printf("您输入的不是素数\n");
	}
	
}
