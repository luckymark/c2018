#Hanoi
	#include<stdio.h>
	void Hanoi(int n,char A,char B,char C)
	{
		if(n==1){
			printf("将第%d个圆盘从%c移动到%c\n",n,A,C);
		}
		else{
			Hanoi(n-1,A,C,B);
			printf("将第%d个圆盘从%c移动到%c\n",n,A,C);
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
                                         