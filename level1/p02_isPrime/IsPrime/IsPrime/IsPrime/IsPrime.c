#include<stdio.h>
#include<stdlib.h>
int main(void) {
	unsigned long long TextNumber;
	printf("现在你可以输入一个数字进行素数检查(输入数字应该为小于ULLONG_MAX的正整数)\n");
	while (scanf_s("%llu", &TextNumber)) {
		unsigned long long flag = 0;
		if (TextNumber <2) 
		{
			printf("%llu 既不是素数也不是合数\n", TextNumber);
			continue;
		}
		for (int i = 2; i*i <= TextNumber; i++)
			if (TextNumber%i == 0)
			{
				flag++;
				break;
			}
		printf("%llu是%s\n", TextNumber, flag ? "合数" : "素数");
	}
	printf("end!\n");
	system("pause");
	return 0;

}
