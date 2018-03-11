# include <stdio.h>
# include <stdlib.h>
# include <Windows.h>
#include <conio.h>

# define WAITTIME 40

void print_space(int cnt);
int main(void)
{
	//获取屏幕宽度 
	HANDLE handle_out;                              //定义一个句柄  
    CONSOLE_SCREEN_BUFFER_INFO screen_info;         //定义窗口缓冲区信息结构体  
    COORD pos = {0, 0};                             //定义一个坐标结构体  
    handle_out = GetStdHandle(STD_OUTPUT_HANDLE);   //获得标准输出设备句柄  
    GetConsoleScreenBufferInfo(handle_out, &screen_info);   //获取窗口信息 
    const int LENGTH = screen_info.dwSize.X - 1;        //screen_info.dwSize.X(缓冲区宽度，也就是横坐标最大值加1)
    //功能实现 
	int cnt;
	int a, b, c;
	for(cnt = 0;; cnt++)
	{
		//主体逻辑部分, 实现循环 
		a = cnt % LENGTH;
		b = (cnt / LENGTH) % 2;
		c = abs(LENGTH * b - a);
		print_space(c);
		
		printf("R");
		Sleep(WAITTIME);
		system("cls");
	}
	CloseHandle(handle_out);    //关闭标准输出设备句柄
}
void print_space(int cnt)
{
	int temp;
	for(temp = 0; temp < cnt; temp++)
	{
		printf(" ");
	}
}
