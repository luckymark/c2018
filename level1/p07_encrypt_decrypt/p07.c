#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int c;
	while((c=getchar())!=EOF)
	{
		if(c>='A'&&c<='Z')
		c=c+2;
		if(c>='a'&&c<='z')
		c=c-3;
		else c=c+4;
		printf("%c",c);
	}
	return 0;
}
