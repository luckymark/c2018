#include <stdio.h>
#include <stdlib.h>
#define INTERVAL 4

int check(int x)
{
    int son_die=x-(x/6+x/12+x/7+5)-INTERVAL;

    if (son_die == x/2)
    {
        return 0;
    }
    return 1;
}

int main()
{
    int the_age=1;
    while ( check(the_age) )
    {
        the_age++;
    }
    printf("The age of diophantus when his son died is %d",the_age-INTERVAL);
    return 0;
}
