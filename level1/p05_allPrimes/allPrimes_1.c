#include <stdio.h>
#include <time.h>
#define N 1000
int main(void)
{  
    int time0=clock();
    int i,mod,num;
    for(num=2;num<=N;num++)
    {
        i=num;
        do
        {
            --i;
            mod=(num%i);
        }while(mod!=0);
        if(i==1)
        printf("%d ",num);
        else;
    }
    int time1=clock();
    printf("\nFinished! Total time is %dms.\n",time1-time0);
    getchar();
    return 0;
}
