#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *str,int len);
void decrypt(char *str,int len);

int main(int argc, char *argv[]) 
{
	int i,m;
	char str[100];
	printf("����������1������������2��");
	scanf("%d",&i);
	printf("�������������ַ�����");
	scanf("%s",str);
	m=strlen(str);
	if(i==1)
	{
		encrypt(str,m);
	}
	if(i==2)
	{
		decrypt(str,m);
	}
	
	return 0;
}

void encrypt(char *str,int len)
{
	int n;
	for(n=0;n<len;n++)
	{
		str[n] +=5;
	}
	puts(str);
}
void decrypt(char *str,int len)
{
	int n;
	for(n=0;n<len;n++)
	{
		str[n] -=5;
	}
	puts(str);
}
