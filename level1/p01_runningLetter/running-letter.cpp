#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void print_1(int i)
{
	int j=0;
	while (j<i) {printf(" ");j++;}
}

void print_2(int i)
{
	print_1(i);
	printf("C\n");
	Sleep(70);
	system("cls");
}

int main()
{
	int i;
	system("mode con cols=101 lines=30  ");
	for (i=0;i<=100;i++) print_2(i);
	for (i=100;i>=0;i--) print_2(i);
	return 0;
}
