#include<stdio.h>
#include<stdlib.h>
void Encrypt(char a[]);
void Decrypt(char b[]);
char str_ing[50];
int judge;
int main(void)
{
	printf("Input\n");
	scanf("%s",str_ing);
	printf("加密请输入1\n解密请输入2\n退出请输入其他键\n");
	scanf("%d",&judge);
	switch(judge)
	{
	case 1:
		Encrypt(str_ing);
		break;
	case 2:
		Decrypt(str_ing);
		break;
	default:
		exit(0);
	}
	return 0;
}
void Encrypt(char a[])
{
	int j=0;
	for(j=0;str_ing[j]!='\0';j++)
	{
		str_ing[j]-=1;
	}
	printf("密文为 %s",str_ing);
	return;
}
void Decrypt(char b[])
{
	int j=0;
	for(j=0;str_ing[j]!='\0';j++)
	{
		str_ing[j]+=1;
	}
	printf("解密内容为 %s",str_ing);
	return;
}
