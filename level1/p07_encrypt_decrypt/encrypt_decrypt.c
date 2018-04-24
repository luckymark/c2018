#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void encrypt(char *words_1, int n);
void decrypt(char *words_1, int n);

void main()
{
	char words[10000];
	scanf("%s", &words);
	int l_words = strlen(words);
	encrypt(words, l_words);
	printf("%s", words);
	getchar();
	getchar();
	decrypt(words, l_words);
	printf("%s", words);
	getchar();
}

void encrypt(char *words_1, int n)
{
	for (int i = 0; i < n; i++)
	{
		words_1[i] = words_1[i] + 1;
	}
}

void decrypt(char *words_1, int n)
{
	for (int i = 0; i < n; i++)
	{
		words_1[i] = words_1[i] - 1;
	}
}