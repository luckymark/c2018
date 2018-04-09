#include <stdio.h>
#include <math.h>
#include <time.h>
#define N 10000 

int main(void)
{
    int prime[N+1]={0};
    int i,j;
    int time0=clock();
    for(i=2;i<=sqrt(N);i++)
    {
        if(prime[i]==0)
        {
            for(j=2*i;j<=N;j=j+i)
                prime[j]=1; 
        }
        else;
    }
    for(i=2;i<=N;i++)
    {
        if(prime[i]==0)
            printf("%d ",i); 
    } 
    int time1=clock();
    printf("\nFinished! Total time is %dms.\n",time1-time0);
    getchar();
    return 0; 
} 
