#include <stdio.h>
#include <time.h>
#include <windows.h>
#define side_length 79
#define go printf("%s",str),Sleep(30),system("cls"),str[i]=' '
int main(int argc, char *argv[])
{
	system("mode con cols=80 lines=20");
	char str[100]={};
	int i=0;
	str[0]='a';
	while(1) 
	{
		for(i=0;i<side_length;i++)
		{
			go;
			str[i+1]='a';
		}
		for(i=side_length;i>0;i--)
		{
			go;
			str[i-1]='a';
		}
	} 
	system("pause");
	return 0;
}
