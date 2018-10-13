#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

int main() {


	HANDLE handle_out;
	CONSOLE_SCREEN_BUFFER_INFO screen_info; 
	COORD pos = { 0, 0 };
	handle_out = GetStdHandle(STD_OUTPUT_HANDLE); 
	GetConsoleScreenBufferInfo(handle_out, &screen_info);


	int length = screen_info.dwSize.X - 1;
	int i;
	for (i = 0; i >= 0; ++i) {
		int a = i % length;
		int b = (i / length) % 2;
		int c = abs(length*b - a);
		int j;
		for (j = 0; j <= c; ++j) {
			printf(" ");
		}
		printf("S");
		Sleep(40);
		system("cls");
	}


	CloseHandle(handle_out);

}