#include<stdio.h>
#include<stdlib.h>
#define LENGTH 80
void delay(void);
void Printf(int);
int main(void)
{
	while (1)
	{
		for (int i = 0; i<LENGTH; i++)
			Printf(i);
		for (int i = LENGTH - 1; i>0; i--)
			Printf(i);
	}
	return 0;
}
void delay(void)
{
	for (int i = 0; i<10; i++)
		for (int i = 0; i<20; i++)
			for (int i = 0; i<30; i++)
				for (int i = 0; i<40; i++)
					for (int i = 0; i<50; i++)
						for (int i = 0; i<14; i++)
						    {}
}
void Printf(int i)
{
	for (int j = 0; j<i; j++)
		printf(" ");
	printf("a");
	delay();
	system("cls");
}

