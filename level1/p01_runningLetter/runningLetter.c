#include "stdio.h"
#include "windows.h"

#define maxRight 49

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void setCursor(int x, int y)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD setps;
    setps.X = x;
    setps.Y = y;
    SetConsoleCursorPosition(hCon, setps);
}

void setConsole()
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT rc;
    rc.Left = 0;
    rc.Top = 0;
    rc.Right = maxRight;
    rc.Bottom = 29;
    SetConsoleWindowInfo(hCon, TRUE, &rc);
}

void work()
{
    setConsole();
    boolean flag=1;
    int x=0,y=0;
    char chr;
    scanf("%c",&chr);
    setCursor(x,y);
    printf("%c",chr);
    Sleep(100);
    while(1)
    {
        system("cls");
        if(flag)
            setCursor(x++,y);
        else setCursor(x--,y);
        if(x>maxRight)
            flag=!flag;
        else if(x<0)
            flag=!flag;
        printf("%c",chr);
        Sleep(100);
    }
}


int main() {
    work();
    return 0;
}
