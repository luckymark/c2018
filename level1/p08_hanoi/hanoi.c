#include <stdio.h>

void move(int n,int x,int y,int z)
{
    if(n==1)
        printf("%c->%c\n",x,z);
    else
    {
        move(n-1,x,z,y);
        printf("%c->%c\n",x,z);
        move(n-1,y,x,z);
    }
}

int main(void)
{
    int n;
    printf("Please input the number of dishes:\n");
    scanf("%d",&n);
    move(n,'a','b','c');
    printf("Done!\n") ;
    getchar();
    getchar();
    return 0;
}
