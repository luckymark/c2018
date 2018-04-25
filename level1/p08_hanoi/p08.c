#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void move (int n, char a, char b, char c)
{ 
	if (n == 1) 
	{ 
		printf("%c-->%c\n",a,c);
	 } 
	else 
	{ 
		move (n-1,a,c,b); 
		printf("%c-->%c\n",a,c);
		move (n-1,b,a,c);
	 } 
} 

int main(int argc, char *argv[]) 
{
	int n;
	scanf("%d",&n);
	move(n,'A','B','C');
	return 0;
}
