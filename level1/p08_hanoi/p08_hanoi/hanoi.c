#include <stdio.h>
void hanoi(int n , char sour , char mid , char dest )
{
    if( n == 1 ){
        printf("%c -> %c\n" , sour , dest) ;
        return ;
    }
    hanoi(n-1 , sour , dest , mid ) ;
    printf("%c -> %c\n" , sour , dest) ;
    hanoi(n-1 , mid , sour , dest) ;
}
int main()
{
    int n ;
    scanf("%d" ,&n) ;
    hanoi(n , 'A' , 'B' , 'C') ;
    return 0 ;
}
