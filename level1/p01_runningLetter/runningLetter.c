#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define screen_l 50

int main()
{
	system("mode con cols=50 lines=20");
	int l_w;
	char words[36];
	scanf("%s", &words);
	l_w = strlen(words);
	for (int space_l = 0; space_l <= screen_l - l_w; space_l++)
	{
		for (int n = 0; n < space_l; n++)
		{
			printf(" ");
		}
		printf("%s", words);
		Sleep(100);
		system("CLS");
	}
	for (int space_l = screen_l - l_w; space_l > 0; space_l--)
	{
		for (int n = space_l; n > 0; n--)
		{
			printf(" ");
		}
		printf("%s", words);
		Sleep(100);
		system("CLS");
	}
	return 0;
}