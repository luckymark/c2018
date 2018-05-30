#include <stdio.h>
#include <time.h>
#include <windows.h> 
 
int main()
{
    time_t t_start, t_end;
    t_start = time(NULL) ;
    int num,i;
    num=2; 
    while(num++<=1000){ 
	for(i=2;i<num;i++)
	{
		if(num%i==0)
		break;
	}
	if(num==i)
	printf("%8d",num);
	} 
    t_end = time(NULL) ;
    printf("time: %d ms\n", difftime(t_end,t_start)) ;
    return 0;
}
