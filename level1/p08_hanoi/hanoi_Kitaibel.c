#include <stdio.h>

void hanoi(int n, char a,char b,char c);
void move(int n, char a, char b);

int count;

int main()
{
    int n=8;
    printf("请输入汉诺塔的层数:");
    scanf("%d",&n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}

void hanoi(int n, char a, char b, char c)
{
    if (n == 1)    //把第n个盘子由A移到C
    {
        move(n, a, c);
    }
    else    //把n-1个盘子由A移到B
    {
        hanoi(n - 1, a, c, b);
        move(n, a, c);
        hanoi(n - 1, b, a, c);
    }
}

void move(int n, char a, char b)
{
    count++;
    printf("第%d步:从%c移到%c\n",count,a,b);
}
