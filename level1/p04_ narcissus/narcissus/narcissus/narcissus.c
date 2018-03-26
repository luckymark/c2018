#include<stdio.h>
#include<stdlib.h>
int judge(int a, int b, int c)
{
	return a * a*a + b * b*b + c * c*c == 100 * a + 10 * b + c;
}
int main(void)
{
	printf("100-1000的所有水仙花数为： ");
	for (int TextNumber = 100; TextNumber < 1000; TextNumber++)
		if (judge(TextNumber / 100, TextNumber / 10 - TextNumber / 100 * 10, TextNumber - TextNumber / 10 * 10))
			printf("%d ", TextNumber);
	puts("\n");
	system("pause");
	return 0;
} 
