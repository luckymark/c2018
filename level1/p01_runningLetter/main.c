#include <stdio.h>  
#include <stdlib.h>  
#include <windows.h>  
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
  int a,b;  
    a = 0;
	while(1){
		//�������� 	
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
		//��������
		while (a> 0)  //���ʹ�ô��ڵ��ڣ������ڿ�ͷ���������0�ո��H������ͣ��ʱ��䳤 
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
