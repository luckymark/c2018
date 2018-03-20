#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x ;
    for( x = 20 ; x < 100 ; x++){
        if( (x + 4 ) % 6 != 0  || (x+4) % 12 != 0) continue ;
        int child = (x + 4) / 6 ;
        int youth = (x + 4) / 12 + child ;
        int married = youth + (x+4) / 7 ;
        int born = married + 5 ;
        int sonold = x - born ;
        if( sonold == (x + 4 ) / 2 ) break ;
    }
    printf("%d" , x) ;
    return 0 ;
}

