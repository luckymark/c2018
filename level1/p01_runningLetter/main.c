#include <stdio.h>  
#include <stdlib.h>  
#include <windows.h>  
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
  int a,b;  
    a = 0;
	while(1){
		//从左向右 	
	    while (a<=79)  
	    {  
	        system ("cls");  
	        b = 1;  
	        while (b<=a)  
	        {  
	            printf(" ");  
	            ++b;  
	        }  
	        printf("H");  
	        Sleep(100);  
	        ++a;  
	    } 
	    a--;
		//从右向左
		while (a> 0)  //如果使用大于等于，将会于开头处输出两个0空格的H，导致停顿时间变长 
	    {  
	        system ("cls"); 
			b = 1;
	        while (b<=a)  
	        {  
	            printf(" ");  
	            ++b;  
	        }  
	        printf("H");  
	        Sleep(100);  
	        --a;  
	    } 
	}
    system("pause");  
    return 0;  
}  
