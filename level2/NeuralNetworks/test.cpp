#include<bits/stdc++.h>
#include<unistd.h>
// 清除屏幕  
#define CLEAR() printf("\033[2J")  
  
// 上移光标  
#define MOVEUP(x) printf("\033[%dA", (x))  
  
// 下移光标  
#define MOVEDOWN(x) printf("\033[%dB", (x))  
  
// 左移光标  
#define MOVELEFT(y) printf("\033[%dD", (y))  
  
// 右移光标  
#define MOVERIGHT(y) printf("\033[%dC",(y))  
  
// 定位光标  
#define MOVETO(x,y) printf("\033[%d;%dH", (x), (y))  
  
// 光标复位  
#define RESET_CURSOR() printf("\033[H")  
  
// 隐藏光标  
#define HIDE_CURSOR() printf("\033[?25l")  
  
// 显示光标  
#define SHOW_CURSOR() printf("\033[?25h")  
  
//反显  
#define HIGHT_LIGHT() printf("\033[7m")  
#define UN_HIGHT_LIGHT() printf("\033[27m")
using namespace std; 
int main(){
   int x,y;
   cin>>x>>y;
   printf("\033[47;31mhello world\033[5m"); 
   while (1);
   return 0;
}
