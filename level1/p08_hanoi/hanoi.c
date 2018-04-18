#include <stdio.h>

void move(int n,char a,char b,char c)
{
    if(n==1)
        printf("%c -> %c\n",a,c);
    else {
        move(n-1,a,c,b);
        printf("%c -> %c\n3",a,c);
        move(n-1,b,a,c);
    }
}

int main()
{
    int n;
    printf("please input the n:");
    scanf("%d",&n);
    move(n,'a','b','c');
    return 0;
}

