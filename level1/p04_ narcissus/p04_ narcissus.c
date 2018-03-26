#include <stdio.h>
#include <stdlib.h>
#define MIN_N 100
#define MAX_N 1000

int cube(int x)
{
    return(x*x*x);
}

int check(int number)
{
    int bit,decade,hundred;
    bit=number%10;
    decade=(number/10)%10;
    hundred=number/100;

    if (cube(bit)+cube(decade)+cube(hundred) == number)
    {
        printf("%d=%d^3+%d^3+%d^3\n",number,hundred,decade,bit);
        return 1;
    }

    return 0;
}

int main()
{
    int i,num=0;

    for (i=MIN_N;i<MAX_N;i++)
    {
        if ( check(i) )
            num++;
    }
    printf("\nThe total of narcissus number is %d.",num);

    return 0;
}
