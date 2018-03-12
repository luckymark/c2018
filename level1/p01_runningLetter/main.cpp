#include <cstdio>	//仅仅适用于windows下控制台
#include "windows.h"

HANDLE hStdout = NULL;
_CONSOLE_SCREEN_BUFFER_INFO info;
char *Str = NULL;
int w = 0;

void genStr(int i) {
    for (int k = 0; k < i - 1; k++) {
        Str[k] = ' ';
    }
    Str[i - 1] = 'C';
    Str[i] = 0;
}

void DoFunnyThings() {
    int flag = 1, i = 1;
    
    while (true) {
        GetConsoleScreenBufferInfo(hStdout, &info);    //支持实时适应窗口大小
        if (w < info.dwMaximumWindowSize.X) {
            free(Str);
            Str = new char[info.dwMaximumWindowSize.X + 1];
        }
        w = info.dwMaximumWindowSize.X;

        system("cls");    //清屏并输出
        genStr(i);
        printf("%s", Str);
        
	i += flag;
	if (i == 1 || i == w){
		flag *= -1;
	}
        
        Sleep(20);
    }
}

int main() {
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    DoFunnyThings();
    return 0;
}