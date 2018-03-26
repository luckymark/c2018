#include <stdio.h>
#define N 100
int a[100],n=0,num;
void prime(void)
{  
    int i,j=0,mod,num;
    for(num=2;num<=N;num++)
    {
        i=2;
        do
        {
            mod=(num%i);
            i++;
        }while(mod!=0);
        if(i>=num)
        {
            //printf("%d ",num);
            n++;
            for(;;)
            {
                a[j]=num;
                j++;
                break;
            }
        }
        else;
    }
    /*for(j=0;j<n;j++)
    {
        printf("%d ",a[j]);
    } */
}

int verify(int num)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(num==a[i]+a[j])
            return 1;
            else;
        }
    }
    
}

int main(void)
{
    prime();
    int num;
    for(num=4;num<=100;num++,num++)
    {
        if(verify(num)==1)
        printf("%d verify successfully!\n",num);
    }
    printf("Done!");
    return 0;
}
