#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
		long int num;
    	while(scanf("%d",&num)==1)
    	{
			if(num==1)
			printf("%ld��������\n",num);
			if(num==2)
			printf("%ld������\n",num);
    		if(num>2)	
		    {
		    	int i=2;
		    	for(;i<num;i++)
    			{
    		    	if(num%i==0)
    		    	{
    		    	    printf("%ld��������\n",num);
    		    	    break;
					}
				}
				if(i==num)
				printf("%ld������\n",num);
				}
		}
	return 0;
}
