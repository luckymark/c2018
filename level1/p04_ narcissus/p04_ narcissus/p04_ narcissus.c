#include <stdio.h>
int Result(int num , int n)
{
    int a[n] ;
    for(int i = 0 ; i < n ; i++){
        int d = num % 10 ;
        a[i] = d ;
        num /= 10 ;
    }
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        int  origin = a[i] ;
        for(int j = 0 ; j < n - 1 ; j++){
            a[i] *= origin ;
        }
        sum += a[i] ;
    }
    return sum ;
}
int main(void)
{
    for(int i = 100 ; i < 1000 ; i++){
        if( i == Result(i , 3)){
            printf("%d\n" , i) ;
        }
    }
    return 0 ;
}
