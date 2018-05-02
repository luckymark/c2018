#include <stdio.h>
#include <stdlib.h>
int prime( int p )
{
	int i ;
	int ret = 1 ;
	for( i = 2 ; i < p ; i++ ){
			if( p % i == 0 ){
				ret = 0 ;
			}
	}
    return ret ;
}
int Goldbach( int n )
{
	int i = 3 ;
	int j = n - 3 ;
	int flag = 0 ;
	for( ; i <= j ; i++ , j-- )
		if( prime( i ) && prime( j )){
                flag = 1 ;
				break ;
        }
    return flag ;
}

int main()
{
    const int MAX = 10000 ;
    int flag = 0 ;
    for(int i = 6 ; i <=MAX ; i += 2){
        if(!Goldbach(i)){
            flag = 1 ;
            break ;
        }
    }
    if(flag){
        printf("wrong\n") ;
    }
    else{
        printf("in %d it is right\n" ,MAX) ;
    }
    return 0 ;
}
