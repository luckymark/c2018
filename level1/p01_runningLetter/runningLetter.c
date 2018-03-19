#include<stdio.h>
#include <windows.h>
#define TIME 24
#define WIDE 80
#define TheChar 'A'


void run()
{
	int i,j;

	for (i=0;i<WIDE*2;i++)
	{
		if (i<=WIDE)
			for (j=0;j<i;j++)
				printf(" ");
		else
			for (j=WIDE;j>i-WIDE;j--)
				printf(" ");
		printf("%c",TheChar);
		Sleep(TIME);
		system("cls");
	}

}

int main()
{
    system("mode con cols=81 lines=50");
	run();
	return 0;
}
