#include<stdio.h>
int main(void)
{
	int a,b,c,d;
	printf("水仙花数都有:"); 
    for(d=100;d<999;d++) 
    { 
        a=d/100;
        b=d/10%10;
        c=d%10;
        if(d==a*a*a+b*b*b+c*c*c) 
        { 
            printf("%5d",d); 
        } 
    } 
    printf("\n"); 
 } 
