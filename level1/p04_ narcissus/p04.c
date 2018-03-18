#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int a,b,c; 
	for(int i=1;;i++) 
	{
		if(i<100)continue;
		if(i>999) break;
	 	a=i/100;
	 	b=i/10%10;
	 	c=i%10;
	  	if(i==(a*a*a+b*b*b+c*c*c)) printf("%d\n",i);
	}
	return 0;
}
