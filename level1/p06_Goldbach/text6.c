#include<stdio.h>
int prime(int n)
{   
		for (int i = 2; i*i <= n; i++) //�ж�����
			if (n%i == 0)return 0;
		return n > 1;
}
int main()
{
	int x, i;
	printf("������1~100��Χ����:");
	scanf("%d", &x); //���������
	for (i = 2; i <= x / 2; i++) //�����ظ�
		if (prime(i) && prime(x - i))
		{
			printf("%d=%d+%d\n", x, x - i, i);
			getchar();
			return 0;
			
		}
	
}