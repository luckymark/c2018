#include <stdio.h>
#include <time.h>
#define N 1000
int divisor[]={2,3,5,7,9} ;
int fast(int num)
{
    int i,mod;
    for(i=0;i<5;i++)
    {
        mod=(num%divisor[i]);
        if(mod==0)
        return 1;
        else;
    }
    return 0;
}
int exhaust(int num) 
{
    int i=2,mod;
    do
    {
        mod=(num%i);
        i++;
    }while(mod!=0);
    if(i<=num)
    return 1;
    else
    return 0;
}
int main(void)
{  
    int time0=clock();
    int i,num;
    for(i=0;i<5;i++)
    {
        printf("%d ",divisor[i]);
    }
    for(num=2;num<=N;num++)
    {
        if(fast(num)==1)
        continue;
        else
        {
            if(exhaust(num)==1)
            continue;
            else
            printf("%d ",num);
        }
    }
    int time1=clock();
    printf("\nFinished! Total time is %dms.\n",time1-time0);
    getchar();
    return 0;
}
