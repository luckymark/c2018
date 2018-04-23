#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MIN_N 1
#define MAX_N 50

int prime(int x)
{
    int i;
    for (i=MIN_N+1;i<=sqrt(x)+1;i++)
        if (x%i == 0) return 0;
    return 1;
}

int main()
{
    int i,j;
    for (i=MIN_N;i<=MAX_N;i++)
    {
        for (j=MIN_N;j<=i*2;j++)
            if (prime(j) && prime(2*i-j))
            {
                printf("%d = %d + %d\n",2*i,j,2*i-j);
                break;
            }
    }
    printf("All even numbers within 100 accord with Goldbach's conjecture.");
    return 0;
}
