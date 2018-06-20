#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void jiami(char a[200])
{
	for(int i=0;i<200;i++)
	{
		if(a[i]<='W'&&a[i]>='A')
		{
		a[i]=a[i]+3;
		}
		else if(a[i]>='X'&&a[i]<='Z')
		{
		a[i]=a[i]-23;
		}
		if(a[i]<='w'&&a[i]>='a')
		{
		a[i]=a[i]+3;
		}
		else if(a[i]>='x'&&a[i]<='z')
		{
		a[i]=a[i]-23;
		}
	}
	printf("加密后是");
	puts(a);
}

void jiemi(char b[200])
{
	for(int i=0;i<200;i++)
	{
		if(b[i]<='Z'&&b[i]>='D')
		{
		b[i]=b[i]-3;	
		}
		else if(b[i]<='C'&&b[i]>='A')
		{
		b[i]=b[i]+23;
		}
		if(b[i]<='z'&&b[i]>='d')
		{
		b[i]=b[i]-3;
		}
		else if(b[i]<='c'&&b[i]>='a')
		{
		b[i]=b[i]+23;
		}
	}
	printf("解密后是");
	puts(b);
}

int main()
{
	char mima[200];
	gets(mima);
	jiami(mima);
	jiemi(mima);
	return 0; 
}






















