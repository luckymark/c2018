#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define SCREEN_WID 50
#define SLEEP_TIME 100

int main()
{
	system("mode con cols=50 lines=20");
	int length_word;
	char words[50];
	scanf("%s", &words);
	length_word = strlen(words);
	for (int space_left = 0; space_left <= SCREEN_WID - length_word; space_left++)
	{
		for (int n = 0; n < space_left; n++)
		{
			printf(" ");
		}
		printf("%s", words);
		Sleep(100);
		system("CLS");
	}
	for (int space_left = SCREEN_WID - length_word; space_left > 0; space_left--)
	{
		for (int n = space_left; n > 0; n--)
		{
			printf(" ");
		}
		printf("%s", words);
		Sleep(SLEEP_TIME);
		system("CLS");
	}
	return 0;
}