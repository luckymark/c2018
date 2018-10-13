#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define length 80

int main() {
	int i;
	for (i = 0; i >= 0; ++i) {
		int a = i % length;
		int b = (i / length)%2;
		int c = abs(length*b - a);
		int j;
		for (j = 0; j <= c; ++j) {
			printf(" ");
		}
		printf("S");
		Sleep(40);
		system("cls");
	}
}