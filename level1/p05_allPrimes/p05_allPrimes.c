#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_N 2
#define MAX_N 1000

int main()
{
    int time_start,time_end,a[MAX_N+5]={0};

    time_start=clock();

    int i,j,num=0;
    for (i=MIN_N;i<=MAX_N/2+1;i++)
    {
        if ( !a[i] )
            for (j=2;j<=MAX_N/i;j++)
                if (i*j<=MAX_N) a[i*j]=1;

    }
    for (int i=MIN_N;i<=MAX_N;i++)
        if ( !a[i] )
        {
            printf("%d  ",i);
            num++;
            if (num%10 == 0) printf("\n");
        }
    printf("\n\nThe total number of prime is %d.",num);

    time_end=clock();

    printf("\ntime use:%lf ms",(double)(time_end-time_start));
    return 0;
}
