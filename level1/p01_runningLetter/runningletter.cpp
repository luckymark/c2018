#include <stdio.h>
#include <windows.h>
#include <conio.h>
int main(void){
	HANDLE handle_out;
	CONSOLE_SCREEN_BUFFER_INFO screen_info;         //定义窗口缓冲区信息结构体     
    int i;
    int length=0;		//单词的长度 
    bool shuttle=true; 		//用来表示现在是去还是回 
    int distance=1;		//表示移动的单词的位移 
    char entity[30];	//记录移动的单词 
    scanf("%s",entity);	//获得单词
	length=strlen(entity);	//获得单词长度 
    while(1){
    	system("cls");
    	for(i=0;i<distance;i++){      //随着distance的递增/递减，每次单词出现的位置更靠右/靠左，营造一种在移动的假象 
    		printf(" ");
		}
		puts(entity);
		Sleep(50);
		if(shuttle)		//如果是在去，distance增加，反之减少 
			distance++;
		else
		    distance--;
		handle_out = GetStdHandle(STD_OUTPUT_HANDLE);   //获得标准输出设备句柄  
    	GetConsoleScreenBufferInfo(handle_out, &screen_info);   //获取窗口信息
		if(distance==screen_info.dwSize.X-length)	//到达屏幕的边缘时改变状态 
			shuttle=false;
		if(distance==0)
			shuttle=true;    
	}
	return 0;
}
