#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int i=1;
	for(;i<150;i++)
		{
			if((i%6==0)&(i%12==0)&(i%7==0))
				{
					int sonlife,falife,marry,sonbirth;
					falife=i;
					sonlife=0.5*(i-4);
					marry=i/6+i/12+i/7;
					sonbirth=marry+5;
					if(sonlife=(falife-4-sonbirth))
					printf("When his son passed away, he was %d.\n",falife-4);
					
				}
		}
	return 0;
}
