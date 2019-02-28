#include <stdio.h>
#include <stdlib.h>
#include<time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int i=2;
	printf("%d\n",i);
	for(int i=3;i<1001;i++)
    	{
			int j=2;
    		for(;j<i;j++)
    		    {
					if(i%j==0)
    		    	break;
				}
			if(j==i)printf("%d\n",i);
		}
	printf("%dms\n",clock());
	return 0;
}
