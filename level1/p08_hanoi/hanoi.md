### 功能要求：

1.汉诺塔：汉诺塔（又称河内塔）问题是源于印度一个古老传说的益智玩具。大梵天创造世界的时候做了三根金刚石柱子，在一根柱子上从下往上按照大小顺序摞着64片黄金圆盘。大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。并且规定，在小圆盘上不能放大圆盘，在三根柱子之间一次只能移动一个圆盘。
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
