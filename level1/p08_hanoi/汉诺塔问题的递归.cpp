#include <stdio.h>
#include <stdlib.h>

void function(int panzishu,char a,char b,char c)
{
	if(panzishu==1)
	{
	printf("��%c===>%c",a,c);
	}
	else
	{
	function(panzishu-1,a,c,b);
	printf("��%c===>%c",a,c);
	function(panzishu-1,b,a,c);
	}
}
int main()
{
	int panzishu;
	char a,b,c;
	a='a';
	b='b';
	c='c';
	printf("�����뺺ŵ������������:");
	scanf("%d",&panzishu);
	function(panzishu,a,b,c);
	return 0;
} 
