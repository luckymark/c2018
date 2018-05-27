#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#define boundary 50;

void setCursor(int x, int y)

{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hCon,pos);

}



void setConsole()

{

	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT rc;

	rc.Left = 0;

	rc.Top = 0;

	rc.Right = boundary;

	rc.Bottom = 29;

	SetConsoleWindowInfo(hCon, TRUE, &rc);

}



void run()

{

	setConsole();
	int x =0, y = 0;
	int test = 1;
	char value;
	scanf("%c", &value);
	setCursor(x, y);
	printf("%c", value);
	Sleep(70);
	while (1) {
		system("cls");
		if (test)/*换boundary蜜汁显示缺小括号*/
			setCursor(x++, y);
		else
			setCursor(--x, y);
		if (x >= 50)
			test = !test;
		else if(x<0)
			test = !test;
			
		printf("%c", value);
		Sleep(70);
	}
}



int main() {

	run();
	system("pause");
	return 0;

}