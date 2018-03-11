//刷新界面版 
#include<stdio.h>
#include<windows.h>

int main(void)
{
	system("mode con cols=30 lines=20");
	for (int i=-29;i<=29;i++)
	{
		for (int j=29-abs(i);j>=1;j--) printf(" ");
		printf("*");
		Sleep(80);
		system("cls");
	}
	return 0;
}


/* //退格版（不完美）：差一格 
#include<stdio.h>
#include<windows.h>

int main(void)
{
	system("mode con cols=30 lines=20");
	printf("*");
	for (int i=1;i<=28;i++)
	{
		printf("\b *");
		Sleep(50);
	}
	for (int i=1;i<=29;i--)
	{
		printf("\b\b* ");
		Sleep(50);
		printf("\b");
	}
	return 0;
}
*/
