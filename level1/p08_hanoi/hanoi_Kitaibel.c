#include <stdio.h>

void hanoi(int n, char a,char b,char c);
void move(int n, char a, char b);

int count;

int main()
{
    int n=8;
    printf("�����뺺ŵ���Ĳ���:");
    scanf("%d",&n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}

void hanoi(int n, char a, char b, char c)
{
    if (n == 1)    //�ѵ�n��������A�Ƶ�C
    {
        move(n, a, c);
    }
    else    //��n-1��������A�Ƶ�B
    {
        hanoi(n - 1, a, c, b);
        move(n, a, c);
        hanoi(n - 1, b, a, c);
    }
}

void move(int n, char a, char b)
{
    count++;
    printf("��%d��:��%c�Ƶ�%c\n",count,a,b);
}
