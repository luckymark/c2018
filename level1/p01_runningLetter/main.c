#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define WIDTH 100
int main(void)
{
    for(int i = 0 ; i < WIDTH * 2 ; i++){
        if( i < WIDTH ){
            for(int j = 0 ; j < i ; j++){
                putchar(' ') ;
            }
            putchar('A') ;
        }
        else{
            for(int j = WIDTH * 2 - i - 1; j > 0 ; j--){
                putchar(' ') ;
            }
            putchar('A') ;
        }
        Sleep(100) ;
        system("cls") ;
    }
    return 0 ;
}
