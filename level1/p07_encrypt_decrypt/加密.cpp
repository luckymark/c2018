#include<stdio.h>
#define SIZE 6
int main(void)
{
	int index;
	char num[6];
	
	printf("请输入六个字母作为你密码初始化的来源\n");

	scanf("%s",num);
	for(index=0;index<SIZE;index++)
	num[index]=num[index]+3;	

	printf("你的密码为");
    for(index=0;index<SIZE;index++)

	printf("%d",num[index]);
	return 0;
}
