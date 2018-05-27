#include<stdio.h>
#define K 2

void encrypt(char *p)
{
	for (int i=0;i<100;i++,p++)
	{
		if ((*p)=='\0')
		{break;}
		(*p)+=K;
		printf("%c",*p);
	}
}

void decrypt(char *p)
{
	for (int i=0;i<100;i++,p++)
	{
		if ((*p)=='\0')
		{break;}
		(*p)-=K;
		printf("%c",*p);
	}
}

int main()
{
	int n;
	void (*p1)(char *);
	char ch[100];
	printf("Please choose 1 or 2(1--encrypt, 2--decrypt) :\n");
	scanf("%d",&n);
	printf("Please enter your text:\n");
	scanf("%s",ch);
	(n==1) ? p1=encrypt :p1=decrypt;
	printf("Result:\n");
	(*p1)(ch);
	return 0;
}
