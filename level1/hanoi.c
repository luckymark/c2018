#include <stdio.h>
void Move(int n,char a,char b);
void Hanoi(int n,char a,char b,char c)
{
    if (n==1)
    {
        Move(n,a,c);
    }
    else
    {
        Hanoi(n-1,a,c,b);
        Move(n,a,c);
        Hanoi(n-1,b,a,c);
    }
}
int x;
void Move(int n,char a,char b)
{
    x++;
    printf("The %d step: Move No.%d dish from %c post to %c post \n" ,x,n,a,b);
}
int main()
{
    int n;
    printf("Please input the number of floor:\n");
    scanf(" %d",&n);
    Hanoi(n, 'A', 'B', 'C');
    return 0;
}

