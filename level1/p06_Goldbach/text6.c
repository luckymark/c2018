#include<stdio.h>
int prime(int n)
{   
		for (int i = 2; i*i <= n; i++) //判断素数
			if (n%i == 0)return 0;
		return n > 1;
}
int main()
{
	int x, i;
	printf("请输入1~100范围的数:");
	scanf("%d", &x); //输入测试数
	for (i = 2; i <= x / 2; i++) //减少重复
		if (prime(i) && prime(x - i))
		{
			printf("%d=%d+%d\n", x, x - i, i);
			getchar();
			return 0;
			
		}
	
}