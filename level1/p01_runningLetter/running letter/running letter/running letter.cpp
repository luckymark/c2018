#include<stdio.h>
#include<stdlib.h>
#define WIDE 120
void delay(void);
int main(void) {
	int i;
	for (i = 1; i <= WIDE; i++)
	{
		int x = 1;
		while (x < i) {
			printf(" ");
			x++;
		}
		printf("0");
		delay();
		system("cls");
	}
	for (i = WIDE; i >= 1; i--)
	{
		int x = 1;
		while (x < i) {
			printf(" ");
			x++;
		}
		printf("0");
		delay();
		system("cls");
	}
	system("pause");
	return 0;
}
void delay(void)
{
	int p, q;
	for (p = 0; p < 10000; p++)
		for (q = 0; q < 2000; q++);
}