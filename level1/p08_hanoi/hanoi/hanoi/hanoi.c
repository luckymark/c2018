#include<stdio.h>
unsigned long long Sum(int);
int main(void) {
	int n;
	puts("你想要几层汉诺塔？");
	while (scanf_s("%d", &n)&&n>0)
		printf("%d层汉诺塔所需步骤和为%llu\n你可以继续输入或者输入其它类型字符结束\n", n, Sum(n));
	return 0;
}
unsigned long long Sum(int y) {
	if (y>1)
		return 2 * Sum(y - 1) + 1;
	else
		return 1;
}
