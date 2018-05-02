#include <stdio.h>
#include <time.h>
#include <math.h>
#define MAX 100100
int a[MAX] = {0} ;
int main()
{
    clock_t t1 = clock() ;
    int num = (int)sqrt(MAX) ;
    //int cnt = 0 ;
    for(int i = 2 ; i <= num ; i++){
        if( !a[i] ){
            for( int j = 2 ; j * i < MAX ; j++){
                a[j * i] = 1 ;
            }
        }
    }
    for(int i = 2 ; i < MAX ; i++){
        if(!a[i]){
            //cnt++ ;
            printf("%d " , i) ;
        }
    }
    //printf("\n cnt = %d" , cnt) ;
    printf("\ntime : %ld" , clock() - t1) ;
    return 0 ;
}
