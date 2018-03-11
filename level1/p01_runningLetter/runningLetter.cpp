//runningLetter
#include <stdio.h>
#include <windows.h>
int main () {
	system("mode con cols=120 lines=30");
	printf("b");
	for (int i=0; i<118; i++) {
		Sleep(20);
		printf("\b b");
	}
	for (int i=0; i<118; i++) {
		Sleep(20);
		printf("\b\bb \b");
	}
	return 1;
}
