#include <stdio.h>
#include <stdlib.h>

void function(int panzishu,char a,char b,char c)
{
	if(panzishu==1)
	{
	printf("将%c===>%c",a,c);
	}
	else
	{
	function(panzishu-1,a,c,b);
	printf("将%c===>%c",a,c);
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
	printf("请输入汉诺塔的盘子数量:");
	scanf("%d",&panzishu);
	function(panzishu,a,b,c);
	return 0;
} 
