#include<stdio.h>
void Hanoi(int n,char A,char B,char C)
{
	if(n==1){
		printf("����%d��Բ�̴�%c�ƶ���%c\n",n,A,C);
	}
	else{
		Hanoi(n-1,A,C,B);
		printf("����%d��Բ�̴�%c�ƶ���%c\n",n,A,C);
		Hanoi(n-1,B,A,C);
	}
}
int main()
{
	int i;
	scanf("%d",&i);
	char X='x';
	char Y='y';
	char Z='z';
	Hanoi(i,X,Y,Z);
	return 0;
}
