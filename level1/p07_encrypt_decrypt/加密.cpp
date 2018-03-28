#include<stdio.h>
#define SPACE ' '
int main()
{
	char ch;
	printf("这是一个转换密码的程序！\n");
	printf("请输入一个原始密码（由字符，数字，符号组成）："); 
	
	ch=getchar();
	while(ch!='\n')
	{
		if(ch==SPACE)
		putchar(ch);
		else 
		putchar(ch+1);
		ch=getchar();
	}
	putchar(ch);
	
	return 0;
}
