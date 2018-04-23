#include <stdio.h>
#include <stdlib.h>

int tot=0;

void move(char a,char c)
{
    tot++;
    printf("Step %d: move from %c to %c\n",tot,a,c);
}

void hanoi(char a,char b,char c,int n)
{
    if (n == 1)
    {
        move(a,c);
    }
    else
    {
        hanoi(a,c,b,n-1);
        move(a,c);
        hanoi(b,a,c,n-1);
    }
}

int main()
{
    int the_number;
    printf("Please enter the size of hanoi:");
    scanf("%d",&the_number);
    printf("\nThe solution is:\n");

    hanoi('A','B','C',the_number);

    return 0;
}
