#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
	int i=0,j=1,m=0,k;
	char words[20];
	scanf("%s",words);
	k=strlen(words);            // 取字符串长度 
	system("mode con cols=100");//设定控制台宽度 
	while(1)        
{
	printf("%s",words);
	system("cls");              //清屏 
    for(i=0;i<j;i++)
{
	printf(" ");	
}
    if(j==100-k)
    m=1;
    if(j==0)
    m=0;
    if(m==0)
	j++;
    else if(m==1)
    j--;
    Sleep(100);
}
    
    return 0;	 
}


