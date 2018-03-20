#include <stdio.h>
#include <math.h>

int main()
{
    int n ;
    scanf("%d" ,&n) ;
    int num = (int)sqrt(n) ;
    int flag = 1 ;
    for(int i = 2 ; i <= num ; i++){
        if( n % i == 0 ){
            flag = 0 ;
            break ;
        }
    }
    if(flag && n!=1){
        printf("%d is a prime" , n) ;
    }
    else{
        printf("%d isn't a prime" , n) ;
    }
    return 0 ;
}
