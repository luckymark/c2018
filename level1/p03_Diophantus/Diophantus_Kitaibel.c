#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) 
{
	float i;
	
	for(i=1.0;;i++)
	{
		if(i/6+i/12+i/7+5+i/2+4==i)
		{
			printf("%.0f",i-4);
			exit(0);
		}
	}
	
	return 0;
}
