#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long n;
    scanf("%lld",&n);

    long long i;
    int flag=1;
    for (i=2;i<=sqrt(n)+1;i++)
    {
        if (n%i == 0) flag=0;
    }
    if ( flag )
        printf("%lld is a prime.",n);
    else
        printf("%lld is not a prime.",n);

    return 0;
}
