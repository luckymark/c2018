#include <stdio.h>

void move(int n,int x,int y,int z)
{
    if(n==1)
        printf("%c->%c\n",x,z);
    else
    {
        move(n-1,x,y,z);
        printf("%c->%c\n",x,z);
        move(n-1,y,x,z);
    }
}

int main(void)
{
    int n;
    scanf("%d",&n);
    move(n,'a','b','c');
    getchar();
    getchar();
    return 0;
}
